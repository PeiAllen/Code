#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=101;
ll arr[MAXN];
ll dp[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    ll ans=0;
    while(r--){
        for(int i=1;i<=c;i++)cin>>arr[i];
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                if(i==j)dp[i][j]=arr[i]*c;
                else{
                    dp[i][j]=max(dp[i+1][j]+arr[i]*(c-(j-i)),dp[i][j-1]+arr[j]*(c-(j-i)));
                }
            }
        }
        ans+=dp[1][c];
    }
    printf("%lli\n",ans);
    return 0;
}