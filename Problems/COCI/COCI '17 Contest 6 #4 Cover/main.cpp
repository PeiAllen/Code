#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
ll dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    map<int,int> points;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        a=abs(a),b=abs(b);
        points[-a]=max(points[-a],b);
    }
    vector<pll> arr;
    ll sofar=0;
    for(auto x:points){
        sofar=max(sofar,ll(x.second));
        arr.push_back({-x.first,sofar});
    }
    reverse(arr.begin(),arr.end());
    dp[0]=0;
    for(int i=1;i<=sz(arr);i++){
        dp[i]=LLONG_MAX;
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],dp[j-1]+arr[i-1].first*arr[j-1].second*4);
        }
    }
    printf("%lli\n",dp[sz(arr)]);
    return 0;
}