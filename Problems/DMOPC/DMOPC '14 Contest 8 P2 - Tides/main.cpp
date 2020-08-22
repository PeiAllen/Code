#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int le=min_element(arr,arr+n)-arr;
    int ri=max_element(arr,arr+n)-arr;
    if(le<ri&&is_sorted(arr+le,arr+ri+1))printf("%d\n",arr[ri]-arr[le]);
    else printf("unknown");
    return 0;
}