#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+2;
int arr[MAXN],pre[MAXN],suf[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        pre[i]=__gcd(arr[i],pre[i-1]);
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        suf[i]=__gcd(arr[i],suf[i+1]);
        ans=max(ans,__gcd(suf[i+1],pre[i-1]));
    }
    printf("%d\n",ans);
    return 0;
}