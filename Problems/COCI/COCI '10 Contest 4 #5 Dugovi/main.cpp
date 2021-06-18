#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
pair<int,ll> adj[MN];
ll cur[MN];
int in[MN];
bool done[MN];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> needed;
ll ans=0;
void prune(int a){
    if(done[a])return;
    ans+=max(ll(0),adj[a].second-cur[a]);
    cur[adj[a].first]+=adj[a].second;
    needed.push({adj[adj[a].first].second-cur[adj[a].first],adj[a].first});
    done[a]=true;
    in[adj[a].first]--;
    if(in[adj[a].first]==0)prune(adj[a].first);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    ll b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        adj[i]={a,b};
        in[a]++;
        needed.push({b,i});
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            prune(i);
        }
    }
    while(sz(needed)){
        auto cur=needed.top();
        needed.pop();
        if(done[cur.second])continue;
        prune(cur.second);
    }
    printf("%lli\n",ans);
    return 0;
}