#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=998244352;
const int MN=3e3+1;
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[bp].first=ap;
    dsu[ap].second+=dsu[bp].second;
    return true;
}
vector<int> adj[MN];
vector<pii> edges;
ll dp[(1<<21)];
pii to[(1<<21)][21];
ll fact[MN];
int n;
ll solve(int a){
    if(__builtin_popcount(a)<=1)return 1;
    if(dp[a]!=-1)return dp[a];
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(a&(1<<i)){
            ans=(ans+solve(to[a][i].first)*solve(to[a][i].second)%mod)%mod;
        }
    }
    return dp[a]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>n>>k;
    k=n-1-k;
    edges.resize(n-1);
    fact[0]=1;
    for(int i=1;i<=n-1;i++)if(i>0)fact[i]=fact[i-1]*ll(i)%mod;
    for(int i=0;i<n-1;i++){
        cin>>edges[i].first>>edges[i].second;
    }
    ll ans=0;
    for(int i=0;i<(1<<(n-1));i++){
        dp[i]=-1;
        for(int j=0;j<n-1;j++){
            if(i&(1<<j)){
                for(int l=1;l<=n;l++)dsu[l]={l,1};
                for(int l=0;l<n-1;l++){
                    if(i&(1<<l)){
                        if(l!=j){
                            uni(edges[l].first,edges[l].second);
                        }
                    }
                }
                int left=0,right=0;
                for(int l=0;l<n-1;l++){
                    if(i&(1<<l)) {
                        if (l == j)continue;
                        if (find(edges[l].first) == find(edges[l].second) && find(edges[l].first) == find(edges[j].first))left += (1 << l);
                        else if (find(edges[l].first) == find(edges[l].second) && find(edges[l].first) == find(edges[j].second))right += (1 << l);
                    }
                }
                to[i][j]={left,right};
            }
        }
    }
    for(int i=0;i<(1<<(n-1));i++){
        if(__builtin_popcount(i)!=k)continue;
        for(int j=1;j<=n;j++)dsu[j]={j,1};
        for(int j=0;j<n-1;j++){
            if(!(i&(1<<j))){
                uni(edges[j].first,edges[j].second);
            }
        }
        ll cur=1;
        map<int,int> teedges;
        for(int l=0;l<n-1;l++){
            if(!(i&(1<<l)))teedges[find(edges[l].first)]+=(1<<l);
        }
        for(auto x:teedges){
            cur=cur*solve(x.second)%mod;
        }
        ans=(ans+cur)%mod;
    }
    printf("%lli\n",ans);
    return 0;
}