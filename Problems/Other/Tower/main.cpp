#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
const int MV=1e4+1;
ll dp[MN][2*MV];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<pii,ll>> arr;
    int a,b;
    ll c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        arr.push_back({{a,b},c});
    }
    sort(arr.begin(),arr.end(),[&](const auto &lhs, const auto &rhs){
        return lhs.first.first+lhs.first.second<rhs.first.first+rhs.first.second;
    });
    for(int i=1;i<=n;i++){
        for(int j=0;j<2*MV;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1].first.first&&j-arr[i-1].first.first<=arr[i-1].first.second){
                dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i-1].first.first]+arr[i-1].second);
            }
        }
    }
    ll ans=0;
    for(int i=0;i<2*MV;i++){
        ans=max(ans,dp[n][i]);
    }
    printf("%lli\n",ans);
    return 0;
}