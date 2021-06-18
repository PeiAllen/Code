#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
map<pll,ll> dist;
int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<>> q;
    q.push({1,{n,m}});
    dist[{n,m}]=1;
    ll shortest=-1;
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second])continue;
        if(cur.second.first*2==cur.second.second){
            shortest=cur.first;
            break;
        }
        auto go=[&](ll a, ll b){
            if(a>b)swap(a,b);
            if(a%2==1&&b%2==1)return;
            if(!dist.count({a,b})||dist[{a,b}]>cur.first+1){
                dist[{a,b}]=cur.first+1;
                q.push({cur.first+1,{a,b}});
            }
        };
        if(cur.second.first%2==0&&cur.second.second-cur.second.first/2>=1)go(cur.second.first,cur.second.second-cur.second.first/2);
        if(cur.second.second-cur.second.first*2>=1)go(cur.second.first,cur.second.second-cur.second.first*2);
        if(cur.second.second%2==0&&cur.second.first-cur.second.second/2>=1)go(cur.second.first-cur.second.second/2,cur.second.second);
        if(cur.second.first-cur.second.second*2>=1)go(cur.second.first-cur.second.second*2,cur.second.second);
    }
    set<pll> ord;
    dist=map<pll,ll>();
    ord.insert({n,m});
    dist[{n,m}]=1;
    ll worst=LLONG_MIN;
    while(sz(ord)){
        auto cur=*ord.rbegin();
        ord.erase(cur);
        ll dis=dist[{cur.first,cur.second}];
        if(cur.first*2==cur.second){
            worst=max(worst,dist[{cur.first,cur.second}]);
        }
        auto go=[&](ll a, ll b){
            if(a>b)swap(a,b);
            if(a>n||b>m)return;
            if(!dist.count({a,b})){
                dist[{a,b}]=dis+1;
                ord.insert({a,b});
            }
            else dist[{a,b}]=max(dist[{a,b}],dis+1);
        };
        if(cur.first%2==0&&cur.second-cur.first/2>=1)go(cur.first,cur.second-cur.first/2);
        if(cur.second-cur.first*2>=1)go(cur.first,cur.second-cur.first*2);
        if(cur.second%2==0&&cur.first-cur.second/2>=1)go(cur.first-cur.second/2,cur.second);
        if(cur.first-cur.second*2>=1)go(cur.first-cur.second*2,cur.second);
    }
    printf("%lli %lli\n",shortest,worst);
    return 0;
}