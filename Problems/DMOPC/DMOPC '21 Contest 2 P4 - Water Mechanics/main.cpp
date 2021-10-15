#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN],dp[MN],reach[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int am=0,prev=0,firstsame=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]!=arr[firstsame])firstsame=i;
        if(firstsame<=i-k)reach[i]=i-k;
        else reach[i]=(firstsame-1==0||arr[firstsame-1]>arr[i]?firstsame:reach[firstsame-1]);
        if(arr[i]>arr[i-1])am=0,prev=reach[i]-1;
        else if(am+1>k)am=(arr[i]<arr[i-1]?0:k),prev=reach[i-k]-1;
        else am=(arr[i]<arr[i-1]?0:am+1);
        dp[i]=dp[prev]+1;
    }
    printf("%d\n",dp[n]);
    return 0;
}