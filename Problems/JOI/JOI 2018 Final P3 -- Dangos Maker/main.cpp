#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[3001][3001];

int dp[3];
int te[3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<n+m-1;i++){
        dp[0]=0,dp[1]=0,dp[2]=0;
        for(int j=max(0,i-m);j<=min(i,n-1);j++){
            if(arr[j][i-j]=='G'){
                for(int k=0;k<3;k++)te[k]=dp[k];
                dp[0]=max(dp[0],max(dp[1],dp[2]));
                if(j>0&&arr[j-1][i-j]=='R'&&j<n-1&&arr[j+1][i-j]=='W'){
                    dp[1]=max(te[1],te[0])+1;
                }
                if(i-j>0&&arr[j][i-j-1]=='R'&&i-j<m-1&&arr[j][i-j+1]=='W'){
                    dp[2]=max(te[2],te[0])+1;
                }
            }
            else dp[0]=max(dp[0],max(dp[1],dp[2]));
        }
        ans+=max(dp[0],max(dp[1],dp[2]));
    }
    printf("%d\n",ans);
    return 0;
}