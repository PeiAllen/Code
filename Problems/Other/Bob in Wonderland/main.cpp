#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int a;
    while(m--){
        cin>>a;
        printf("%d\n",arr+n-lower_bound(arr,arr+n,a));
    }
    return 0;
}