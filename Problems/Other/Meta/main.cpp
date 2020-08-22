#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
pii longest;
int longestdepth[MAXN];
int par[MAXN];
int depth[MAXN];
int dfs(int loc, int parent, int dist){
    depth[loc]=dist;
    par[loc]=parent;
    longestdepth[loc]=0;
    if(dist>longest.second)longest={loc,dist};
    for(int x:matrix[loc]){
        if(x!=parent)longestdepth[loc]=max(longestdepth[loc],dfs(x,loc,dist+1)+1);
    }
    return longestdepth[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    longest={-1,-1};
    dfs(1,0,0);
    int oneend=longest.first;
    longest={-1,-1};
    dfs(oneend,0,0);
    int othend=longest.first;
    int cur=othend;
    int len=0;
    int metaoneend=cur;
    int last=-1;
    while(cur){
        for(auto x:matrix[cur]){
            if(x!=par[cur]&&longestdepth[x]+1==len&&x!=last){
                metaoneend=cur;
            }
        }
        last=cur;
        cur=par[cur];
        len++;
    }
    dfs(othend,0,0);
    cur=oneend;
    len=0;
    int metaothend=cur;
    last=-1;
    while(cur){
        for(auto x:matrix[cur]){
            if(x!=par[cur]&&longestdepth[x]+1==len&&x!=last){
                metaothend=cur;
            }
        }
        last=cur;
        cur=par[cur];
        len++;
    }
    dfs(metaoneend,0,0);
    printf("%d\n",depth[metaothend]+1);
    return 0;
}