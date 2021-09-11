#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
vector<int> adj[MN];
int pc[MN][MN];
double dp[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,e,cst,kst,a,b;
    cin>>n>>e>>cst>>kst;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}