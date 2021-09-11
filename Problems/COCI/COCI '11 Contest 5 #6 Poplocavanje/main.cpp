#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
struct sam{
    struct node{
        int link,len,ind;
        array<int,26> to;
        node(){
            link=-1,len=0,ind=-1;
            fill(to.begin(),to.end(),-1);
        }
    };
    vector<node> t;
    sam(){
        t={node()};
    }
    int addchar(int p, char a, int ind){
        int cur=sz(t);
        t.push_back(node());
        t[cur].len=t[p].len+1,t[cur].ind=ind;
        for(;p!=-1&&t[p].to[a-'a']==-1;p=t[p].link)t[p].to[a-'a']=cur;
        if(p==-1)t[cur].link=0;
        else{
            int oth=t[p].to[a-'a'];
            if(t[oth].len==t[p].len+1)t[cur].link=oth;
            else{
                int clone=sz(t);
                t.push_back(node());
                t[clone].to=t[oth].to,t[clone].link=t[oth].link;
                t[clone].len=t[p].len+1;
                t[cur].link=t[oth].link=clone;
                for(;p!=-1&&t[p].to[a-'a']==oth;p=t[p].link)t[p].to[a-'a']=clone;
            }
        }
        return cur;
    }
}solver;
int maxlen[2*MN];
vector<int> adj[2*MN];
int psa[MN];
void dfs(int loc){
    if(solver.t[loc].ind!=-1){
        psa[solver.t[loc].ind-maxlen[loc]+1]++;
        psa[solver.t[loc].ind+1]--;
    }
    for(auto x:adj[loc]){
        maxlen[x]=max(maxlen[x],maxlen[loc]);
        dfs(x);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    string a;
    cin>>n>>a;
    int last=0;
    for(int i=0;i<n;i++)last=solver.addchar(last,a[i],i);
    cin>>m;
    while(m--){
        cin>>a;
        int cur=0;
        for(auto x:a){
            cur=solver.t[cur].to[x-'a'];
            if(cur==-1)break;
        }
        if(cur!=-1)maxlen[cur]=max(maxlen[cur],sz(a));
    }
    for(int i=1;i<sz(solver.t);i++)adj[solver.t[i].link].push_back(i);
    dfs(0);
    int am=!psa[0];
    for(int i=1;i<n;i++){
        psa[i]+=psa[i-1];
        am+=!psa[i];
    }
    printf("%d\n",am);
    return 0;
}