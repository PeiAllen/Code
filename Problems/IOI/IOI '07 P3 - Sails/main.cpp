#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pii arr[MN];
priority_queue<ll,vector<ll>,greater<>> q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    int last=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        for(;last<arr[i].first;last++)q.push(0);
        vector<ll> topush;
        for(int j=0;j<arr[i].second;j++){
            ans+=q.top();
            topush.push_back(q.top()+1);
            q.pop();
        }
        for(auto x:topush)q.push(x);
    }
    printf("%lli\n",ans);
    return 0;
}