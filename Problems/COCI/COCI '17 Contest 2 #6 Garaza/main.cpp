#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int ans[MN],arr[MN];
struct gcdseg{
    int t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=arr[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=__gcd(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int loc){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind]=arr[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind]=__gcd(t[left],t[right]);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return __gcd(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
    int walkright(int ind, int le, int ri, int st, int gc){
        if(ri<st)return gc;
        if(le>=st){
            if(__gcd(t[ind],gc)>1)return __gcd(t[ind],gc);
            while(le!=ri){
                int mid=(le+ri)/2;
                int left=ind+1,right=ind+(mid-le+1)*2;
                if(__gcd(t[left],gc)==1){
                    ind=left,ri=mid;
                }
                else{
                    gc=__gcd(t[left],gc);
                    ind=right,le=mid+1;
                }
            }
            return -(le-1);
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        int te=walkright(left,le,mid,st,gc);
        if(te<=0)return te;
        gc=__gcd(gc,te);
        return walkright(right,mid+1,ri,st,gc);
    }
    int walkleft(int ind, int le, int ri, int en, int gc){
        if(le>en)return -1;
        if(ri<=en){
            if(__gcd(t[ind],gc)==gc)return -1;
            while(le!=ri){
                int mid=(le+ri)/2;
                int left=ind+1,right=ind+(mid-le+1)*2;
                if(__gcd(t[right],gc)<gc)ind=right,le=mid+1;
                else ind=left,ri=mid;
            }
            return le;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        int te=walkleft(right,mid+1,ri,en,gc);
        if(te>=0)return te;
        return walkleft(left,le,mid,en,gc);
    }
}gcdtree;
struct ansseg{
    struct node{
        int data,lazy;
        ll sum;
        node(){
            data=0,sum=0,lazy=-1;
        }
        void apply(int val, int le, int ri){
            if(val==-1)return;
            data=val,lazy=val;
            sum=ll(val)*(ri-le+1);
        }
    }t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].data=t[ind].sum=ans[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].data=t[right].data;
        t[ind].sum=t[left].sum+t[right].sum;
    }
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,le,mid),t[right].apply(t[ind].lazy,mid+1,ri);
        t[ind].lazy=-1;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val,le,ri);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=t[right].data;
        t[ind].sum=t[left].sum+t[right].sum;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].sum;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
    int walk(int ind, int le, int ri, int val){//first val that has >=val
        if(le==ri){
            if(t[ind].data>=val)return le;
            return le+1;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[left].data>=val)return walk(left,le,mid,val);
        return walk(right,mid+1,ri,val);
    }
}anstree;
ll getsum(ll a, ll b){
    if(b<a)return 0;
    return b*(b+1)/2-a*(a-1)/2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b,c;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    gcdtree.mt(0,1,n);
    for(int i=1;i<=n;i++){
        int end=gcdtree.walkright(0,1,n,i,arr[i]);
        if(end>0)end=n;
        else end=-end;
        ans[i]=end;
    }
    anstree.mt(0,1,n);
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            arr[b]=c;
            gcdtree.update(0,1,n,b);
            int cur=b;
            while(cur>0&&gcdtree.query(0,1,n,cur,b)>1){
                int next=gcdtree.walkleft(0,1,n,cur,gcdtree.query(0,1,n,cur,b));
                if(next<0)next=0;
                int end=gcdtree.walkright(0,1,n,cur,arr[cur]);
                if(end>0)end=n;
                else end=-end;
                anstree.update(0,1,n,next+1,cur,end);
                cur=next;
            }
            if(cur==b){
                anstree.update(0,1,n,cur,cur,cur);
                int left=anstree.walk(0,1,n,cur);
                anstree.update(0,1,n,left,cur-1,cur-1);
                int end=gcdtree.walkright(0,1,n,cur,arr[cur]);
                if(end>0)end=n;
                else end=-end;
                anstree.update(0,1,n,cur,cur,end);
                continue;
            }
            if(cur==0)continue;
            int left=anstree.walk(0,1,n,b);
            anstree.update(0,1,n,left,cur,b-1);
        }
        else{
            int stbad=max(b,anstree.walk(0,1,n,c));
            printf("%lli\n",anstree.query(0,1,n,b,stbad-1)+getsum(1,c-stbad+1)-getsum(b-1,stbad-2));
        }
    }
    return 0;
}