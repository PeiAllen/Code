#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2001;
ll dp[MN][MN][2];
vector<pair<int,ll>> adj[MN];
void dfs(int loc, int parent){
    
}
vector<long long> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
    for(int i=0;i<sz(U);i++){
        adj[U[i]].push_back({V[i],W[i]});
        adj[V[i]].push_back({U[i],W[i]});
    }
    dfs(0,-1);
    return vector<long long>(N, 0);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}