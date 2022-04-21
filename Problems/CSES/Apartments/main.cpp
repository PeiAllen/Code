#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,a;
    cin>>n>>m>>k;
    vector<pii> range;
    for(int i=0;i<n;i++){
        cin>>a;
        range.push_back({a-k,a+k});
    }
    sort(range.begin(),range.end());
    vector<int> arr(m);
    for(int i=0;i<m;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ptr=0,ans=0;
    for(int i=0;i<n;i++){
        while(ptr<m&&arr[ptr]<range[i].first)ptr++;
        if(ptr<m&&arr[ptr]<=range[i].second)ptr++,ans++;
    }
    printf("%d\n",ans);
    return 0;
}