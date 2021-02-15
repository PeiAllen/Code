#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pii arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=1;
    for(int i=0;i<n;i++)cin>>arr[i].first,arr[i].second=i;
    sort(arr,arr+n);
    priority_queue<int,vector<int>,greater<>> cnt;
    for(int i=0;i<n;i++){
        cnt.push(arr[i].second);
        while(sz(cnt)&&cnt.top()<=i)cnt.pop();
        ans=max(ans,sz(cnt));
    }
    printf("%d\n",ans);
    return 0;
}