#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=202;
pll arr[MAXN];

lli l;
lli dis(int a, int b){
    return min(abs(arr[a].first-arr[b].first),l-abs(arr[a].first-arr[b].first));
}
lli dp[MAXN][MAXN][MAXN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i].second;
    }
    sort(arr+1,arr+n+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                for(int m=0;m<2;m++){
                    dp[i][j][k][m]=INT_MAX;
                }
            }
        }
    }
    int best=0;
    dp[0][0][0][0]=0;
    dp[0][0][0][1]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=i+j;k++){
                for(int m=0;m<2;m++) {
                    int cur=(m?n-(j-1):i);
                    if (i)dp[i][j][k][m] = min(dp[i][j][k][m],dp[i - 1][j][k][0] + dis(i-1,i)+dis(i,cur));
                    if (j)dp[i][j][k][m] = min(dp[i][j][k][m],dp[i][j - 1][k][0] + dis(i,n-(j-1))+dis(n-(j-1),cur));
                    if (i && k &&  dp[i - 1][j][k-1][0] + dis(i-1,i) <= arr[i].second)dp[i][j][k][m]=min(dp[i][j][k][m],dp[i - 1][j][k-1][0]+dis(i-1,i)+dis(i,cur));
                    if(j&&k&&dp[i][j - 1][k-1][0] + dis(i,n-(j-1))<=arr[n-(j-1)].second)dp[i][j][k][m] = min(dp[i][j][k][m],dp[i][j - 1][k-1][0] + dis(i,n-(j-1))+dis(n-(j-1),cur));
                    if (i)dp[i][j][k][m] = min(dp[i][j][k][m],dp[i - 1][j][k][1] + dis(n-(j-1),i)+dis(i,cur));
                    if (j)dp[i][j][k][m] = min(dp[i][j][k][m],dp[i][j - 1][k][1] + dis(n-(j-2),n-(j-1))+dis(n-(j-1),cur));
                    if (i && k &&  dp[i - 1][j][k-1][1] + dis(n-(j-1),i)<= arr[i].second)dp[i][j][k][m]=min(dp[i][j][k][m],dp[i - 1][j][k-1][1]+dis(n-(j-1),i)+dis(i,cur));
                    if(j&&k&&dp[i][j - 1][k-1][1] + dis(n-(j-2),n-(j-1))<=arr[n-(j-1)].second)dp[i][j][k][m]=min(dp[i][j][k][m],dp[i][j - 1][k-1][1] + dis(n-(j-2),n-(j-1))+dis(n-(j-1),cur));
                    if(dp[i][j][k][m]!=INT_MAX){
                        best=max(best,k);
                    }
                }
            }
        }
    }
    printf("%d\n",best);
    return 0;
}