#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+2;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        if(arr[i]==m)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}