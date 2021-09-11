#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
template <class T> T fp(T a, T b, T mod){
    a%=mod;
    T ans=1;
    for(T i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
template <class T> bool isprime(T x){
    if(x<=1||x%6%4!=1)return (x|1)==3;
    T s=0,d=x-1;
    while(!(d&1))s++,d>>=1;
    for(T a:{2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        T v=fp(a,d,x),i=s-1;
        if(v!=1)while(v!=x-1&&i--&&v>1)v=v*v%x;
        if(v!=x-1&&a%x!=0&&i!=s-1)return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll ans=1;
    for(ll i=2;i*i*i<=n;i++){
        ll am=0;
        while(n%i==0)am++,n/=i;
        ans*=(am+1);
    }
    if(isprime(__int128(n)))ans*=2;
    else if(isprime(__int128(sqrtl(n)))&&ll(sqrtl(n))*ll(sqrtl(n))==n)ans*=3;
    else if(n!=1)ans*=4;
    printf("%lli\n",ans);
    return 0;
}