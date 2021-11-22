#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
const ll MV=2e9;
ll m;
ll arr[MN];
ll phi(ll a){
    ll tot=a;
    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            tot-=tot/i;
            while(a%i==0)a/=i;
        }
    }
    if(a>1)tot-=tot/a;
    return tot;
}
ll fpcap(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i){
            if(ans*a>MV)ans=MV;
            else ans*=a;
        }
        if(a*a>MV)a=MV;
        else a*=a;
    }
    return ans;
}
ll fp(ll a, ll b, ll mod){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>m;
    vector<ll> mods;
    mods.push_back(m);
    for(int i=1;i<n;i++){
        ll ne=phi(mods.back());
        if(ne==1)break;
        mods.push_back(ne);
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll prev=1;
    if(sz(mods)==n&&mods.back()==2)prev=0;
    ll val=1;
    for(int i=n-1;i>=0;i--){
        if(i>=sz(mods))prev=0;
        else{
           if(val>=phi(mods[i])){
               prev=fp(arr[i],prev+phi(mods[i]),mods[i]);
           }
           else{
               prev=fp(arr[i],prev,mods[i]);
           }
        }
        val=fpcap(arr[i],val);
    }
    printf("%lli\n",prev);
    return 0;
}