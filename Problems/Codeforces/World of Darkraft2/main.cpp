#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
const int MAXL=700;
long double dp[2][MAXL];
long double dp2[2][MAXL];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    long double k;
    cin>>n>>k;
    dp2[0][1]=1;
    int cur=1,oth=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<min(i+2,MAXL);j++){
            dp2[cur][j]=(1/(long double)(j*k))*(dp2[oth][j-1])+(j/(long double)((j+1)*k))*dp2[oth][j]+((k-1)/(long double)k)*dp2[oth][j];
            dp[cur][j]=(dp[oth][j-1]+j-1)*(((1/(long double)(j*k))*(dp2[oth][j-1]))/dp2[cur][j])+(dp[oth][j]+(j*(j+1)/2)/(long double)j)*(((j/(long double)((j+1)*k))*dp2[oth][j])/dp2[cur][j])+dp[oth][j]*((((k-1)/(long double)k)*dp2[oth][j])/dp2[cur][j]);
        }
        swap(cur,oth);
    }
    long double ans=0;
    for(int i=1;i<min(n+2,MAXL);i++){
        ans+=dp[oth][i]*dp2[oth][i];
    }
    printf("%.9Lf",ans*k);
    return 0;
}