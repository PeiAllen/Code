#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2001;
vector<int> matrix[MAXN];
bool use[MAXN];
int dist[MAXN];
int vnode;
void dfs(int loc, int par, int dep){
    dist[loc]=dep;
    vnode++;
    for(int x:matrix[loc]){
        if(x!=par&&use[x])dfs(x,loc,dep+1);
    }
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
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        vector<int> touse;
        for(int j=0;j<n;j++){
            if(i&(1<<j))touse.push_back(j+1),use[j+1]=true;
            else use[j+1]=false;
        }
        if(sz(touse)==1){
            ans++;
            continue;
        }
        vector<pii> roots;
        vector<int> leaves;
        for(int x:touse){
            int deg=0;
            for(int y:matrix[x])if(use[y])deg++;
            if(deg>1)roots.push_back({deg,x});
            else leaves.push_back(x);
        }
        sort(roots.begin(),roots.end());
        if(sz(roots)==0)continue;
        int root=roots.begin()->second;
        vnode=0;
        dfs(root,0,1);
        if(vnode==sz(touse)){
            set<int> vals;
            for(int x:leaves){
                vals.insert(dist[x]);
            }
            if(sz(vals)!=1)continue;
            vals.clear();
            for(auto x:roots){
                vals.insert(x.first-(x.second==root?0:1));
            }
            if(sz(vals)==1&&*vals.begin()>=2)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}