#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pii> adj[MN];
vector<int> nodes;
int st[MN],lst[MN],et;
vector<int> adj2[MN*2];
int compcnt=0,n,k;
ll compval[MN],arr[MN];
auto addnode(int node,int comp){
    compval[comp]+=arr[node];
    adj2[node].push_back(comp+n);
    adj2[comp+n].push_back(node);
}
void dfs(int loc, int eind){
    st[loc]=lst[loc]=et++;
    nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(x.second==eind)continue;
        if(!st[x.first]){
            dfs(x.first,x.second);
            lst[loc]=min(lst[loc],lst[x.first]);
            if(lst[x.first]==st[x.first]){
                compcnt++;
                addnode(loc,compcnt),addnode(x.first,compcnt);
            }
            else if(lst[x.first]==st[loc]){
                compcnt++;
                addnode(loc,compcnt);
                while(1){
                    auto cur=nodes.back();
                    nodes.pop_back();
                    addnode(cur,compcnt);
                    if(cur==x.first)break;
                }
            }
        }
        else lst[loc]=min(lst[loc],st[x.first]);
    }
    if(lst[loc]==st[loc])nodes.pop_back();
}
ll dp[MN*2][21][2];
void solve(int loc, int parent){
    if(loc<=n){
        for(auto x:adj2[loc]){
            if(x==parent)continue;
            solve(x,loc);
            for(int i=k;i>=0;i--){
                for(int j=0;j<=1;j++){
                    for(int i2=0;i2+i<=k;i2++){
                        for(int j2=0;j2<=1;j2++){
                            dp[loc][i+i2][j||j2]=max(dp[loc][i+i2][j||j2],dp[loc][i][j]+dp[x][i2][j2]-(j&&j2)*arr[loc]);
                        }
                    }
                }
            }
        }
    }
    else{
        dp[loc][1][1]=compval[loc-n];
        for(auto x:adj2[loc]){
            if(x==parent)continue;
            solve(x,loc);
            for(int i=k;i>=0;i--){
                for(int j=0;j<=1;j++){
                    for(int i2=0;i2+i<=k;i2++){
                        for(int j2=0;j2<=1;j2++){
                            dp[loc][i+i2][j]=max(dp[loc][i+i2][j],dp[loc][i][j]+dp[x][i2][j2]-(j&&j2)*arr[x]);
                        }
                    }
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,a,b;
    ll cost;
    cin>>n>>m>>k>>cost;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++)cin>>arr[i];
    et=1;
    dfs(1,-1);
    for(int i=1;i<=n;i++)assert(st[i]);
    solve(1,0);
    ll best=cost*k;
    for(int i=1;i<=k;i++){
        best=max(best,max(dp[1][i][0],dp[1][i][1])+cost*(k-i));
    }
    printf("%lli\n",best);
    return 0;
}