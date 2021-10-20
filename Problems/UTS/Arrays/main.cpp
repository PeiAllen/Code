#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a=0,sum=0,cur;
    for(int i=1;i<=n;i++){
        cin>>a;
        cur=(sum+a)%mod;
        sum=(sum+cur)%mod;
    }
    printf("%lli\n",cur);
    return 0;
}