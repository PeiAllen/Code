#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[3][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[0][i];
    for(int i=1;i<=n;i++)cin>>arr[1][i];
    for(int i=1;i<=n;i++)cin>>arr[2][i];
    sort(arr[0]+1,arr[0]+n+1);
    sort(arr[1]+1,arr[1]+n+1);
    sort(arr[2]+1,arr[2]+n+1);
    ll ans=0;
    for(int i=1,lptr=1,rptr=1;i<=n;i++){
        while(lptr<=n&&arr[0][lptr]<arr[1][i]){
            lptr++;
        }
        while(rptr<=n&&arr[2][rptr]<=arr[1][i])rptr++;
        ans+=ll(lptr-1)*ll(n-rptr+1);
    }
    printf("%lli\n",ans);
    return 0;
}