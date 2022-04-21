#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=101,MM=1001;
int arr[MN];
ll dp[MN][MM];
ll solve(int n){
    dp[0][0]=1;
    for(int j=1;j<MM;j++)dp[0][j]=dp[0][j-1];
    for(int i=1;i<=n;i++){
        for(int j=0;j<MM;j++){//j=arr[i]-prevj
            dp[i][j]=(arr[i]-j>=0?dp[i-1][arr[i]-j]:0);
        }
        for(int j=1;j<MM;j++)dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
    }
    return dp[n][0];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n%2==0){
        printf("%lli\n",solve(n));
    }
    else{
        ll ans=solve(n);
        while(1) {
            bool bad=false;
            for (int i = 1; i <= n; i++){
                if(--arr[i]<0)bad=true;
            }
            if(bad)break;
            ans = (ans + solve(n)) % mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}