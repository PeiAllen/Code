#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MM=1e9+20;
struct seg{//range set, point query, cnt query
    struct node{
        int data[10],lazy,l,r;
        node(){
            l=-1,r=-1;
            lazy=-1;
            for(int i=0;i<10;i++)data[i]=0;
        }
        void apply(int v, int range){
            if(v==-1)return;
            lazy=v;
            for(int i=0;i<10;i++)data[i]=0;
            data[lazy]=range;
        }
    };
    vector<node> t;
    seg(){
        t={node()};
    }
    int nn(int range){
        t.push_back(node());
        t.back().data[0]=range;
        return sz(t)-1;
    }
    void rl(int ind, int le, int ri){
        if(t[ind].lazy==-1)return;
        int mid=(le+ri)/2;
        if(t[ind].l==-1){int te=nn(mid-le+1);t[ind].l=te;}
        if(t[ind].r==-1){int te=nn(ri-mid);t[ind].r=te;}
        t[t[ind].l].apply(t[ind].lazy,mid-le+1);
        t[t[ind].r].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=-1;
    }
    int update(int ind, int le, int ri, int l, int r, int v){
        if(l>r||l>ri||r<le)return ind;
        if(ind==-1&&v==0)return ind;
        if(ind==-1)ind=nn(ri-le+1);
        if(le>=l&&ri<=r){
            t[ind].apply(v,ri-le+1);
            return ind;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        {int te=update(t[ind].l,le,mid,l,r,v);t[ind].l=te;}
        {int te=update(t[ind].r,mid+1,ri,l,r,v);t[ind].r=te;}
        for(int i=0;i<10;i++)t[ind].data[i]=(t[ind].l==-1?(i==0?mid-le+1:0):t[t[ind].l].data[i])+(t[ind].r==-1?(i==0?ri-mid:0):t[t[ind].r].data[i]);
        return ind;
    }
    int query(int ind, int le, int ri, int l, int r, int val){
        if(l>r||l>ri||r<le)return 0;
        if(ind==-1||t[ind].lazy!=-1){
            if(val==(ind==-1?0:t[ind].lazy))return min(ri,r)-max(le,l)+1;
            return 0;
        }
        if(le>=l&&ri<=r)return t[ind].data[val];
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        return query(t[ind].l,le,mid,l,r,val)+query(t[ind].r,mid+1,ri,l,r,val);
    }
    int find(int ind, int le, int ri, int l, int r, int v){
        if(l>r||l>ri||r<le)return -1;
        if(ind==-1||t[ind].lazy!=-1){
            if(v==(ind==-1?0:t[ind].lazy))return -1;
            return max(l,le);
        }
        if(le>=l&&ri<=r){
            if(t[ind].data[v]==ri-le+1)return -1;
            while(le!=ri){
                if(ind==-1||t[ind].lazy!=-1){
                    ri=le;
                    break;
                }
                rl(ind,le,ri);
                int mid=(le+ri)/2;
                if((t[ind].l==-1?(v==0?mid-le+1:0):t[t[ind].l].data[v])==mid-le+1){
                    ind=t[ind].r;
                    le=mid+1;
                }
                else{
                    ind=t[ind].l;
                    ri=mid;
                }
            }
            return le;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int te=find(t[ind].l,le,mid,l,r,v);
        if(te!=-1)return te;
        return find(t[ind].r,mid+1,ri,l,r,v);
    }
    int find2(int ind, int le, int ri){
        if(ind==-1||t[ind].lazy==0)return le-1;
        if(t[ind].lazy!=-1){
            return ri;
        }
        if(le==ri){
            if(t[ind].data[0]==1)return le-1;
            return le;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        if((t[ind].r==-1?ri-mid:t[t[ind].r].data[0])==ri-mid){
            return find2(t[ind].l,le,mid);
        }
        return find2(t[ind].r,mid+1,ri);
    }
    int getval(int ind, int le, int ri, int loc){
        if(ind==-1||t[ind].lazy!=-1){
            return (ind==-1?0:t[ind].lazy);
        }
        if(le==ri){
            for(int i=0;i<10;i++){
                if(t[ind].data[i]==1)return i;
            }
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        if(loc<=mid)return getval(t[ind].l,le,mid,loc);
        return getval(t[ind].r,mid+1,ri,loc);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    tree.t[0].data[0]=MM;
    char type;
    int a,b;
    while(n--){
        cin>>type>>a;
        if(type=='A'){
            cin>>b;
            int val=tree.getval(0,0,MM-1,b);
            if(val+a<10){
                tree.update(0,0,MM-1,b,b,val+a);
            }
            else{
                tree.update(0,0,MM-1,b,b,(val+a)%10);
                int firstgood=tree.find(0,0,MM-1,b+1,MM-1,9);
                tree.update(0,0,MM-1,b+1,firstgood-1,0);
                tree.update(0,0,MM-1,firstgood,firstgood,tree.getval(0,0,MM-1,firstgood)+1);
            }
        }
        else if(type=='S'){
            cin>>b;
            int val=tree.getval(0,0,MM-1,b);
            if(val-a>=0){
                tree.update(0,0,MM-1,b,b,val-a);
            }
            else{
                tree.update(0,0,MM-1,b,b,val+10-a);
                int firstgood=tree.find(0,0,MM-1,b+1,MM-1,0);
                tree.update(0,0,MM-1,b+1,firstgood-1,9);
                tree.update(0,0,MM-1,firstgood,firstgood,tree.getval(0,0,MM-1,firstgood)-1);
            }
        }
        else{
            int am=tree.query(0,0,MM-1,0,MM-1,a);
            if(a==0) {
                int lastdigit = tree.find2(0, 0, MM - 1);
                if (lastdigit == -1) {
                    am = 1;
                } else {
                    am -= (MM - 1 - lastdigit);
                }
            }
            printf("%d\n",am);
        }
    }
    return 0;
}