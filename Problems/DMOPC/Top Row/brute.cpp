#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
struct sam{
    struct node{
        int sufind,len,link;
        int to[26];
        node(int l, int i){
            len=l,sufind=i;
            link=-1;
            for(int j=0;j<26;j++)to[j]=-1;
        }
    };
    vector<node> t;
    int last;
    sam(){
        last=0;
        t={node(0,-1)};
    }
    void add(char x, int ind){
        int cur=sz(t),charval=x-'a';
        t.push_back(node(t[last].len+1,ind));
        int from=last;
        while(from!=-1&&t[from].to[charval]==-1)t[from].to[charval]=cur,from=t[from].link;
        if(from==-1)t[cur].link=0;
        else{
            int plink=t[from].to[charval];
            if(t[plink].len==t[from].len+1)t[cur].link=plink;
            else{
                int clone=sz(t);
                t.push_back(node(t[from].len+1,-1));
                for(int i=0;i<26;i++)t[clone].to[i]=t[plink].to[i];
                t[clone].link=t[plink].link;
                t[plink].link=t[cur].link=clone;
                while(from!=-1&&t[from].to[charval]==plink)t[from].to[charval]=clone,from=t[from].link;
            }
        }
        last=cur;
    }
}solver;
int st[2*MN],sparse[20][4*MN],et,samind[MN],depth[2*MN],parent[MN];
vector<int> adj[2*MN];
ll psa[MN];
void dfs(int loc, int dep){
    st[loc]=et;
    sparse[0][et++]=loc;
    depth[loc]=dep;
    for(auto x:adj[loc]){
        dfs(x,dep+1);
        sparse[0][et++]=loc;
    }
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
int mah(int a, int b){
    if(depth[a]>depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){//subtask 1,2
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=1;i<=sz(s);i++)solver.add(s[i-1],i);
    for(int i=0;i<sz(solver.t);i++){
        if(solver.t[i].sufind!=-1)samind[solver.t[i].sufind]=i;
        if(solver.t[i].link!=-1)adj[solver.t[i].link].push_back(i);
    }
    for(int i=1;i<=sz(s);i++)psa[i]=psa[i-1]+(i+1);
    dfs(0,0),ms();
    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a>>b;
        set<int> goneto;
        ll ans=0;
        for(int i=b;i>=a;i--){
            int ind=samind[i];
            auto it=goneto.lower_bound(st[ind]);
            int loc=0;
            if(it!=goneto.end())loc=mah(loc,getlca(ind,sparse[0][*it]));
            if(it!=goneto.begin())loc=mah(loc,getlca(ind,sparse[0][*prev(it,1)]));
            if(i-a+1>=solver.t[loc].len+1)ans+=psa[i-a+1]-psa[solver.t[loc].len];
            goneto.insert(st[ind]);
        }
        printf("%lli\n",ans);
    }
    return 0;
}