#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1,MAXV=1e6+1;
int arr[MAXN];
int n,t;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int val){
            data=min(data,val);
            lazy=min(lazy,val);
        }
    }t[4*MAXV];
    void clear(){for(int i=0;i<4*MAXV;i++)t[i].data=0,t[i].lazy=0;}
    void prop(int ind){if(t[ind].lazy)t[ind<<1].apply(t[ind].lazy),t[ind<<1|1].apply(t[ind].lazy),t[ind].lazy=0;}
    void update(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        if(le!=ri)prop(ind);
        int mid=(le+ri)/2;
        update(ind<<1,le,mid,l,r,val),update(ind<<1|1,mid+1,ri,l,r,val);
        t[ind].data=min(t[ind<<1].data,t[ind<<1|1].data);
    }
    int query(int ind, int le, int ri, int loc){
        if(le==ri)return t[ind].data;
        prop(ind);
        int mid=(le+ri)/2;
        if(loc<=mid)return query(ind<<1,le,mid,loc);
        return query(ind<<1|1,mid+1,ri,loc);
    }
}tree;
vector<pair<int,pii>> influences;
int maxdiff;
void spread(){
    for(auto &&x:influences){
        x.second.first=max(1,x.second.first-maxdiff),x.second.second=min(MAXV,x.second.second+maxdiff);
        tree.update(1,1,MAXV,x.second.first,x.second.second,x.first);
    }
}
bool work(){
    influences=vector<pair<int,pii>>();
    tree.clear();
    for(int i=1;i<=n;i++){
        spread();
        influences.push_back({tree.query(1,1,MAXV,arr[i])-1,{arr[i],arr[i]}});
        tree.update(1,1,MAXV,arr[i],arr[i],influences.back().first);
    }
    return n+tree.t[1].data<=t;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int lo=0;
    int hi=MAXV;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(maxdiff=mid,work())hi=mid;
        else lo=mid+1;
    }
    printf("%d\n",lo);
    return 0;
}