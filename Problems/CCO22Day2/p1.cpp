#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=4001;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll dp[MN][MN];
ll fact[MN];
ll inv[MN];
int drop[MN];
int needfilled[MN];
int need[MN];
vector<int> adj[MN];
ll choose(ll a, ll b){
    return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int dfs(int loc){
    int needed=1-drop[loc];
    for(auto x:adj[loc]){
        int a=dfs(x);
        if(a==INT_MAX)return INT_MAX;
        needed+=a;
    }
    if(needed<0)return INT_MAX;
    need[loc]=needed;
    if(sz(adj[loc])==0){
        if(drop[loc]==0){
            dp[loc][0]=1;
            dp[loc][1]=1;
        }
        else if(drop[loc]==1){
            dp[loc][0]=1;
        }
    }
    else if(sz(adj[loc])==1){
        int a = adj[loc][0];
        for (int i = 0; i <=need[a]; i++) {
            if (i == need[a]) {
                int fromup = i + 1 - drop[loc];
                if (fromup < 0)continue;
                dp[loc][fromup] = (dp[loc][fromup] + dp[a][i] * choose(i + 1, i) % mod) % mod;
            }
            int fromup = i - drop[loc];
            if (fromup < 0)continue;
            dp[loc][fromup] = (dp[loc][fromup] + dp[a][i]) % mod;
        }
    }
    else {
        int a = adj[loc][0], b = adj[loc][1];
        for (int i = 0; i <= need[a]; i++) {
            for (int j = 0; j <= need[b]; j++) {
                if(i==need[a]&&j==need[b]){
                    int fromup=i+j+1-drop[loc];
                    if(fromup<0)continue;
                    dp[loc][fromup]=(dp[loc][fromup]+dp[a][i]*dp[b][j]%mod*choose(i+j+1,i)%mod*choose(j+1,1)%mod)%mod;
                }
                int fromup=i+j-drop[loc];
                if(fromup<0)continue;
                dp[loc][fromup]=(dp[loc][fromup]+dp[a][i]*dp[b][j]%mod*choose(i+j,i)%mod)%mod;
            }
        }
    }
    return needed;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,a;
    cin>>n>>k;
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*ll(i);
        inv[i]=fp(fact[i],mod-2);
    }
    for(int i=1;i<=k;i++){
        cin>>a;
        drop[a]++;
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a!=0)adj[i].push_back(a);
        cin>>a;
        if(a!=0)adj[i].push_back(a);
    }
    if(dfs(1)==INT_MAX)printf("0\n");
    printf("%lli\n",dp[1][0]);
    return 0;
}