#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int n,m,k,q;
vector<int> omatrix[MAXN];
vector<pair<int,pll>> matrix[2*MAXN];
bool done[MAXN];
int odepth[MAXN],oparent[MAXN];
pll cycind[MAXN];
void dfsh(int loc, int par, int dep){
    odepth[loc]=dep;
    oparent[loc]=par;
    for(auto x:omatrix[loc])if(x!=par)dfsh(x,loc,dep+1);
}
int depth[2*MAXN];
ll dist[2*MAXN];
int lcasparse[20][4*MAXN];
int chsparse[20][4*MAXN];
int lcast[2*MAXN];
int chst[2*MAXN];
int lcaind=0,chind=0;
ll val[MAXN];
ll psa[2*MAXN];
void dfstree(int loc, int dis, int dep){
    lcast[loc]=lcaind,chst[loc]=chind;
    lcasparse[0][lcaind++]=loc,chsparse[0][chind++]=loc;
    depth[loc]=dep;
    dist[loc]=dis;
    for(auto x:matrix[loc]){
        dfstree(x.first,dist[loc]+x.second.first,dep+1);
        lcasparse[0][lcaind++]=loc;
    }
}
ll dfsans(int loc){
    ll curval=psa[loc];
    for(auto x:matrix[loc]){
        ll te=dfsans(x.first);
        if(loc>n)val[loc-n]+=te*(x.second.second-x.second.first);
        curval+=te;
    }
    return curval;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=lcaind;j++){
            lcasparse[i][j]=mh(lcasparse[i-1][j],lcasparse[i-1][j+(1<<(i-1))]);
        }
        for(int j=0;j+(1<<i)<=chind;j++){
            chsparse[i][j]=mh(chsparse[i-1][j],chsparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=lcast[a],b=lcast[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(lcasparse[k][a],lcasparse[k][b-(1<<k)+1]);
}
int getch(int a, int b){
    a=chst[a],b=chst[b];
    a++;
    assert(a<=b);
    int k=log2(b-a+1);
    return mh(chsparse[k][a],chsparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k>>q;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        omatrix[a].push_back(b);
        omatrix[b].push_back(a);
    }
    dfsh(1,0,1);
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        int ate=a,bte=b;
        vector<pii> nodes;
        bool swapped=false;
        while(ate!=bte){
            if(odepth[ate]<odepth[bte])swap(ate,bte),swapped^=1;
            nodes.push_back({ate,swapped});
            done[ate]=true;
            ate=oparent[ate];
        }
        int lca=ate;
        matrix[lca].push_back({i+n,{0,0}});
        for(auto x:nodes){
            int curdist=odepth[x.first]-odepth[lca];
            int othdist=odepth[a]-odepth[x.first]+1+odepth[b]-odepth[lca];
            matrix[i+n].push_back({x.first,{curdist,min(curdist,othdist)}});
            if(x.second)cycind[x.first]={odepth[a]-odepth[lca]+odepth[x.first]-odepth[lca],sz(nodes)+1};
            else cycind[x.first]={odepth[a]-odepth[x.first],sz(nodes)+1};
        }
    }
    for(int i=1;i<=n;i++){
        if(!done[i])matrix[oparent[i]].push_back({i,{1,1}});
    }
    dfstree(1,0,1);
    ms();
    ll ans=0;
    while(q--){
        cin>>a>>b;
        int lca=getlca(a,b);
        psa[a]++,psa[b]++;
        if(lca>n){
            int ach=getch(lca,a),bch=getch(lca,b);
            psa[ach]--,psa[bch]--;
            ans+=dist[a]+dist[b]-dist[ach]-dist[bch];
            ll olddist=abs(cycind[ach].first-cycind[bch].first);
            ans+=olddist;
            val[lca-n]+=min(olddist,cycind[ach].second-olddist)-olddist;
        }
        else{
            psa[lca]-=2;
            ans+=dist[a]+dist[b]-2*dist[lca];
        }
    }
    dfsans(1);
    sort(val+1,val+1+m);
    for(int i=1;i<=k;i++)ans+=val[i];
    printf("%lli\n",ans);
    return 0;
}