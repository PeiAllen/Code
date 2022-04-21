#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pii arr[MN];
bool given[MN];
vector<pii> adj[MN];
bool gone[MN];
vector<pair<pii,int>> badedges;
bool goodedge[MN];
void dfs(int loc, int eind){
    gone[loc]=true;
    for(auto x:adj[loc]){
        if(x.second!=eind){
            if(gone[x.first]){
                badedges.push_back({{loc,x.first},x.second});
            }
            else{
                dfs(x.first,x.second);
                goodedge[x.second]=true;
            }
        }
    }
}
vector<int> ord;
void dfs2(int loc, int eind){
    for(auto x:adj[loc]){
        if(x.second!=eind){
            if(goodedge[x.second]){
                given[x.second]=true;
                ord.push_back(x.second);
                dfs2(x.first,x.second);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        adj[arr[i].first].push_back({arr[i].second,i});
        adj[arr[i].second].push_back({arr[i].first,i});
    }
    for(int i=1;i<=m;i++){
        if(!gone[i]) {
            badedges = vector<pair<pii, int>>();
            dfs(i, -1);
            int root = i;
            if (sz(badedges)) {
                if (badedges[0].first.first != arr[badedges[0].second].first)swap(badedges[0].first.first, badedges[0].first.second);
                root = badedges[0].first.first;
                given[badedges[0].second]=true;
                ord.push_back(badedges[0].second);
            }
            dfs2(root, -1);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(!given[i])ord.push_back(i),cnt++;
    printf("%d\n",cnt);
    for(auto x:ord)printf("%d\n",x);
    return 0;
}