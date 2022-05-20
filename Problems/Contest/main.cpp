#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=15e4+2;
int arr[MN];
vector<pii> adj[MN];
int sts[MN];
bool cent[MN];
int parent[MN];
int dist[MN][18];
int dptr[MN];
vector<pair<int,ll>> psa[MN];
int childcnt[MN][18];
int cptr[MN];
vector<vector<pair<int,ll>>> psach;
int dfssts(int loc, int p){
    sts[loc]=1;
    for(auto x:adj[loc])if(x.first!=p&&!cent[x.first])sts[loc]+=dfssts(x.first,loc);
    return sts[loc];
}
int findcent(int loc, int p, int hfsz){
    for(auto x:adj[loc])if(x.first!=p&&!cent[x.first]&&sts[x.first]>hfsz)return findcent(x.first,loc,hfsz);
    return loc;
}
void dfs(int loc, int p, int curcent, int cc, int depth){
    dist[loc][dptr[loc]++]=depth;
    childcnt[loc][cptr[loc]++]=cc;
    psach.back().push_back({arr[loc],depth});
    psa[curcent].push_back({arr[loc],depth});
    for(auto x:adj[loc])if(x.first!=p&&!cent[x.first])dfs(x.first,loc,curcent,cc,depth+x.second);
}
void decomp(int loc, int p){
    int cur=findcent(loc,-1,dfssts(loc,-1)/2);
    parent[cur]=p;
    cent[cur]=true;
    dist[cur][dptr[cur]++]=0;
    psa[cur].push_back({arr[cur],0});
    for(auto x:adj[cur]){
        if(!cent[x.first]){
            psach.push_back({});
            dfs(x.first,cur,cur,sz(psach)-1,x.second);
            sort(psach.back().begin(),psach.back().end());
            for(int i=1;i<sz(psach.back());i++)psach.back()[i].second+=psach.back()[i-1].second;
        }
    }
    sort(psa[cur].begin(),psa[cur].end());
    for(int i=1;i<sz(psa[cur]);i++)psa[cur][i].second+=psa[cur][i-1].second;
    for(auto x:adj[cur]){
        if(!cent[x.first]){
            decomp(x.first,cur);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b,c;
    ll mod;
    cin>>n>>q>>mod;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    decomp(1,0);
    ll lastans=0;
    while(q--){
        cin>>a>>b>>c;
        int l=min((b+lastans)%mod,(c+lastans)%mod);
        int r=max((b+lastans)%mod,(c+lastans)%mod);
        lastans=0;
        int cur=a;
        int ptr=dptr[a]-1;
        while(cur!=0){
            int ri=lower_bound(psa[cur].begin(),psa[cur].end(),pair<int,ll>{r+1,-1})-psa[cur].begin()-1;
            int le=lower_bound(psa[cur].begin(),psa[cur].end(),pair<int,ll>{l,-1})-psa[cur].begin()-1;
            lastans+=(ri-le)*ll(dist[a][ptr]);
            lastans+=(ri==-1?ll(0):psa[cur][ri].second)-(le==-1?ll(0):psa[cur][le].second);
            if(a!=cur) {
                int ind = childcnt[a][ptr];
                ri = lower_bound(psach[ind].begin(), psach[ind].end(), pair<int, ll>{r + 1, -1}) - psach[ind].begin() - 1;
                le = lower_bound(psach[ind].begin(), psach[ind].end(), pair<int, ll>{l, -1}) - psach[ind].begin() - 1;
                lastans -= (ri - le) * ll(dist[a][ptr]);
                lastans -= (ri == -1 ? ll(0) : psach[ind][ri].second) - (le == -1 ? ll(0) : psach[ind][le].second);
            }
            cur=parent[cur];
            ptr--;
        }
        printf("%lli\n",lastans);
    }
    return 0;
}