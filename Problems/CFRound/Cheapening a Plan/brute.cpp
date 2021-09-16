#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e2+2;
ll arr[MN];
ll dp[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=0;j<=arr[i];j++){
            dp[i][j]=LLONG_MAX;
            for(int k=0;k<=arr[i-1];k++){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+arr[i]-j+abs(j-k));
            }
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<=arr[n];i++)ans=min(ans,i+dp[n][i]);
    printf("%lli\n",ans);
    return 0;
}