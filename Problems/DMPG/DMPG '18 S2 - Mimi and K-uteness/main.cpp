#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[i]+=arr[i-1];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=arr[n-i+1]-arr[i-1];
        printf("%lli\n",ans);
    }
    return 0;
}