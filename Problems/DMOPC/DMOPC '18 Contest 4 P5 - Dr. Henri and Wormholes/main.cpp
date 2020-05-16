#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<pair<int,pair<lli,int>>> matrix[MAXN];
bool both[MAXN];
lli dp[MAXN][2];
vector<lli> diffs[MAXN];
lli ans=0;
void dfs(int loc, int parent){
    for(auto x:matrix[loc]){
        if(x.first!=parent) {
            dfs(x.first, loc);
            dp[loc][0] += (x.second.second ? dp[x.first][0] + x.second.first * 2 : 0);
            diffs[loc].push_back(dp[x.first][1] + x.second.first - (x.second.second ? dp[x.first][0] + x.second.first * 2 : 0));
        }
    }
    sort(diffs[loc].begin(),diffs[loc].end(),greater<>());
    dp[loc][1]=dp[loc][0]+max((lli)0,(sz(diffs[loc])?*diffs[loc].begin():(lli)0));
}
void dfs2(int loc, int parent, lli weight, int edgetype){
    dp[loc][0]+=(edgetype?dp[parent][0]+2*weight-(dp[loc][0]+2*weight):0);

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a,b;
    lli t;
    for(int i=0;i<k;i++){
        cin>>a;
        both[a]=true;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b>>t;
        matrix[a].push_back({b,{t,both[i]}});
        matrix[b].push_back({a,{t,both[i]}});
    }
    dfs(1,0);
    dfs2(1,0,0,0);
    printf("%lli\n",ans);
    return 0;
}