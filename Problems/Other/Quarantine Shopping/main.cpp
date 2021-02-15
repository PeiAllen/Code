#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll dp[1001][1001];
int am[1001][1001];
int cost[1001];
int deq[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    int c,s;
    ll v;
    for(int i=1;i<=n;i++){
        cin>>c>>v>>s;
        cost[i]=c;
        for(int m=0;m<c;m++){
            int l=0,r=-1;
            for(int j=m;j<=d;j+=c){
                while(l<=r&&dp[i-1][deq[r]]+(j-deq[r])/c*v<=dp[i-1][j])r--;
                deq[++r]=j;
                while(l<=r&&(j-deq[l])/c>s)l++;
                dp[i][j]=dp[i-1][j],am[i][j]=0;
                if(l<=r&&dp[i-1][deq[l]]+(j-deq[l])/c*v>=dp[i][j]){
                    dp[i][j]=dp[i-1][deq[l]]+(j-deq[l])/c*v;
                    am[i][j]=(j-deq[l])/c;
                }
            }
        }
    }
    int best=max_element(dp[n],dp[n]+d+1)-dp[n];
    printf("%lli\n",dp[n][best]);
    stack<int> vals;
    for(int i=n;i>=1;i--){
        vals.push(am[i][best]);
        best-=cost[i]*am[i][best];
    }
    while(sz(vals))printf("%d\n",vals.top()),vals.pop();
    return 0;
}