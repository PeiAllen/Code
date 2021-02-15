#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll bit[MN];
int n,q;
ll s,t;
void update(int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
ll calc(ll last, ll cur){
    return (last-cur)*(last<=cur?s:t);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q>>s>>t;
    ll val=0;
    ll a,last=0;
    cin>>a;
    for(int i=1;i<=n;i++){
        cin>>a;
        val+=calc(last,a);
        update(i,a),update(i+1,-a);
        last=a;
    }
    int l,r;
    while(q--){
        cin>>l>>r>>a;
        val-=calc(query(l-1),query(l));
        if(r+1<=n)val-=calc(query(r),query(r+1));
        update(l,a),update(r+1,-a);
        val+=calc(query(l-1),query(l));
        if(r+1<=n)val+=calc(query(r),query(r+1));
        printf("%lli\n",val);
    }
    return 0;
}