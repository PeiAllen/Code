#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
map<pii,int> used;
vector<int> matrix[MAXN];
vector<int> col[MAXN];
int lift[17][MAXN];
int depth[MAXN];
int val[MAXN];
void dfs(int loc, int parent, int dep){
    lift[0][loc]=parent;
    depth[loc]=dep;
    for(int x:matrix[loc]){
        if(x!=parent)dfs(x,loc,dep+1);
    }
}
int n;
void ml(){
    for(int i=1;i<=16;i++){
        for(int j=1;j<n-1;j++){
            lift[i][j]=lift[i-1][lift[i-1][j]];
        }
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<17;i++){
        if(diff&(1<<i))a=lift[i][a];
    }
    if(a==b)return a;
    for(int i=16;i>=0;i--){
        if(lift[i][a]!=lift[i][b])a=lift[i][a],b=lift[i][b];
    }
    return lift[0][a];
}
int ans;
int dfsans(int loc, int parent){
    for(int x:matrix[loc]){
        if(x!=parent){
            val[loc]+=dfsans(x,loc);
        }
    }
    if(val[loc]==0&&parent!=0)ans++;
    return val[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int a,b,c,d;
    for(int i=1;i<n-1;i++){
        cin>>a>>b>>c>>d;
        col[d].push_back(i);
        if(used.count({min(a,b),max(a,b)})){
            matrix[i].push_back(used[{min(a,b),max(a,b)}]);
            matrix[used[{min(a,b),max(a,b)}]].push_back(i);
        }
        else used[{min(a,b),max(a,b)}]=i;
        if(used.count({min(a,c),max(a,c)})){
            matrix[i].push_back(used[{min(a,c),max(a,c)}]);
            matrix[used[{min(a,c),max(a,c)}]].push_back(i);
        }
        else used[{min(a,c),max(a,c)}]=i;
        if(used.count({min(c,b),max(c,b)})){
            matrix[i].push_back(used[{min(c,b),max(c,b)}]);
            matrix[used[{min(c,b),max(c,b)}]].push_back(i);
        }
        else used[{min(c,b),max(c,b)}]=i;
    }
    dfs(1,0,0);
    ml();
    for(int i=1;i<=n;i++){
        if(sz(col[i])){
            int lc=col[i][0];
            val[col[i][0]]++;
            for(int j=1;j<sz(col[i]);j++){
                val[col[i][j]]++;
                lc=lca(lc,col[i][j]);
            }
            val[lc]-=sz(col[i]);
        }
    }
    dfsans(1,0);
    printf("%d\n",ans);
    return 0;
}