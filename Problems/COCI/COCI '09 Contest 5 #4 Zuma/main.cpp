#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=102,MK=6;
int arr[MN];
int dp[MN][MN];
int n,k;
int solve(int l, int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    vector<int> locations={l-1};
    vector<vector<int>> tedp;
    tedp.push_back({});
    tedp.back().resize(MK,INT_MAX);
    tedp[0][0]=0;
    int best=INT_MAX;
    for(int i=l;i<=r;i++){
        if(arr[i]==arr[l]){
            tedp.push_back({});
            tedp.back().resize(MK,INT_MAX);
            for(int j=0;j<MK;j++){
                for(int from=0;from<SZ(locations);from++){
                    if(j>0&&tedp[from][j-1]!=INT_MAX)tedp[SZ(locations)][j]=min(tedp[SZ(locations)][j],tedp[from][j-1]+solve(locations[from]+1,i-1));
                    if(j==MK-1&&tedp[from][j]!=INT_MAX)tedp[SZ(locations)][j]=min(tedp[SZ(locations)][j],tedp[from][j]+solve(locations[from]+1,i-1));
                }
                if(tedp[SZ(locations)][j]!=INT_MAX){
                    best=min(best,tedp[SZ(locations)][j]+max(0,k-j)+solve(i+1,r));
                }
            }
            locations.push_back(i);
        }
    }
    return dp[l][r]=best;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
    printf("%d\n",solve(1,n));
    return 0;
}