#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+1;
const ll MINV=-1e12;
ll arr[MAXN];
struct rangemax{
    ll left,best,right,entire;
    rangemax(){
        left=MINV,best=MINV,right=MINV,entire=MINV;
    }
};
rangemax rangemerge(const rangemax &l, const rangemax &r){
    rangemax te;
    te.entire=(l.entire==MINV||r.entire==MINV?MINV:l.entire+r.entire);
    te.left=max(l.left,(l.entire==MINV||r.left==MINV?MINV:l.entire+r.left));
    te.right=max(r.right,(r.entire==MINV||l.right==MINV?MINV:r.entire+l.right));
    te.best=max({l.best,r.best,te.entire,te.left,te.right,(l.right==MINV||r.left==MINV?MINV:l.right+r.left)});
    return te;
}
struct seg{
    struct node{
        int lazytype;
        ll lazytime;
        rangemax arr[2][2],norm;
        node(){
            lazytype=-1;
            lazytime=MINV;
        }
        void applylazyti(ll range, ll val){
            if(val!=MINV){
                norm.entire=val*range;
                norm.left=max(range*val,val);
                norm.right=max(range*val,val);
                norm.best=max(range*val,val);
                for(int i=0;i<2;i++){
                    arr[i][0].left=(arr[i][1].left==MINV?MINV:max(arr[i][1].left*val,val));
                    arr[i][0].right=(arr[i][1].right==MINV?MINV:max(arr[i][1].right*val,val));
                    arr[i][0].entire=(arr[i][1].entire==MINV?MINV:arr[i][1].entire*val);
                    arr[i][0].best=(arr[i][1].best==MINV?MINV:max(arr[i][1].best*val,val));
                }
                lazytime=val;
            }
        }
        void applylazyty(ll range, int val){
            if(val!=-1){
                arr[!val][0]=rangemax();
                arr[!val][1]=rangemax();
                arr[val][1].left=range,arr[val][1].best=range,arr[val][1].right=range,arr[val][1].entire=range;
                arr[val][0]=norm;
                lazytype=val;
            }
        }
    }t[2*MAXN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2,left=ind+1,right=ind+(mid-le+1)*2;
        t[left].applylazyti(mid-le+1,t[ind].lazytime),t[left].applylazyty(mid-le+1,t[ind].lazytype);
        t[right].applylazyti(ri-mid,t[ind].lazytime),t[right].applylazyty(ri-mid,t[ind].lazytype);
        t[ind].lazytime=MINV,t[ind].lazytype=-1;
    }
    void mergech(int ind, int left, int right){
        t[ind].norm=rangemerge(t[left].norm,t[right].norm);
        for(int i=0;i<2;i++)for(int j=0;j<2;j++)t[ind].arr[i][j]=rangemerge(t[left].arr[i][j],t[right].arr[i][j]);
    }
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].applylazyti(1,arr[le]);
            t[ind].applylazyty(1,0);
            return;
        }
        int mid=(le+ri)/2,left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        mergech(ind,left,right);
    }
    void update(int ind, int le, int ri, int l, int r, ll time, int type){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].applylazyti(ri-le+1,time),t[ind].applylazyty(ri-le+1,type);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2,left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,time,type),update(right,mid+1,ri,l,r,time,type);
        mergech(ind,left,right);
    }
    rangemax query(int ind, int le, int ri, int l, int r, int type){
        if(l>ri||r<le)return rangemax();
        if(le>=l&&ri<=r)return t[ind].arr[type][0];
        prop(ind,le,ri);
        int mid=(le+ri)/2,left=ind+1,right=ind+(mid-le+1)*2;
        return rangemerge(query(left,le,mid,l,r,type),query(right,mid+1,ri,l,r,type));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    tree.mt(0,1,n);
    int a,b,c,d;
    while(q--){
        cin>>a>>b>>c;
        if(a==1)tree.update(0,1,n,b,c,MINV,0);
        else if(a==2)tree.update(0,1,n,b,c,MINV,1);
        else if(a==3){
            cin>>d;
            tree.update(0,1,n,b,c,d,-1);
        }
        else if(a==4){
            ll ans=tree.query(0,1,n,b,c,0).best;
            if(ans==MINV)printf("breaks galore\n");
            else printf("%lli\n",ans);
        }
        else{
            ll ans=tree.query(0,1,n,b,c,1).best;
            if(ans==MINV)printf("breaks galore\n");
            else printf("%lli\n",ans);
        }
    }
    return 0;
}