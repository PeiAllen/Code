#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int mod=1e4+7;
const ll amod=1e9+7;
ll dp[2][mod];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    int cur=1;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        int num=a[i]-'0';
        for(int j=0;j<mod;j++)dp[cur][j]=dp[!cur][j];
        for(int j=0;j<mod;j++)dp[cur][(j*10+num)%mod]=(dp[cur][(j*10+num)%mod]+dp[!cur][j])%amod;
        cur=!cur;
    }
    printf("%lli\n",dp[!cur][k]);
    return 0;
}