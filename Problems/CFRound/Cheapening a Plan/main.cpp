#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+2;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll should=min(arr[i],max(arr[i-1],arr[i+1]));
        ans+=arr[i]-should+abs(should-arr[i-1]);
        arr[i]=should;
    }
    printf("%lli\n",ans+arr[n]);
    return 0;
}

/*
 * Given a histogram, each line of length 1 costs 1 dollar,
 * and you only need to fill the lines between the inside and outside of the histogram bars.
 * Now you can also decrease the height of each histogram by 1 for 1 dollar,
 * you can do this infinitely until it reaches 0 height.
 * What is the minimal cost needed given the histogram.
Note there are no lines on the bottom
But there are lines at the top of each bar
 */