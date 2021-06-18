#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pii> adj[MN];
int st[MN],miet[MN],et;
vector<int> reach;
vector<vector<int>> comps;
set<int> adj2[MN];
int comp[MN];
void dfs(int loc, int edge){
    st[loc]=miet[loc]=et++;
    reach.push_back(loc);
    for(auto x:adj[loc]){
        if(x.second!=edge){
            if(!st[x.first])dfs(x.first,x.second),miet[loc]=min(miet[loc],miet[x.first]);
            else miet[loc]=min(miet[loc],st[x.first]);
        }
    }
    if(st[loc]==miet[loc]){
        comps.push_back({});
        while(1){
            auto cur=reach.back();
            reach.pop_back();
            comp[cur]=sz(comps)-1;
            comps.back().push_back(cur);
            if(cur==loc)break;
        }
    }
}
map<int,set<int>> intern;
int nodecnt;
void prunecv(int a){
    assert(sz(adj2[a])==2);
    nodecnt--;
    int l=*adj2[a].begin(),r=*adj2[a].rbegin();
    if(intern[a].count(r)){
        if(intern[a].count(l)){
            intern[r].insert(l);
        }
        swap(l,r);
    }
    if(intern[a].count(l))intern[r].insert(l);
    intern.erase(a);
    adj2[l].insert(r),adj2[r].insert(l);
    adj2[l].erase(a),adj2[r].erase(a);
}
void removeleaf(int a){
    assert(sz(adj2[a])==1);
    nodecnt--;
    intern[*adj2[a].begin()].erase(a);
    if(sz(intern[*adj2[a].begin()])==0)intern.erase(*adj2[a].begin());
    adj2[*adj2[a].begin()].erase(a);
    if(sz(adj2[*adj2[a].begin()])==2)prunecv(*adj2[a].begin());
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
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            if(comp[x.first]!=comp[i]){
                adj2[comp[i]].insert(comp[x.first]);
            }
        }
    }
    vector<int> leaves;
    for(int i=0;i<sz(comps);i++)if(sz(adj2[i])<=1)leaves.push_back(i);
    if(sz(leaves)==1)printf("0\n");
    else{//https://cs.stackexchange.com/questions/107373/minimally-extend-a-tree-such-that-there-are-no-bridges-in-the-new-graph
        printf("%d\n",(sz(leaves)+1)/2);
        nodecnt=sz(comps);
        for(auto x:leaves)intern[*adj2[x].begin()].insert(x);
        for(int i=0;i<sz(comps);i++)if(sz(adj2[i])==2)prunecv(i);
        while(sz(intern)>=2&&nodecnt>=3){
            a=*intern.begin()->second.begin(),b=*intern.rbegin()->second.begin();
            printf("%d %d\n",comps[a].front(),comps[b].front());
            removeleaf(a),removeleaf(b);
        }
        if(sz(intern)==2)printf("%d %d\n",comps[intern.begin()->first].front(),comps[intern.rbegin()->first].front());
        else{
            if(sz(intern.begin()->second)%2==1){
                printf("%d %d\n",comps[*intern.begin()->second.begin()].front(),comps[*intern.begin()->second.rbegin()].front());
                intern.begin()->second.erase(intern.begin()->second.begin());
            }
            while(sz(intern.begin()->second)){
                printf("%d %d\n",comps[*intern.begin()->second.begin()].front(),comps[*intern.begin()->second.rbegin()].front());
                intern.begin()->second.erase(intern.begin()->second.begin());
                intern.begin()->second.erase(prev(intern.begin()->second.end(),1));
            }
        }
    }
    return 0;
}