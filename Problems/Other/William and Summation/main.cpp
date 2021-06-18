#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll sum=0,best=LLONG_MAX,ma=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i]*ll(n-i+1);
        arr[i]=(-arr[i])*ll(n-i+1)+(-arr[i])*ll(n-i+1);
        arr[i]+=arr[i-1];
        best=min(best,arr[i]-ma);
        ma=max(ma,arr[i]);
    }
    printf("%lli\n",sum+best);
    return 0;
}
