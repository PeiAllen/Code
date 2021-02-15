#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll arr[MN];
vector<pair<int,ll>> matrix[MN];
ll dist[MN];
map<ll,ll> trainings;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i],dist[i]=INT_MAX;
    int a,b;
    ll c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    dist[1]=1;
    q.push({1,1});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(dist[cur.second]>=cur.first){
            for(auto x:matrix[cur.second]){
                if(max(cur.first,x.second)<dist[x.first]){
                    dist[x.first]=max(cur.first,x.second);
                    q.push({dist[x.first],x.first});
                }
            }
        }
    }
    if(dist[n]==INT_MAX){
        printf("-1\n");
        return 0;
    }
    if(dist[n]==1){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(trainings.count(dist[i]))trainings[dist[i]]=min(trainings[dist[i]],arr[i]);
        else trainings[dist[i]]=arr[i];
    }
    ll bestslope=trainings[1],cost=0,last=1;
    for(auto x:trainings){
        cost+=bestslope*(x.first-last);
        if(x.first==dist[n]){
            printf("%lli\n",cost);
            return 0;
        }
        bestslope=min(bestslope,x.second),last=x.first;
    }
    return 0;
}