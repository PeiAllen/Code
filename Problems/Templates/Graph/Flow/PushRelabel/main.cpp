#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct PushRelabel{
    int V;
    struct Edge{
        ll c;
        int ind,to;
        Edge(int to,ll c, int ind):to(to),c(c),ind(ind){}
    };
    vector<vector<Edge>> G;
    PushRelabel(int V):V(V),G(V+1){}
    void addedge(int a, int b, ll f){
        if(a==b||!f)return;
        G[a].push_back(Edge(b,f,sz(G[b])));
        G[b].push_back(Edge(a,0,sz(G[a])-1));
    }
    ll maxFlow(int s, int t){
        if(s==t)return LLONG_MAX;
        vector<int> d(V+1,V),ptr(V+1,0),am(V,0);
        vector<vector<int>> active(V+1);
        vector<ll> ex(V+1,0);
        int bq[V+1];
        int bql=0,bqr=-1;
        d[t]=0,bq[++bqr]=t;
        while(bqr>=bql){
            int cur=bq[bql++];
            for(auto x:G[cur])if(!x.c&&d[x.to]==V)d[x.to]=d[cur]+1,bq[++bqr]=x.to;
        }
        d[s]=V;
        for(int i=0;i<=V;i++)if(d[i]<V)am[d[i]]++;
        ll U=0,maxE=1;
        for(auto &&x:G[s])ex[s]-=x.c,ex[x.to]+=x.c,G[x.to][x.ind].c+=x.c,U=max(U,x.c),x.c=0;
        while(maxE<=U)maxE<<=1;
        for(ll halfE=maxE>>1;halfE;halfE>>=1){
            int curd=1;
            for(int i=0;i<=V;i++)if(ex[i]>=halfE&&d[i]<V&&i!=t)active[d[i]].push_back(i);
            while(curd<V&&am[curd]){
                if(!sz(active[curd]))curd++;
                else {
                    int cur = active[curd].back();
                    while (ptr[cur] < sz(G[cur]) && (d[cur] != d[G[cur][ptr[cur]].to] + 1 || G[cur][ptr[cur]].c == 0))ptr[cur]++;
                    if (ptr[cur] == sz(G[cur])) {
                        am[d[cur]]--,active[d[cur]].pop_back(), d[cur] = INT_MAX, ptr[cur] = 0;
                        for (auto &&x:G[cur])if(x.c&&d[x.to] + 1<d[cur])d[cur] = d[x.to] + 1;
                        if(d[cur]<V)active[d[cur]].push_back(cur),am[d[cur]]++;
                    }
                    else {
                        Edge &e = G[cur][ptr[cur]];
                        ll flow = min({ex[cur], e.c});
                        ex[cur] -= flow, ex[e.to] += flow, e.c -= flow, G[e.to][e.ind].c += flow;
                        if (ex[cur]<halfE)active[d[cur]].pop_back();
                        if (e.to != t && ex[e.to] >= halfE)active[d[e.to]].push_back(e.to),curd-=1;
                    }
                }
            }
            for(int i=curd+1;i<V;i++)active[i]=vector<int>();
        }
        return ex[t];
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    PushRelabel flow(n);
    int a,b;
    ll c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        flow.addedge(a,b,c);
    }
    printf("%lli\n",flow.maxFlow(s,t));
    return 0;
}