#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
struct sam{
    struct node{
        int link,len;
        pii id;
        int to[26];
        node(int l=0,pii i={-1,-1}){
            len=l,link=-1,id=i;
            fill(to,to+26,-1);
        }
    };
    vector<node> t;
    sam(){
        t={node()};
    }
    int add(char ch, int last, pii id){//there will exist empty nodes "len==t[link].len"
        int cur=sz(t),p=last,c=ch-'a';
        t.push_back(node(t[p].len+1,id));
        for(;p!=-1&&t[p].to[c]==-1;p=t[p].link)t[p].to[c]=cur;
        if(p==-1)t[cur].link=0;
        else{
            int oth=t[p].to[c];
            if(t[oth].len==t[p].len+1)t[cur].link=oth;
            else{
                int clone=sz(t);
                t.push_back(node(t[p].len+1));
                t[clone].link=t[oth].link;
                copy(t[oth].to,t[oth].to+26,t[clone].to);
                t[oth].link=t[cur].link=clone;
                for(;p!=-1&&t[p].to[c]==oth;p=t[p].link)t[p].to[c]=clone;
            }
        }
        return cur;
    }
    void clear(){
        t=vector<node>();
    }
}solver;
vector<int> par,depth,sts;
vector<pii> rep;
vector<vector<int>> adj;
vector<int> st,en;
int type[MN],et,m;
vector<int> bit;
vector<int> relatednodes[MN];
int qnode[MN];
void update(int loc, int val){
    for(;loc<=m;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int dfssts(int loc){
    sts[loc]=1;
    depth[loc]=depth[par[loc]]+1;
    for(auto x:adj[loc])sts[loc]+=dfssts(x);
    sort(adj[loc].begin(),adj[loc].end(),[&](const auto &lhs, const auto &rhs){
        return sts[lhs]>sts[rhs];
    });
    return sts[loc];
}
void dfs(int loc, pii r){
    rep[loc]=r;
    st[loc]=et++;
    for(auto x:adj[loc])dfs(x,(x==adj[loc][0]?r:pii{x,depth[x]}));
    en[loc]=et-1;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
int getlca(int a, int b){
    while(rep[a].first!=rep[b].first){
        if(rep[a].second<rep[b].second)swap(a,b);
        a=par[rep[a].first];
    }
    return mh(a,b);
}
string arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n;
    string a;
    solver.t.reserve(4e6+10);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>type[i];
        if(type[i]==1){
            type[i]=-1;
            cin>>a;
            int last=0;
            for(int j=0;j<sz(a);j++)last=solver.add(a[j],last,{i,j});
        }
        else cin>>type[i];
    }
    m=sz(solver.t);
    par.resize(m);
    for(int i=1;i<=n;i++){
        int cur=0;
        for(int j=0;j<sz(arr[i]);j++){
            if(solver.t[cur].to[arr[i][j]-'a']==-1){
                cur=-1;
                break;
            }
            cur=solver.t[cur].to[arr[i][j]-'a'];
        }
        qnode[i]=cur;
    }
    for(int i=1;i<m;i++){
        relatednodes[solver.t[i].id.first].push_back(i);
        par[i]=solver.t[i].link;
    }
    solver.clear();
    st.resize(m),en.resize(m),bit.resize(m+1),rep.resize(m),depth.resize(m),sts.resize(m),adj.resize(m);
    for(int i=1;i<m;i++){
        adj[par[i]].push_back(i);
    }
    et=1;
    dfssts(0),dfs(0,{0,depth[0]});
    for(int i=1;i<=q;i++){
        if(type[i]==-1){
            sort(relatednodes[i].begin(),relatednodes[i].end(),[&](const auto &lhs, const auto &rhs){
                return st[lhs]<st[rhs];
            });
            update(st[relatednodes[i][0]],1);
            for(int j=1;j<sz(relatednodes[i]);j++){
                update(st[relatednodes[i][j]],1);
                int te=getlca(relatednodes[i][j],relatednodes[i][j-1]);
                update(st[te],-1);
            }
        }
        else{
            if(qnode[type[i]]==-1)printf("0\n");
            else printf("%d\n",query(en[qnode[type[i]]])-query(st[qnode[type[i]]]-1));
        }
    }
    return 0;
}