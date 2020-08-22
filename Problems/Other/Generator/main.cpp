#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll dp[12][(1<<11)+1][(1<<11)+1];
ll mod=1e9+7;
ll fix(ll a){
    if(a>=mod)a-=mod;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    dp[0][0][0]=1;
    for(int R=19;R<=19;R++){
        int n=32-__builtin_clz(R);
        assert(n<=11);
        int ext=(1<<(n))-1-R;
        assert(ext<=(1<<11)+1);
        printf("%d\n",ext);
        for(int i=1;i<=n;i++){
            for(int k=0;k<=ext;k++){
                for(int j=max(1,(1<<(i-1))-k);j<=(1<<(i-1));j++){
                    if((1<<(i-1))-1-(k-((1<<(i-1))-j))>=j-1){
                        dp[i][k][j]=dp[i-1][k-((1<<(i-1))-j)][min(j,(i==1?0:(1<<(i-2))))];
                    }
                    else dp[i][k][j]=0;
                    if(j>max(1,(1<<(i-1))-k))dp[i][k][j]=fix(dp[i][k][j]+dp[i][k][j-1]);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=ext;i++)ans=fix(ans+dp[n][i][(1<<(n-1))]);
        printf("%d: %lli\n",R,ans);
    }
    return 0;
}