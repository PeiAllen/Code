#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<pii> adj[MN];
stack<int> nodes;
stack<int> edges;
vector<vector<int>> ebccs,nbccs;
int st[MN],low[MN],et=0;
void getbcc(int loc, int eind){
    st[loc]=low[loc]=++et;
    edges.push(eind);
    nodes.push(loc);
    for(auto x:adj[loc]){
        if(x.second!=eind){
            if(!st[x.first]){
                getbcc(x.first,x.second);
                low[loc]=min(low[loc],low[x.first]);
                if(low[x.first]==st[x.first]){
                    nbccs.push_back({{loc,x.first}});
                    ebccs.push_back({x.second});
                    nodes.pop(),edges.pop();
                }
                else if(low[x.first]==st[loc]){
                    nbccs.push_back({loc});
                    ebccs.push_back({});
                    while(1){
                        nbccs.back().push_back(nodes.top());
                        nodes.pop();
                        if(nbccs.back().back()==x.first)break;
                    }
                    while(1){
                        ebccs.back().push_back(edges.top());
                        edges.pop();
                        if(ebccs.back().back()==x.second)break;
                    }
                }
            }
            else{
                low[loc]=min(low[loc],st[x.first]);
                if(st[x.first]<st[loc])edges.push(x.second);
            }
        }
    }
    if(eind==-1)nodes.pop(),edges.pop();
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
    for(int i=1;i<=n;i++)if(!st[i])getbcc(i,-1);
    printf("%d\n",sz(ebccs));
    for(auto x:ebccs){
        printf("%d",sz(x));
        for(auto y:x)printf(" %d",y);
        printf("\n");
    }
    return 0;
}