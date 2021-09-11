#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll ans[MN];
int psa[MN];
vector<int> adj[4*MN];
struct SAM{
    struct node {
        map<char,int> to;
        int link,len,in;
        bool sp;
        node(int l=0, bool s=1, int i=0){
            to={},link=-1,len=l,sp=s,in=i;
        }
    };
    vector<node> t;
    int last;
    SAM(){
        t={node()};
        last=0;
    }
    void addchar(char c, int in){
        int cur=sz(t);
        t.push_back(node(t[last].len+1,1,in));
        int p=last;
        while(p!=-1&&!t[p].to.count(c))t[p].to[c]=cur,p=t[p].link;
        if(p==-1)t[cur].link=0;
        else{
            int oth=t[p].to[c];
            if(t[oth].len==t[p].len+1)t[cur].link=oth;
            else{
                int clone=sz(t);
                t.push_back(node(t[p].len+1,0));
                t[clone].link=t[oth].link,t[clone].to=t[oth].to;
                t[cur].link=t[oth].link=clone;
                while(p!=-1&&t[p].to[c]==oth)t[p].to[c]=clone,p=t[p].link;
            }
        }
        last=cur;
    }
}solver;
pii dfs(int loc){
    int mi=INT_MAX;
    int locs=-1;
    if(solver.t[loc].sp){
        mi=min(mi,solver.t[loc].len);
        locs=solver.t[loc].in;
    }
    for(auto x:adj[loc]){
        pii te=dfs(x);
        mi=min(mi,te.first);
        if(locs==-1)locs=te.second;
        else if(locs!=te.second)locs=-2;
    }
    if(locs!=-2&&loc!=0)ans[locs]+=max(0,min(mi-psa[locs],solver.t[loc].len)-solver.t[solver.t[loc].link].len);
    return {mi,locs};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(auto x:s)solver.addchar(x,i);
        solver.addchar('$',0);
        psa[i+1]=psa[i]+sz(s)+1;
    }
    for(int i=1;i<sz(solver.t);i++)adj[solver.t[i].link].push_back(i);
    dfs(0);
    for(int i=1;i<=n;i++)printf("%lli\n",ans[i]);
    return 0;
}