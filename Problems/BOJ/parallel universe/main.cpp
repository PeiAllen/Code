#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
const ll mod=1e9+9;
const ll mod2=998244353;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
vector<int> adj[MN];
int dist[2][MN],sts[MN];
set<pair<pll,pll>> trees;
bool nprime[MN];
vector<ll> primes;
void dfs(int loc, int parent, int ind){
    dist[ind][loc]=(parent==-1?0:dist[ind][parent])+1;
    for(auto x:adj[loc])if(x!=parent)dfs(x,loc,ind);
}
pll gethash(int loc, int parent){
    sts[loc]=1;
    pll hsh={1,1};
    for(auto x:adj[loc])if(x!=parent){
        pll te=gethash(x,loc);
        hsh.first=(hsh.first+primes[sts[x]]*te.first%mod)%mod;
        hsh.second=(hsh.second+primes[sts[x]]*te.second%mod2)%mod2;
        sts[loc]+=sts[x];
    }
    return hsh;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,s,a,b;
    cin>>n;
    for(ll i=2;i<MN;i++){
        if(!nprime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<MN;j+=i)nprime[j]=true;
        }
    }
    shuffle(primes.begin(),primes.end(),gen);
    for(int st=0;st<n;st++){
        cin>>s;
        for(int i=0;i<s;i++)adj[i]=vector<int>(),dist[0][i]=0,dist[1][i]=0,sts[i]=0;
        for(int i=1;i<s;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,-1,0);
        a=max_element(dist[0],dist[0]+s)-dist[0];
        dfs(a,-1,0);
        b=max_element(dist[0],dist[0]+s)-dist[0];
        dfs(b,-1,1);
        vector<int> nodes;
        int best=INT_MAX;
        for(int i=0;i<s;i++){
            if(max(dist[0][i],dist[1][i])<best){
                best=max(dist[0][i],dist[1][i]);
                nodes=vector<int>();
            }
            if(max(dist[0][i],dist[1][i])==best)nodes.push_back(i);
        }
        assert(sz(nodes)<=2);
        pair<pll,pll> te={gethash(nodes[0],-1),(sz(nodes)==2?gethash(nodes[1],-1):pll{-1,-1})};
        trees.insert({min(te.first,te.second),max(te.first,te.second)});
    }
    printf("%d\n",sz(trees));
    return 0;
}