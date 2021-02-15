#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
int arr[MN];
int dp[2][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cur=1;
    dp[0][m-1]=1;
    vector<int> ans;
    for(int i=m+n;i>=0;i--){
        for(int j=0;j<m;j++){
            if(dp[!cur][min(m-1,j+k)]-dp[!cur][j]>0)dp[cur][j]=(arr[i%n]==arr[(i-1+n)%n]);//1 is winning position if previous is same as you, 1 is losing position if previous is different
            else dp[cur][j]=(arr[i%n]!=arr[(i-1+n)%n]);
            if(j)dp[cur][j]+=dp[cur][j-1];
        }
        if(i<n){
            if(dp[cur][0]==(arr[i%n]==arr[(i-1+n)%n]))ans.push_back(arr[i%n]);
            else ans.push_back(!arr[i%n]);
        }
        cur=!cur;
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)printf("%d ",x);
    return 0;
}