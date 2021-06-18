#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
const ll mod=1e9+7;
ll dp[2][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n>>a;
    if(a!=0&&a!=-1){
        printf("0\n");
        return 0;
    }
    dp[0][0]=1;
    int cur=1;
    for(int i=1;i<n;i++){
        cin>>a;
        if(a==-1){
            for(int j=0;j<=5010;j++){
                dp[cur][j]=dp[!cur][j]+(j-1>=0?dp[!cur][j-1]:0)+dp[!cur][j+1];
                while(dp[cur][j]>=mod)dp[cur][j]-=mod;
            }
        }
        else{
            for(int j=0;j<=5010;j++)dp[cur][j]=0;
            if(a<=5010){
                dp[cur][a]=dp[!cur][a]+(a-1>=0?dp[!cur][a-1]:0)+dp[!cur][a+1];
                while(dp[cur][a]>=mod)dp[cur][a]-=mod;
            }
        }
        cur=!cur;
    }
    printf("%lli\n",dp[!cur][0]);
    return 0;
}