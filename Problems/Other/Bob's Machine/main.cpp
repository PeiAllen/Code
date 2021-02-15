#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
vector<pii> arr[MN];
int dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,r;
    cin>>n>>m>>r;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        arr[b+r].push_back({a,c});
    }
    for(int i=1;i<=2*n;i++){
        dp[i]=dp[i-1];
        for(auto x:arr[i])dp[i]=max(dp[x.first]+x.second,dp[i]);
    }
    printf("%d\n",dp[2*n]);
    return 0;
}