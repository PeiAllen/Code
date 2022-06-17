#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e4+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1,greater<>());
    int prev=0;
    for(int i=1;i<=n;i++){
        while(i+1<=n&&arr[i+1]==arr[i])i++;
        if(i>m)return 0*printf("%d\n",prev);
        prev=i;
    }
    printf("%d\n",prev);
    return 0;
}