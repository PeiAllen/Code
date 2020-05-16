#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    lli ans=0;
    ans+=(arr[0]-arr[1])*(arr[0]-arr[1]);
    for(int i=2;i<n;i++){
        ans+=(arr[i]-arr[i-2])*(arr[i]-arr[i-2]);
    }
    ans+=(arr[n-2]-arr[n-1])*(arr[n-2]-arr[n-1]);
    printf("%lli\n",ans);
    return 0;
}