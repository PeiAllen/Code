#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e6+20;
const ll mod=1e9+7;
vector<pair<int,ll>> adj[MN];
int indeg[MN];
vector<ll> poss[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n,k;
        cin>>n>>k;
        unordered_map<int,pair<vector<pair<ll,int>>,vector<pair<ll,int>>>> vendors;
        int a,b;
        ll x,y;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>x>>y;
            vendors[a].first.push_back({x,i});
            vendors[b].second.push_back({y,i});
        }
        int nextnode=n+1;
        for(auto x:vendors){
            vector<pair<ll,int>> buyers=x.second.first;
            vector<pair<ll,int>> sellers=x.second.second;
            sort(buyers.begin(),buyers.end()),sort(sellers.begin(),sellers.end());
            int firstnode=nextnode;
            for(int i=0;i<sz(buyers);i++){
                adj[nextnode].push_back({buyers[i].second,buyers[i].first});
                indeg[buyers[i].second]++;
                if(i>=1){
                    adj[nextnode-1].push_back({nextnode,0});
                    indeg[nextnode]++;
                }
                nextnode++;
            }
            int ptr=0;
            for(int i=0;i<sz(sellers);i++){
                while(ptr<sz(buyers)&&buyers[ptr].first<=sellers[i].first){
                    ptr++;
                }
                if(ptr<sz(buyers)){
                    adj[sellers[i].second].push_back({firstnode+ptr,-sellers[i].first});
                    indeg[firstnode+ptr]++;
                }
            }
        }
        vector<int> nodeorder;
        queue<int> q;
        for(int i=1;i<nextnode;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            nodeorder.push_back(cur);
            for(auto x:adj[cur]){
                indeg[x.first]--;
                if(indeg[x.first]==0){
                    q.push(x.first);
                }
            }
        }
        vector<ll> final;
        for(int i=sz(nodeorder)-1;i>=0;i--){
            int node=nodeorder[i];
            vector<ll> te;
            if(node<=n)te.push_back(0);
            for(auto x:adj[node]){
                for(auto y:poss[x.first]){
                    te.push_back(x.second+y);
                }
            }
            sort(te.begin(),te.end(),greater<>());
            if(sz(te)>k)te.resize(k);
            poss[node]=te;
            if(node<=n){
                for(auto x:poss[node]){
                    final.push_back(x);
                }
            }
        }
        sort(final.begin(),final.end(),greater<>());
        ll ans=0;
        for(int i=0;i<min(k,sz(final));i++){
            ans+=final[i]%mod;
        }
        printf("Case #%d: %lli\n",cs,ans%mod);
        for(int i=0;i<nextnode;i++){
            adj[i]=vector<pair<int,ll>>();
            poss[i]=vector<ll>();
            indeg[i]=0;
        }
    }
    return 0;
}
