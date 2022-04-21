#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<int> adj[MN];
int dp[MN][2][2];
void dfs(int loc, int parent){

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;)
    return 0;
}