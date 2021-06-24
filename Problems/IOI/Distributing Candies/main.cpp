#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+3;
int n,q;
struct seg{
    struct node{
        ll mi,ma,lazy;
        node(){
            mi=0,ma=0,lazy=0;
        }
        void apply(ll v){
            lazy+=v;
            mi+=v;
            ma+=v;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy);
        t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].mi=min(t[left].mi,t[right].mi);
        t[ind].ma=max(t[left].ma,t[right].ma);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return LLONG_MAX;
        if(le>=l&&ri<=r)return t[ind].mi;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
    ll walk(int ind, int le, int ri, ll c, ll mi, ll ma){
        if(le==ri){
            if(t[ind].mi<mi){
                return query(0,0,q+1,q+1,q+1)-(ma-c);
            }
            else{
                return query(0,0,q+1,q+1,q+1)-mi;
            }
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(max(t[right].ma,ma)-min(t[right].mi,mi)>=c)return walk(right,mid+1,ri,c,mi,ma);
        return walk(left,le,mid,c,min(mi,t[right].mi),max(ma,t[right].ma));
    }
}tree;
vector<pair<int,ll>> updates[MN];
vector<int> distribute_candies(vector<int> c, vector<int> l, vector<int> r, vector<int> v){
    n=sz(c),q=sz(l);
    tree.update(0,0,q+1,0,q+1,2e9);
    tree.update(0,0,q+1,1,q+1,-2e9);
    for(int i=0;i<q;i++){
        updates[l[i]].push_back({i+2,v[i]});
        if(r[i]+1<n)updates[r[i]+1].push_back({i+2,-v[i]});
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        for(auto x:updates[i])tree.update(0,0,q+1,x.first,q+1,x.second);
        ans[i]=tree.walk(0,0,q+1,c[i],LLONG_MAX,LLONG_MIN);
    }
    return ans;
}


//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    vector<int> ans=distribute_candies({10, 15, 13}, {0, 0}, {2, 1}, {20, -11});
//    for(auto x:ans)printf("%d ",x);
//    return 0;
//}