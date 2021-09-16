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
pii final;
int getworst(int loc, int parent){
    vector<int> children;
    for(auto x:adj[loc]){
        if(x!=parent){
            children.push_back(x);
        }
    }
    sort(children.begin(),children.end(),[&](const auto &lhs, const auto &rhs){
        return dp[lhs]>dp[rhs];
    });
    if(parent){
        vector<pii> nodes={{sz(children),loc}};
        for (int i = 0; i < sz(children); i++) {
            nodes.push_back({dp[children[i]]+i,getworst(children[i],loc)});
        }
        sort(nodes.begin(),nodes.end(),greater<>());
        int ind=0;
        while(ind+1<sz(nodes)&&nodes[ind+1].first==nodes[0].first)ind++;
        return nodes[rnd.next(0,ind)].second;
    }
    else{
        if(sz(children)==0)final={loc,loc};
        else {
            vector<pii> nodes={{sz(children)-1,loc}};
            vector<int> firstnodes={getworst(children[0],loc)};
            for (int i = 1; i < sz(children); i++) {
                int worst=getworst(children[i],loc);
                nodes.push_back({dp[children[i]] + i-1, worst});
                if(dp[children[i]]==dp[children[0]])firstnodes.push_back(worst);
            }
            sort(nodes.begin(),nodes.end(),greater<>());
            int ind=0;
            while(ind+1<sz(nodes)&&nodes[ind+1].first==nodes[0].first)ind++;
            int child=nodes[rnd.next(0,ind)].second;
            if(firstnodes.back()==child)firstnodes.pop_back();
            final={child,firstnodes[rnd.next(0,sz(firstnodes)-1)]};
        }
    }
    return -1;
}
pii worstdepth(int loc, int parent, int dep){
    pii worst={dep,loc};
    for(auto x:adj[loc]){
        if(x!=parent){
            worst=max(worst,worstdepth(x,loc,dep+1));
        }
    }
    return worst;
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=stoi(argv[1]),t=stoi(argv[2]),abt=stoi(argv[3]);//t is the elongation https://codeforces.com/blog/entry/18291
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
    fans.resize(n+1);
    dfs(1,0);
    walkdfs(1,0,-1);
    int f=max_element(fans.begin()+1,fans.end())-fans.begin();
    if(abt==1){//worst a,b for f
        dfs(f,0);
        getworst(f,0);
        if(rnd.next(0,1)==0)swap(final.first,final.second);
        printf("%d %d\n",final.first,final.second);
        printf("%d\n",f);
    }
    else if(abt==2){//a=b=f
        printf("%d %d\n",f,f);
        printf("%d\n",f);
    }
    else if(abt==3){//a,b = deepest depths
        vector<pii> depths;
        for(auto x:adj[f]){
            depths.push_back(worstdepth(x,f,0));
        }
        sort(depths.begin(),depths.end(),greater<>());
        while(sz(depths)<2)depths.push_back({(sz(depths)?depths[0].first:0),f});
        sort(depths.begin(),depths.end(),greater<>());
        int ind=0;
        while(ind+1<sz(depths)&&depths[ind+1].first==depths[0].first)ind++;
        shuffle(depths.begin(),depths.begin()+ind+1);
        printf("%d %d\n",depths[0].second,depths[1].second);
        printf("%d\n",f);
    }
    return 0;
}
