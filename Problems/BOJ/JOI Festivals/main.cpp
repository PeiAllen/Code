#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll dist[MN];
vector<pair<int,ll>> adj[MN];
pii dsu[MN];
vector<pair<pii,pair<pii,pii>>> his;
int find(int a){
    if(dsu[a].first==a)return a;
    return find(dsu[a].first);
}
void undo(){
    auto cur=his.back();
    his.pop_back();
    if(cur.first.first==-1)return;
    dsu[cur.first.first]=cur.second.first;
    dsu[cur.first.second]=cur.second.second;
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp){
        his.push_back({{-1,-1},{}});
        return false;
    }
    his.push_back({{ap,bp},{dsu[ap],dsu[bp]}});
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
ll ans[MN];
void cdq(ll l, ll r, const vector<int>& nodes, const vector<pair<pii,int>>& queries){
    if(sz(queries)==0)return;
    if(l==r){
        for(auto x:queries)ans[x.second]=l;
        return;
    }
    ll mid=(l+r)/2;
    vector<int> leftn,rightn;
    vector<pair<pii,int>> leftq,rightq;
    int cnt=0;
    for(auto x:nodes){
        if(dist[x]>mid){
            rightn.push_back(x);
            for(auto y:adj[x])if(pair<ll,int>{dist[y.first],y.first}>pair<ll,int>{dist[x],x}){
                uni(y.first,x);
                cnt++;
            }
        }
        else leftn.push_back(x);
    }
    for(auto x:queries){
        if(find(x.first.first)==find(x.first.second))rightq.push_back(x);
        else leftq.push_back(x);
    }
    cdq(l,mid,leftn,leftq);
    while(cnt--)undo();
    cdq(mid+1,r,rightn,rightq);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,qu,a,b;
    cin>>n>>m>>k>>qu;
    ll w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int> nodes;
    for(int i=1;i<=n;i++)nodes.push_back(i),dsu[i]={i,1},dist[i]=LLONG_MAX;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    for(int i=0;i<k;i++){
        cin>>a;
        dist[a]=0;
        q.push({0,a});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second])continue;
        for(auto x:adj[cur.second]){
            if(dist[x.first]>cur.first+x.second){
                dist[x.first]=cur.first+x.second;
                q.push({dist[x.first],x.first});
            }
        }
    }
    vector<pair<pii,int>> queries;
    for(int i=0;i<qu;i++){
        cin>>a>>b;
        queries.push_back({{a,b},i});
    }
    cdq(0,MN*1000,nodes,queries);
    for(int i=0;i<qu;i++)printf("%lli\n",ans[i]);
    return 0;
}