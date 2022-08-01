#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1,MM=2e5+1;
ll dist[MN];
vector<pair<int,ll>> adj[MN];
pair<pii,ll> edge[MM];
int n;
vector<ll> dists;
void dfs(int loc){
    if(loc==n){
        dists.push_back(dist[loc]);
    }
    for(auto x:adj[loc]){
        if(!dist[x.first]){
            dist[x.first]=dist[loc]+x.second;
            dfs(x.first);
            dist[x.first]=0;
        }
    }
}
pll dp[(1<<18)][18];
vector<ll> miedgesset[19];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].first.first>>edge[i].first.second>>edge[i].second;
        adj[edge[i].first.first].push_back({edge[i].first.second,edge[i].second});
        adj[edge[i].first.second].push_back({edge[i].first.first,edge[i].second});
    }
    if(n<=18) {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)miedgesset[j]=vector<ll>();
            for(auto x:adj[i]){
                miedgesset[x.first].push_back(x.second);
            }
            adj[i]=vector<pair<int,ll>>();
            for(int j=1;j<=n;j++){
                sort(miedgesset[j].begin(),miedgesset[j].end());
                for(int k=0;k<min(2,sz(miedgesset[j]));k++){
                    adj[i].push_back({j,miedgesset[j][k]});
                }
            }
        }
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                dp[i][j]={LLONG_MAX,LLONG_MAX};
                if(i&(1<<j)){
                    if(i==1&&j==0){
                        dp[i][j]={0,LLONG_MAX};
                        continue;
                    }
                    for(pair<int,ll> x:adj[j+1]){
                        x.first--;
                        if(i&(1<<x.first)){
                            if(dp[i^(1<<j)][x.first].first!=LLONG_MAX){
                                ll tedist=dp[i^(1<<j)][x.first].first+x.second;
                                if(tedist<dp[i][j].first){
                                    dp[i][j].second=dp[i][j].first;
                                    dp[i][j].first=tedist;
                                }
                                else if(tedist>dp[i][j].first&&tedist<dp[i][j].second){
                                    dp[i][j].second=tedist;
                                }
                                if(dp[i^(1<<j)][x.first].second!=LLONG_MAX){
                                    tedist=dp[i^(1<<j)][x.first].second+x.second;
                                    if(tedist<dp[i][j].first){
                                        dp[i][j].second=dp[i][j].first;
                                        dp[i][j].first=tedist;
                                    }
                                    else if(tedist>dp[i][j].first&&tedist<dp[i][j].second){
                                        dp[i][j].second=tedist;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<ll> possdists;
        for(int i=0;i<(1<<n);i++){
            if(dp[i][n-1].first!=LLONG_MAX)possdists.push_back(dp[i][n-1].first);
            if(dp[i][n-1].second!=LLONG_MAX)possdists.push_back(dp[i][n-1].second);
        }
        for (auto x: possdists) {
            if (x != possdists[0]) {
                printf("1\n");
                return 0;
            }
        }
        printf("0\n");
    }
    else{
        dist[1] = 1;
        dfs(1);
        for (auto x: dists) {
            if (x != dists[0]) {
                printf("1\n");
                return 0;
            }
        }
        printf("0\n");
    }
    return 0;
}