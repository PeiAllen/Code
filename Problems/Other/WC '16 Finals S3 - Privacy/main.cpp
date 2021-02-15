#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e2+1;
int dp[MN][MN];
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;
    l++;
    for(int j=1;j<=l;j++)dp[0][j]=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        int val=0;
        int badam=0;
        priority_queue<int,vector<int>,greater<>> q;
        q.push(arr[i]);
        for(int j=0;j<=l;j++)dp[i][j]=INT_MAX;
        for(int j=i-1;j>=0;j--){
            while(sz(q)&&q.top()<i-j-1)badam++,val+=(i-j-1-q.top()-1),q.pop();
            val+=badam;
            for(int k=1;k<=min(i,l);k++){
                if(dp[j][k-1]!=INT_MAX)dp[i][k]=min(dp[i][k],dp[j][k-1]+val);
            }
            q.push(arr[j]);
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=l;i++){
        ans=min(ans,dp[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}