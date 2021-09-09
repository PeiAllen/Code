#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=1e3+1;
unordered_map<int,ll> dp[MN];
ll depth[MN];
vector<pair<int,pll>> adj[MN];
int who[MN];
bool gone[MN];
int n,m,a,b,c,d;
ll k,longest;
void dfs(int loc, int parent){
    gone[loc]=true;
    who[loc]=loc;
    dp[loc]=unordered_map<int,ll>();
    dp[loc][loc]=0;
    for(auto x:adj[loc])if(x.A!=parent){
        depth[x.A]=depth[loc]+x.B.A;
        dfs(x.A,loc);
        for(auto y:dp[x.A]){
            if(depth[y.A]-depth[loc]<=longest)dp[loc][y.A]=0,who[y.A]=x.A;
        }
    }
    for(auto x:adj[loc])if(x.A!=parent){
        for(auto &&y:dp[loc]){
            if(who[y.A]==x.A){
                y.B+=dp[x.A][y.A];
            }
            else {
                ll best=LLONG_MAX;
                for (auto z: dp[x.A]) {
                    if(depth[z.A]-depth[loc]+depth[y.A]-depth[loc]<=longest&&depth[z.A]-depth[loc]<=depth[y.A]-depth[loc])best=min(best,z.B);
                    best=min(best,z.B+x.B.B);
                }
                y.B+=best;
            }
        }
    }
}
bool work(ll maxlen){
    longest=maxlen;
    fill(gone,gone+n+1,false);
    ll needed=0;
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            dfs(i,0);
            needed+=min_element(dp[i].begin(),dp[i].end(),[&](const auto &first, const auto &smallest){
                return first.B<smallest.B;
            })->B;
        }
    }
    return needed<=k;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        adj[a].push_back({b,{c,d}});
        adj[b].push_back({a,{c,d}});
    }
    ll lo=0,hi=1e12;
    while(lo!=hi){
        ll mid=(lo+hi)/2;
        if(work(mid))hi=mid;
        else lo=mid+1;
    }
    printf("%lli\n",lo);
    return 0;
}