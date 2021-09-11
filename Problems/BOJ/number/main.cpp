#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<pll> arr[65];
map<ll,ll> dist;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(__int128 i=2;i<=1e6;i++){
        __int128 val=i*i*i;
        for(int j=3;val<=2e18;j++,val*=i){
            arr[j].push_back({val,i});
        }
    }
    ll a;
    cin>>a;
    priority_queue<pll,vector<pll>,greater<>> q;
    q.push({0,a});
    dist[a]=0;
    auto trydist=[&](const ll &val, const ll& dis){
        if(!dist.count(val)){
            dist[val]=dis;
            return true;
        }
        if(dist[val]>dis){
            dist[val]=dis;
            return true;
        }
        return false;
    };
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(dist[cur.second]<cur.first)continue;
        if(cur.second==1){
            printf("%lli\n",cur.first);
            break;
        }
        if(trydist(1,cur.first+cur.second-1)){
            q.push({cur.first+cur.second-1,1});
        }
        ll below=sqrtl(cur.second);
        if(trydist(below,1+cur.first+cur.second-below*below)){
            q.push({1+cur.first+cur.second-below*below,below});
        }
        if(trydist(below+1,1+cur.first+(below+1)*(below+1)-cur.second)){
            q.push({1+cur.first+(below+1)*(below+1)-cur.second,below+1});
        }
        for(int i=3;i<=64;i++){
            int ind=upper_bound(arr[i].begin(),arr[i].end(),pll{cur.second,LLONG_MAX})-arr[i].begin()-1;
            if(ind!=-1&&trydist(arr[i][ind].second,1+cur.first+cur.second-arr[i][ind].first)){
                q.push({1+cur.first+cur.second-arr[i][ind].first,arr[i][ind].second});
            }
            ind++;
            if(ind!=sz(arr[i])&&trydist(arr[i][ind].second,1+cur.first+arr[i][ind].first-cur.second)){
                q.push({1+cur.first+arr[i][ind].first-cur.second,arr[i][ind].second});
            }
        }
    }
    return 0;
}