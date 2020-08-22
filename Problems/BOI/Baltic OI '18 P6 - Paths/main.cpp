#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
ll dp[MAXN][(1<<5)];
int arr[MAXN];
pii edges[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]--;
        dp[i][(1<<arr[i])]=1;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second;
    }
    ll ans=0;
    for(int bit=2;bit<=k;bit++) {
        for (int i = 0; i < m; i++) {
            for(int j=0;j<(1<<5);j++){
                if(__builtin_popcount(j)==bit&&j&(1<<arr[edges[i].first])&&j&(1<<arr[edges[i].second])){
                    dp[edges[i].first][j]+=dp[edges[i].second][j-(1<<arr[edges[i].first])];
                    dp[edges[i].second][j]+=dp[edges[i].first][j-(1<<arr[edges[i].second])];
                    ans+=dp[edges[i].second][j-(1<<arr[edges[i].first])];
                    ans+=dp[edges[i].first][j-(1<<arr[edges[i].second])];
                }
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}