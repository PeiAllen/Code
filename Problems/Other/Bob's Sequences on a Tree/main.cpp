#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1,MC=10+1;
struct sam{
    struct node{
        int link,len,to[MC];
        node(int s=0){
            link=-1,len=s;
            fill(to,to+MC,-1);
        }
    };
    vector<node> t;
    sam(){
        t={node()};
    }
    int extend(int c, int last){
        int cur=sz(t);
        t.push_back(node(t[last].len+1));
        int p=last;
        for(;p!=-1&&t[p].to[c]==-1;p=t[p].link)t[p].to[c]=cur;
        if(p==-1) t[cur].link=0;
        else{
            int oth=t[p].to[c];
            if(t[oth].len==t[p].len+1)t[cur].link=oth;
            else{
                int clone=sz(t);
                t.push_back(node(t[p].len+1));
                t[clone].link=t[oth].link;
                for(int i=0;i<MC;i++)t[clone].to[i]=t[oth].to[i];
                t[cur].link=t[oth].link=clone;
                for(;p!=-1&&t[p].to[c]==oth;p=t[p].link)t[p].to[c]=clone;
            }
        }
        return cur;
    }
}solver;
vector<int> adj[MN];
int arr[MN];
void dfs(int loc, int parent, int last){
    int cur=solver.extend(arr[loc],last);
    for(auto x:adj[loc]){
        if(x!=parent)dfs(x,loc,cur);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,c,a,b;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(sz(adj[i])==1){
            dfs(i,-1,0);
        }
    }
    ll ans=0;
    for(int i=1;i<sz(solver.t);i++){
        ans+=solver.t[i].len-solver.t[solver.t[i].link].len;
    }
    printf("%lli\n",ans);
    return 0;
}