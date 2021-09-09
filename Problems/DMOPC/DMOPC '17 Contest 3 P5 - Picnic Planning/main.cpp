#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
string arr[MN];
ll dp[MN][MN];
ll dp2[MN][MN];
vector<int> locs[MN];
vector<int> toremove[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j]=dp[i][j-1]+i*j%mod*((fp(l,l)+fp(j,j))%mod)%mod;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='X'){
                locs[j+1].push_back(i);
            }
        }
    }
    ll ans=0;
    for(int j=1;j<=m;j++)reverse(locs[j].begin(),locs[j].end());
    for(int i=1;i<=n;i++){
        ll cur=0;
        for(int j=1;j<=m;j++){
            if(sz(locs[j])){
                toremove[j]
            }
        }
        for(int j=i;j<=n;j++){

            ans+=cur;
        }
        for(int j=i;j<=n;j++)toremove[i]=vector<int>();
        for(int j=1;j<=m;j++){

        }
    }
    return 0;
}