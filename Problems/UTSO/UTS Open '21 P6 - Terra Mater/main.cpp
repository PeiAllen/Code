#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll height[MN];
int n,k;
int bit[MN];
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]=max(bit[loc],val);
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans=max(ans,bit[loc]);
    return ans;
}
bool work(ll v){
    for(int i=1;i<=n;i++)bit[i]=0;
    update(1,0);
    vector<pll> points;
    vector<ll> ycoords;
    for(int i=1;i<=n;i++)points.push_back({height[i]-i*v,height[i]+i*v}),ycoords.push_back(height[i]+i*v);
    sort(ycoords.begin(),ycoords.end()),ycoords.erase(unique(ycoords.begin(),ycoords.end()),ycoords.end());
    sort(points.begin(),points.end(),[&](const pll &lhs, const pll &rhs){
         if(lhs.first==rhs.first)return lhs.second<rhs.second;
         return lhs.first>rhs.first;
    });
    for(auto x:points){
        int yc=lower_bound(ycoords.begin(),ycoords.end(),x.second)-ycoords.begin()+1;
        int val=query(yc);
        if(val+1>=n-k)return true;
        update(yc,val+1);
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>height[i];
        ll lo=0,hi=1e9;
        while(lo!=hi){
            ll mid=(lo+hi)/2;
            if(work(mid))hi=mid;
            else lo=mid+1;
        }
        printf("%lli\n",lo);
    }
    return 0;
}