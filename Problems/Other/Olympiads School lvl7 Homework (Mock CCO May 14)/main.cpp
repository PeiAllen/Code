#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const ll mod=998244353;
ll fastpow(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=(ll)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==2) {
        ll a, b;
        int x, y;
        cin >> x >> y;
        cin >> a >> b;
        ll num = a * a + a * b * (ll) 2 + b * b;
        ll den = a * b;
        ll gc = __gcd(num, den);
        num /= gc, den /= gc;
        if (pii{x, y} == pii{0, 0}) {
            printf("0\n");
        } else if (pii{x, y} == pii{0, 1}) {
            num = (num + den) * a + b * den;
            den = den * (a + b);
            gc = __gcd(num, den);
            num /= gc, den /= gc;
            printf("%lli\n", num * fastpow(den, mod - 2) % mod);
        } else if (pii{x, y} == pii{1, 0}) {
            num = (num + den) * b + a * den;
            den = den * (a + b);
            gc = __gcd(num, den);
            num /= gc, den /= gc;
            printf("%lli\n", num * fastpow(den, mod - 2) % mod);
        } else {
            printf("%lli\n", num * fastpow(den, mod - 2) % mod);
        }
    }

    return 0;
}