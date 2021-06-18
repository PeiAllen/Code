#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e4+1;
const ll mod=1e9+7;
vector<pii> adj[MN];
int st[MN],lst[MN],et;
vector<int> nodes;
int tosub[MN];
bool bad=false;
ll ans=1;
int dfs(int loc, int edgeind){
    nodes.push_back(loc);
    lst[loc]=st[loc]=et++;
    int cnt=0;
    for(auto x:adj[loc]){
        if(x.second==edgeind)continue;
        if(st[x.first]){
            lst[loc]=min(lst[loc],st[x.first]);
            if(st[x.first]<st[loc]){
                tosub[x.first]++;
                cnt++;
            }
        }
        else{
            cnt+=dfs(x.first,x.second);
            if(lst[x.first]==st[loc]){
                ll am=1;
                while(1){
                    auto cur=nodes.back();
                    am++;
                    nodes.pop_back();
                    if(cur==x.first)break;
                }
                ans=ans*am%mod;
            }
            lst[loc]=min(lst[loc],lst[x.first]);
        }
    }
    cnt-=tosub[loc];
    if(cnt>=2)bad=true;
    if(lst[loc]==st[loc])nodes.pop_back();
    return cnt;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    et=1;
    dfs(1,-1);
    if(bad){
        printf("safe\n");
        return 0;
    }
    for(int i=1;i<=n;i++)if(!st[i]){
        printf("safe\n");
        return 0;
    }
    printf("%lli\n",ans);
    return 0;
}