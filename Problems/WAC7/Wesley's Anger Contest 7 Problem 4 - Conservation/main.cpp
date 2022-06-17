#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
vector<int> arr[MN];
int dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        arr[a].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int ptr=0;
        for(int j=1;j<=sz(arr[i]);j++){
            dp[j]=dp[j-1];
            while(arr[i][ptr]<arr[i][j-1]-2)ptr++;
            dp[j]=max(dp[j],dp[ptr]+1);
        }
        ans+=dp[sz(arr[i])];
    }
    printf("%d\n",ans);
    return 0;
}