#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int val[MAXN];
int maxdep[MAXN];
pii ans[MAXN];
pii best={0,-1};
int lift[18][MAXN];
int n,m;
void dfs(int loc, int parent, int depth){
    if(depth>=best.first)best={depth,loc};
    lift[0][loc]=parent;
    maxdep[loc]=1;
    for(int x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc,depth+1);
            maxdep[loc]=max(maxdep[loc],maxdep[x]+1);
        }
    }
}
void ml(){
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++)lift[i][j]=lift[i-1][lift[i-1][j]];
    }
}
int up(int loc, int am){
    for(int i=0;i<=17;i++){
        if(am&(1<<i))loc=lift[i][loc];
    }
    return loc;
}
set<int> values;
pii deq[MAXN];
int l=0,r=-1;
void dfsans(int loc, int parent, int depth){
    if(parent) {
        int toch = depth-1-maxdep[parent]+1;
        int last=depth-maxdep[loc];
        for(int i=toch;i<=last;i++){
            while(l<=r&&deq[l].first<=i)l++;
            if(l>r||deq[l].first-deq[l].second>i){
                values.insert(val[up(loc,depth-i)]);
            }
        }
    }
    if(depth>ans[loc].second){
        ans[loc]={sz(values),depth};
    }
    pii madep[2];
    madep[0]={0,-1};
    madep[1]={0,-1};
    for(int x:matrix[loc]){
        if(x!=parent){

        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for(int i=1;i<=n;i++)cin>>val[i];
    dfs(1,0,0);
    int oneside=best.second;
    best={0,-1};
    dfs(oneside,0,0);
    int othside=best.second;
    values.clear();
    ml();
    dfsans(oneside,0,0);
    dfs(othside,0,0);
    values.clear();
    ml();
    dfsans(othside,0,0);
    return 0;
}