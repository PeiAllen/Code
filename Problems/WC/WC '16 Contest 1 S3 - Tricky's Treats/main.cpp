#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,t;
    cin>>n>>m>>t;
    priority_queue<int,vector<int>,greater<>> vals;
    vector<pii> houses(n);
    int sum=0,best=0;
    for(int i=0;i<n;i++)cin>>houses[i].first>>houses[i].second;
    sort(houses.begin(),houses.end());
    for(int i=0;i<n;i++){
        sum+=houses[i].second;
        vals.push(houses[i].second);
        while(sz(vals)&&sz(vals)>(m-houses[i].first*2)/t)sum-=vals.top(),vals.pop();
        best=max(best,sum);
    }
    printf("%d\n",best);
    return 0;
}