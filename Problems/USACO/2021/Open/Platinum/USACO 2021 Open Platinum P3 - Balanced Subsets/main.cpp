#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=155;
const ll mod=1e9+7;
ll dp[2][2][2][MN][MN];
string arr[MN];
int psa[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=1;j<=n;j++){
            psa[i][j]=psa[i][j-1]+(arr[i][j-1]=='G');
        }
    }
    int cur=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int ld=0;ld<=1;ld++){
            for(int rd=0;rd<=1;rd++){
                for(int a=1;a<=n;a++) {
                    for (int b = 1; b <= n + 1; b++) {
                        dp[cur][ld][rd][a][b]=0;
                    }
                }
                for(int a=1;a<=n;a++) {
                    for (int b = a+1; b <= n+1; b++) {
                        dp[cur][ld][rd][a][b]=0;
                        if(psa[i][b-1]-psa[i][a-1]==b-a){
                            if(ld==0&&rd==0)dp[cur][ld][rd][a][b]=1;
                            for(int ld2=0;ld2<=ld;ld2++){
                                for(int rd2=0;rd2<=rd;rd2++){
                                    pii a2={1,n},b2={1,n+1};
                                    if(ld==0)a2.first=max(a2.first,a);
                                    else a2.second=min(a2.second,a);
                                    if(rd==0)b2.second=min(b2.second,b);
                                    else b2.first=max(b2.first,b);
                                    if(ld!=ld2)a2.second=min(a2.second,a-1);
                                    if(rd!=rd2)b2.first=max(b2.first,b+1);
                                    a2.second=min(a2.second,b-1);
                                    b2.first=max(b2.first,a+1);
                                    if(a2.first>a2.second||b2.first>b2.second)continue;
                                    dp[cur][ld][rd][a][b]+=dp[!cur][ld2][rd2][a2.second][b2.second]-dp[!cur][ld2][rd2][a2.first-1][b2.second]-dp[!cur][ld2][rd2][a2.second][b2.first-1]+dp[!cur][ld2][rd2][a2.first-1][b2.first-1]+mod+mod;
                                    dp[cur][ld][rd][a][b]%=mod;
                                }
                            }
                        }
                        ans=(ans+dp[cur][ld][rd][a][b])%mod;
                    }
                }
                for(int a=1;a<=n;a++){
                    for (int b = 1; b <= n+1; b++) {
                        dp[cur][ld][rd][a][b] += dp[cur][ld][rd][a - 1][b] + dp[cur][ld][rd][a][b - 1] - dp[cur][ld][rd][a - 1][b - 1] + mod;
                        dp[cur][ld][rd][a][b] %= mod;
                    }
                }
            }
        }
        cur=!cur;
    }
    printf("%lli\n",ans);
    return 0;
}