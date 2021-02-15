#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int dp[MAXN][2];
bool done[MAXN];
void dfs(int loc, int parent){
    done[loc]=true;
    int sum=0;
    vector<int> chg;
    for(auto x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc);
            sum+=dp[x][0];
            chg.push_back(dp[x][1]-dp[x][0]);
        }
    }
    sort(chg.begin(),chg.end());
    dp[loc][0]=1e6;
    if(sz(chg)>=2)dp[loc][0]=sum+chg[0]+chg[1]+1;
    dp[loc][1]=sum;
    if(sz(chg)>=1)dp[loc][1]=min(dp[loc][1],sum+chg[0]);
    dp[loc][0]=min(dp[loc][0],dp[loc][1]+1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        int am=n+(n-1-m);
        int a,b;
        for(int i=1;i<=n;i++)matrix[i]=vector<int>(),done[i]=false;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            matrix[a].push_back(b),matrix[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(!done[i]){
                dfs(i,0);
                am+=min(dp[i][0],dp[i][1]+1)-1;
            }
        }
        printf("%d\n",am);
    }
    return 0;
}