#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    ll num=a/b;
    ll mo=a%b;
    if(num||!mo)printf("%lli ",num);
    if(mo) {
        ll k = __gcd(mo, b);
        printf("%lli/%lli",mo/k,b/k);
    }
    printf("\n");
    return 0;
}