#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=20;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    ll sum=accumulate(arr,arr+n,ll(0));
    ll best=LLONG_MAX;
    for(int i=0;i<(1<<n);i++){
        ll sum2=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum2+=arr[j];
            }
        }
        best=min(best,abs(sum2-(sum-sum2)));
    }
    printf("%lli\n",best);
    return 0;
}