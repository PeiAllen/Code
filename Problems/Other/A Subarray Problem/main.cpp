#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        arr[a]=i;
    }
    int l=INT_MAX,r=-1;
    int ans=0;
    for(int i=1;i<=n;i++){
        l=min(l,arr[i]);
        r=max(r,arr[i]);
        if(r-l+1==i)ans++;
    }
    printf("%d\n",ans);
    return 0;
}