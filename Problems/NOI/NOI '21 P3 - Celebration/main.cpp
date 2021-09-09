#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;

inline int readint() {
    int c, o = 0;
    while ((c = getchar()) < '0');
    do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
    return o;
}
//inline int readint(){
//    int a;
//    cin>>a;
//    return a;
//}
const int MN=3e5+1;
int low[MN],ind[MN];
vector<vector<int>> comps;
int partof[MN];
bool inst[MN];
vector<int> stac;
vector<int> inadj[MN],nadj[MN];
int ord[MN],indeg[MN];
pii dsu[MN];
int pc[2*MN];
vector<int> adj[MN];
vector<pii> fadj[MN];
int n,m,q,k;
int depth[MN],sparse[20][2*MN],st[MN],et,psa[MN],sparsech[19][MN],stch[MN],etch,par[MN],nodecnt[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
void scc(int loc){
    inst[loc]=true;
    stac.push_back(loc);
    low[loc]=ind[loc]=et++;
    for(auto x:adj[loc]){
        if(!low[x])scc(x),low[loc]=min(low[loc],low[x]);
        else if(inst[x])low[loc]=min(low[loc],ind[x]);
    }
    if(low[loc]==ind[loc]){
        comps.push_back({});
        while(1){
            auto cur=stac.back();
            stac.pop_back();
            inst[cur]=false;
            partof[cur]=SZ(comps)-1;
            comps.back().push_back(cur);
            if(cur==loc)break;
        }
    }
}
void dfs(int loc, int parent){
    depth[loc]=depth[parent]+1;
    nodecnt[loc]=nodecnt[parent]+SZ(comps[loc]);
    par[loc]=parent;
    sparse[0][et]=loc;
    sparsech[0][etch]=loc;
    st[loc]=et++;
    stch[loc]=etch++;
    for(auto x:fadj[loc])if(x.first!=parent){
            psa[x.first]=psa[loc]+x.second;
            sparse[0][et++]=loc;
            dfs(x.first,loc);
        }
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1;i<19;i++){
        for(int j=0;j+(1<<i)<=etch;j++){
            sparsech[i][j]=mh(sparsech[i-1][j],sparsech[i-1][j+(1<<(i-1))]);
        }
    }
}
inline int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int p=pc[b-a+1];
    return mh(sparse[p][a],sparse[p][b-(1<<p)+1]);
}
inline int getch(int a, int ances){
    a=stch[a],ances=stch[ances]+1;
    int p=pc[a-ances+1];
    return mh(sparsech[p][ances],sparsech[p][a-(1<<p)+1]);
}
inline int getnodedist(int a, int b){
    int lca=getlca(a,b);
    return depth[a]-depth[lca]+depth[b]-depth[lca]+1;
}
inline int getactdist(int a, int b){
    int lca=getlca(a,b);
    return nodecnt[a]-nodecnt[lca]+nodecnt[b]-nodecnt[lca]+nodecnt[lca]-nodecnt[par[lca]];
}
inline bool canreach(int a, int b){
    int lca=getlca(a,b);
    if(psa[a]-psa[lca]!=-(depth[a]-depth[lca])||psa[b]-psa[lca]!=(depth[b]-depth[lca]))return 0;
    return 1;
}
bitset<6> reach[6];
void solvetree(){
    et=etch=0;
    dfs(1,0),ms();
    int be,en;
    for(int i=0;i<q;i++){
        be=partof[readint()];
        en=partof[readint()];
        vector<pii> edges(k);
        vector<int> nodes(2+2*k);
        for(int j=0;j<SZ(nodes);j++)for(int l=0;l<SZ(nodes);l++)reach[j][l]=false;
        nodes[0]=be,nodes[1]=en;
        for(int j=0;j<k;j++){
            edges[j].first=partof[readint()];
            edges[j].second=partof[readint()];
            nodes[(j+1)*2]=edges[j].first;
            nodes[(j+1)*2+1]=edges[j].second;
            reach[(j+1)*2][(j+1)*2+1]=true;
        }
        for(int j=0;j<SZ(nodes);j++)for(int l=0;l<SZ(nodes);l++){
                if(j==l||canreach(nodes[j],nodes[l]))reach[j][l]=true;
            }
        for(int mid=0;mid<SZ(nodes);mid++){
            for(int stn=0;stn<SZ(nodes);stn++){
                if(reach[stn][mid]){
                    reach[stn]|=reach[mid];
                }
            }
        }
        vector<pii> paths;
        for(int j=0;j<SZ(nodes);j++){
            if(reach[0][j])for(int j2=0;j2<SZ(nodes);j2++){
                    if(j!=j2&&reach[j2][1]&&canreach(nodes[j],nodes[j2])){
                        paths.push_back({nodes[j],nodes[j2]});
                    }
                }
        }
        sort(paths.begin(),paths.end(),[&](const auto &lhs, const auto& rhs){
            return getnodedist(lhs.first,lhs.second)>getnodedist(rhs.first,rhs.second);
        });
        int ans=0;
        vector<pii> usedpaths;
        for(auto x:paths){
            vector<vector<pii>> addedpaths(2,vector<pii>());
            int xlca=getlca(x.first,x.second);
            if(x.first==xlca)addedpaths[0].push_back({x.second,x.first});
            else if(x.second==xlca)addedpaths[0].push_back(x);
            else addedpaths[0].push_back({x.first,xlca}),addedpaths[0].push_back({x.second,getch(x.second,xlca)});
            vector<pii> te=addedpaths[0];
            int cur=1;
            for(auto y:usedpaths){
                addedpaths[cur]=vector<pii>();
                for(auto z:addedpaths[!cur]){
                    if(depth[z.second]<depth[y.second]){
                        if(getlca(z.first,y.second)==y.second){
                            int stoppoint=getlca(z.first,y.first);
                            addedpaths[cur].push_back({par[y.second],z.second});
                            if(z.first!=stoppoint){
                                addedpaths[cur].push_back({z.first,getch(z.first,stoppoint)});
                            }
                        }
                        else addedpaths[cur].push_back(z);
                    }
                    else{
                        if(getlca(z.second,y.first)==z.second){
                            int stoppoint=getlca(z.first,y.first);
                            if(z.first!=stoppoint){
                                addedpaths[cur].push_back({z.first,getch(z.first,stoppoint)});
                            }
                        }
                        else addedpaths[cur].push_back(z);
                    }
                }
                cur=!cur;
            }
            for(auto y:addedpaths[!cur])ans+=getactdist(y.first,y.second);
            for(auto y:te)usedpaths.push_back(y);
        }
        printf("%d\n",ans);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    freopen("celebration3.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int a,b;
    n=readint();
    m=readint();
    q=readint();
    k=readint();
    for(int i=1;i<2*MN;i++)pc[i]=__lg(i);
    for(int i=0;i<m;i++){
        a=readint(),b=readint();
        adj[a].push_back(b);
    }
    comps.push_back({});
    et=1;
    for(int i=1;i<=n;i++)if(!ind[i])scc(i);
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            if(partof[x]!=partof[i])inadj[partof[x]].push_back(partof[i]),nadj[partof[i]].push_back(partof[x]),indeg[partof[x]]++;
        }
    }
    queue<int> qu;
    for(int i=1;i<SZ(comps);i++){
        adj[i]=vector<int>();
        dsu[i]={i,1};
        if(indeg[i]==0)qu.push(i);
    }
    int cnt=0;
    while(SZ(qu)){
        auto cur=qu.front();
        qu.pop();
        sort(inadj[cur].begin(),inadj[cur].end(),[&](const auto &lhs, const auto &rhs){
           return ord[lhs]>ord[rhs];
        });
        ord[cur]=cnt++;
        for(auto x:inadj[cur]){
            if(uni(x,cur)){
                adj[x].push_back(cur);
                fadj[x].push_back({cur,1});
                fadj[cur].push_back({x,-1});
            }
        }
        for(auto x:nadj[cur]){
            if((--indeg[x])==0)qu.push(x);
        }
    }
    n=SZ(comps)-1;
    solvetree();
    return 0;
}