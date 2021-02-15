#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=1e5+1;
int conver(char a){
    if(a=='A')return 0;
    if(a=='G')return 1;
    if(a=='C')return 2;
    return 3;
}
ll dp[MN][4][4][4];//at i with needing jth end character, has starting character k and most recent character l
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    if(a[0]=='?')for(int i=0;i<4;i++)for(int j=0;j<4;j++)dp[0][i][j][j]=1;
    else for(int i=0;i<4;i++)dp[0][i][conver(a[0])][conver(a[0])]=1;
    for(int i=1;i<sz(a);i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(a[i]=='?'||conver(a[i])==l){
                        for(int f=0;f<4;f++)if(f!=l)dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][j][k][f])%mod;
                        if(l==k)for(int f=0;f<4;f++)dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][f][j][f])%mod;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)ans=(ans+dp[sz(a)-1][i][j][i])%mod;
    printf("%lli\n",ans);
    return 0;
}