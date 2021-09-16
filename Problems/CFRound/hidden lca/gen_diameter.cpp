#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=1e5+1;
int par[MN];
vector<int> adj[MN];
int dist[MN];
void dfsd(int loc, int parent){
    dist[loc]=dist[parent]+1;
    for(auto x:adj[loc])if(x!=parent)dfsd(x,loc);
}
int dp[MN],depth[MN];
void dfs(int loc, int parent){
    vector<int> children;
    depth[loc]=depth[parent]+1;
    for(auto x:adj[loc]){
        if(x!=parent){
            dfs(x,loc);
            children.push_back(dp[x]);
        }
    }
    sort(children.begin(),children.end(),greater<>());
    dp[loc]=1;
    if(parent) {
        for (int i = 0; i < sz(children); i++) {
            dp[loc] = max(dp[loc], children[i] + i);
        }
    }
    else{
        dp[loc]=0;
        for (int i = 1; i < sz(children); i++) {
            dp[loc] = max(dp[loc], children[i] + i - 1);
        }
        if(sz(children))dp[loc]+=children.front();
    }
}
vector<int> fans;
void walkdfs(int loc, int parent, int parentdp){
    vector<pii> children;
    if(parentdp!=-1)children.push_back({parentdp,parent});
    for(auto x:adj[loc])if(x!=parent)children.push_back({dp[x],x});
    sort(children.begin(),children.end(),greater<>());
    int nodeans=0;
    for (int i = 1; i < sz(children); i++) {
        nodeans = max(nodeans, children[i].first + i - 1);
    }
    if(sz(children))nodeans+=children.front().first;
    fans[loc]=nodeans;
    vector<int> pre,suf(sz(children));
    for(int i=0;i<sz(children);i++){
        pre.push_back(max(sz(pre)?pre.back():0,children[i].first+i));
    }
    for(int i=sz(children)-1;i>=0;i--){
        suf[i]=max((i==sz(children)-1?0:suf[i+1]+1),children[i].first);
    }
    for(int i=0;i<sz(children);i++){
        if(children[i].second!=parent){
            walkdfs(children[i].second,loc,max((i-1>=0?pre[i-1]:1),(i+1<sz(suf)?suf[i+1]+i:1)));
        }
    }
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=stoi(argv[1]),t=stoi(argv[2]),ft=stoi(argv[3]);//t is the elongation https://codeforces.com/blog/entry/18291
    printf("%d\n",n);
    for(int i=1;i<n;i++){
        par[i]=rnd.wnext(i,t);
    }
    vector<int> perm(n);
    for(int i=0;i<n;i++)perm[i]=i+1;
    shuffle(perm.begin(),perm.end());
    vector<pii> edges;
    for(int i=1;i<n;i++){
        edges.push_back({perm[par[i]],perm[i]});
    }
    shuffle(edges.begin(),edges.end());
    for(auto x:edges)printf("%d %d\n",x.first,x.second),adj[x.first].push_back(x.second),adj[x.second].push_back(x.first);
    dfsd(1,0);
    int a=max_element(dist+1,dist+n+1)-dist;
    dfsd(a,0);
    int b=max_element(dist+1,dist+n+1)-dist;
    printf("%d %d\n",a,b);

    // ========= OUTPUT NODE ON PATH ===============
    auto outputNodeOnPath = [] (int N, vector<pii> edges, int A, int B, int type, vector<int> neededops) {
        vector<vector<int>> g(N+1);
        for (auto [a, b] : edges) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> path;
        function<bool(int, int, int)> getPath = [&] (int c, int p, int end) {
            if (c == end) {
                path.push_back(c);
                return true;
            }
            bool ok = false;
            for (auto to : g[c]) {
                if (to != p) {
                    ok |= getPath(to, c, end);
                }
            }
            if (ok) path.push_back(c);
            return ok;
        };
        getPath(A, -1, B);
        if(type==1){//random F
            printf("%d\n", path[rnd.next(0, (int)path.size()-1)]);
        }
        else if(type==2){//random endpoint
            if(rnd.next(0,1)==0)printf("%d\n",path[0]);
            else printf("%d\n",path[sz(path)-1]);
        }
        else if(type==3){//midpoint
            printf("%d\n",path[sz(path)/2]);
        }
        else if(type==4){//worstcase
            int worst=path[0];
            for(auto x:path){
                if(neededops[x]>neededops[worst])worst=x;
            }
            printf("%d\n",worst);
        }
        else assert(0);
    };
    // ========= OUTPUT NODE ON PATH ===============
    fans.resize(n+1);
    dfs(1,0);
    walkdfs(1,0,-1);
    outputNodeOnPath(n, edges, a, b,ft,fans);

    return 0;
}
