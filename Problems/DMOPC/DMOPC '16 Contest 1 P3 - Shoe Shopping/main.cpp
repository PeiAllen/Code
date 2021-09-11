#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
double arr[MN],dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i]=min({dp[i-1]+arr[i],(i-2>=0?dp[i-2]+arr[i]+arr[i-1]-min(arr[i],arr[i-1])/2:DBL_MAX),(i-3>=0?dp[i-3]+arr[i]+arr[i-1]+arr[i-2]-min({arr[i],arr[i-1],arr[i-2]}):DBL_MAX)});
    }
    printf("%.1f\n",dp[n]);
    return 0;
}