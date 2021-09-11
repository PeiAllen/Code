#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1,MV=1000*10+1;
int dp[MN][(1<<10)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string a;
    for(int j=0;j<(1<<10);j++)dp[0][j]=MV;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=0;j<(1<<m);j++){
            int am=0;
            bool last=false,work=true;
            for(int k=0;k<m;k++){
                if(j&(1<<k)){
                    if(a[k]=='.')work=false;
                    last=false;
                }
                else {
                    if(a[k]=='#'){
                        if(!last)am++;
                        last=true;
                    }
                    else last=false;
                }
            }
            dp[i][j]=MV;
            if(work){
                for(int k=j;;k=(k-1)&j){
                    dp[i][j]=min(dp[i][j],am+dp[i-1][k]+__builtin_popcount(j)-__builtin_popcount(k));
                    if(k==0)break;
                }
            }
        }
        for(int j=0;j<(1<<m);j++){
            for(int k=j;;k=(k-1)&j){
                dp[i][k]=min(dp[i][k],dp[i][j]);
                if(k==0)break;
            }
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}