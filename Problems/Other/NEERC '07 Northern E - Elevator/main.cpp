#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll MV=2e18;
ll dist[MN];
vector<ll> adds;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll h,a,b,c;
    cin>>h>>a>>b>>c,h-=1;
    adds.push_back(b),adds.push_back(c);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    for(int i=0;i<a;i++)dist[i]=MV;
    dist[0]=0;
    q.push({0,0});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            for(auto x:adds){
                if(cur.first+x<dist[(cur.second+x)%a]){
                    dist[(cur.second+x)%a]=cur.first+x;
                    q.push({cur.first+x,(cur.second+x)%a});
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<a;i++)ans+=max(ll(0),h/a-dist[i]/a+(i<=h%a));
    printf("%lli\n",ans);
    return 0;
}