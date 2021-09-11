#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=6;
vector<int> matrix[MN];
int dp[MN];
void dfs(int loc){
    dp[loc]=1;
    for(auto x:matrix[loc])dfs(x),dp[loc]*=(dp[x]+1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1,a;i<n;i++)cin>>a,matrix[a].push_back(i);
    dfs(n),printf("%d\n",dp[n]);
    return 0;
}