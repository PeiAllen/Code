#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
int stl[MN],stc[MN],depth[MN];
int sparsel[19][2*MN],sparsec[18][MN];
ll psa[MN];
ll ans=0;
int etlcnt=0,etccnt=0;
map<pii,ll> cnt;
ll query[MN];
void makeet(int loc, int parent){
    stl[loc]=etlcnt,sparsel[0][etlcnt++]=loc,stc[loc]=etccnt,sparsec[0][etccnt++]=loc,depth[loc]=depth[parent]+1;
    for(auto x:adj[loc])if(x!=parent)makeet(x,loc),sparsel[0][etlcnt++]=loc;
}
int md(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<19;i++){
        for(int j=0;j+(1<<i)<=etlcnt;j++){
            sparsel[i][j]=md(sparsel[i-1][j],sparsel[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1;i<18;i++){
        for(int j=0;j+(1<<i)<=etccnt;j++){
            sparsec[i][j]=md(sparsec[i-1][j],sparsec[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=stl[a],b=stl[b];
    if(b<a)swap(a,b);
    int k=log2(b-a+1);
    return md(sparsel[k][a],sparsel[k][b-(1<<k)+1]);
}
int getc(int p, int c){
    if(p==c)return -1;
    p=stc[p]+1,c=stc[c];
    int k=log2(c-p+1);
    return md(sparsec[k][p],sparsec[k][c-(1<<k)+1]);
}
void dfs(int loc, int parent){
    for(auto x:adj[loc])if(x!=parent)dfs(x,loc),psa[loc]+=psa[x];
    ans+=query[loc]*(psa[loc]-1),ans-=query[loc]*(query[loc]-1)/2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    makeet(1,0),ms();
    for(int i=n;i<=m;i++){
        cin>>a>>b;
        int lca=getlca(a,b);
        int ac=getc(lca,a),bc=getc(lca,b);
        if(ac!=-1)psa[a]++,psa[lca]--,query[ac]++;
        if(bc!=-1)psa[b]++,psa[lca]--,query[bc]++;
        if(ac!=-1&&bc!=-1)cnt[{min(ac,bc),max(ac,bc)}]++;
    }
    dfs(1,0);
    for(auto x:cnt)ans-=x.second*(x.second-1)/2;
    printf("%lli\n",ans);
    return 0;
}