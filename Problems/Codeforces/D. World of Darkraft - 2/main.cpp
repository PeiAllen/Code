#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
const int MAXL=1000;
long double dp[MAXN][MAXL];
long double dp2[MAXN][MAXL];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    long double k;
    cin>>n>>k;
    dp2[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<min(i+2,MAXL);j++){
            dp[i][j]=(1/(long double)(j*k))*(dp[i-1][j-1]+j-1)+(j/(long double)((j+1)*k))*(dp[i-1][j]+(j*(j+1)/2)/(long double)j);
            dp2[i][j]=(1/(long double)(j*k))*(dp2[i-1][j-1])+(j/(long double)((j+1)*k))*dp2[i-1][j];
        }
    }
    long double ans=0;
    for(int i=1;i<min(n+2,MAXL);i++){
        ans+=dp2[n][i]*dp[n][i];
    }
    cout<<ans*k;
    return 0;
}