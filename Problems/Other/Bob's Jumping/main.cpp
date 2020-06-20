#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pair<int,ll>> matrix[MAXN];
ll height[MAXN];
ll dist[MAXN];
ll dist2[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    ll oh;
    cin>>n>>m>>oh;
    for(int i=1;i<=n;i++){
        cin>>height[i];
        dist[i]=LLONG_MAX;
        dist2[i]=LLONG_MAX;
    }
    int a,b;
    ll t;
    for(int i=0;i<m;i++){
        cin>>a>>b>>t;
        matrix[a].push_back({b,t});
        matrix[b].push_back({a,t});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    dist[n]=0;
    q.push({0,n});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            for(auto x:matrix[cur.second]){
                if(dist[x.first]>cur.first+x.second&&x.second<=height[x.first]){
                    dist[x.first]=cur.first+x.second;
                    q.push({dist[x.first],x.first});
                }
            }
        }
    }
    ll ans=LLONG_MAX;
    dist2[1]=0;
    q.push({0,1});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist2[cur.second]){
            if(cur.second==n){
                ans=min(ans,cur.first+height[n]-(oh-cur.first));
                continue;
            }
            for(auto x:matrix[cur.second]){
                if(x.second+cur.first<=oh){
                    ll add=max((ll)0,oh-(cur.first+x.second)-height[x.first]);
                    if(dist2[x.first]>add+cur.first+x.second){
                        dist2[x.first]=add+cur.first+x.second;
                        q.push({dist2[x.first],x.first});
                    }
                }
                else if(dist[x.first]!=LLONG_MAX&&height[cur.second]>=x.second){
                    ans=min(ans,dist[x.first]*2+height[n]+cur.first+x.second+x.second-(oh-cur.first));
                }
            }
        }
    }
    if(ans==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}