#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
const ll MINV=-1e15;
ll arr[MAXN];
ll dp[MAXN][31];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        k=min(n,k);
        ll sum=0;
        ll ans=MINV;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++)dp[i][j]=MINV;
            dp[min(i,n-1)][0]=sum;
            for(int j=i+1;j<n;j++){
                ll ma=MINV;
                for(int l=1;l<=k;l++){
                    dp[j][l]=dp[j-1][l-1]+arr[j];
                    ma=max(ma,dp[j-1][l]);
                }
                dp[j][0]=max(ma,dp[j-1][0]);
            }
            for(int l=0;l+i<=k;l++)ans=max(ans,dp[n-1][l]);
            sum+=arr[i];
        }
        printf("%lli\n",ans);
    }
    return 0;
}