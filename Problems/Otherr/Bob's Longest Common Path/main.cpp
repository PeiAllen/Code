#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
pii paths[MN];
int sparse[19][2*MN];
int et=0;
int st[MN];
int en[MN];
int par[MN];
int dist[MN];
vector<int> tadd[MN],teadd[MN],tedel[MN];
int n,k;
void dfs(int loc){
    dist[loc]=dist[par[loc]]+1;
    sparse[0][et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc]){
        dfs(x);
        sparse[0][et++]=loc;
    }
    en[loc]=et;
}
int mh(int a, int b){
    if(dist[a]<dist[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<19;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int ans=-1;
multiset<int> ch[MN];
multiset<int> eti[MN];
int dfsans(int loc){
    int cur=loc;
    for(auto x:tadd[loc])ch[cur].insert(x);
    for(auto x:teadd[loc]){
        int lca=getlca(sparse[0][x],loc);
        if(lca!=loc) {
            auto it = eti[cur].lower_bound(x);
            if (it != eti[cur].end()) {
                if (getlca(sparse[0][*it], loc) == lca)ans = max(ans, dist[loc] + dist[getlca(sparse[0][x], sparse[0][*it])] - 2 * dist[lca]);
            }
            if (it != eti[cur].begin()) {
                it--;
                if (getlca(sparse[0][*it], loc) == lca)ans = max(ans, dist[loc] + dist[getlca(sparse[0][x], sparse[0][*it])] - 2 * dist[lca]);
            }
        }
        eti[cur].insert(x);
    }
    for(auto x:adj[loc]){
        int te=dfsans(x);
        if(sz(ch[te])>sz(ch[cur]))swap(te,cur);
        for(auto y:ch[te])ch[cur].insert(y);
        for(auto y:eti[te]){
            int lca=getlca(sparse[0][y],loc);
            if(lca!=loc) {
                auto it = eti[cur].lower_bound(y);
                if (it != eti[cur].end()) {
                    if (getlca(sparse[0][*it],loc)==lca)ans = max(ans, dist[loc] + dist[getlca(sparse[0][y], sparse[0][*it])] - 2 * dist[lca]);
                }
                if (it != eti[cur].begin()) {
                    it--;
                    if (getlca(sparse[0][*it],loc)==lca)ans = max(ans, dist[loc] + dist[getlca(sparse[0][y], sparse[0][*it])] - 2 * dist[lca]);
                }
            }
            eti[cur].insert(y);
        }
    }
    for(auto x:tedel[loc])eti[cur].erase(eti[cur].find(x));
    if(sz(ch[cur])>=2)ans=max(ans,dist[loc]-*next(ch[cur].begin(),1));
    return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        cin>>par[i];
        adj[par[i]].push_back(i);
    }
    dfs(1);
    ms();
    for(int i=0;i<k;i++){
        cin>>paths[i].first>>paths[i].second;
        int lca=getlca(paths[i].first,paths[i].second);
        tadd[paths[i].first].push_back(dist[lca]);
        tadd[paths[i].second].push_back(dist[lca]);
        teadd[paths[i].first].push_back(st[paths[i].second]);
        teadd[paths[i].second].push_back(st[paths[i].first]);
        tedel[lca].push_back(st[paths[i].first]),tedel[lca].push_back(st[paths[i].second]);
    }
    dfsans(1);
    printf("%d\n",ans);
    return 0;
}