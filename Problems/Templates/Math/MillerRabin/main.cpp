#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
template <class T> T mm(T a, T b, T mod){//use mm when multiplication overflows.
    a%=mod,b%=mod;
    T ans=0;
    for(T i=1;i<=b;i<<=1){
        if(b&i)ans=(ans+a)%mod;
        a=(a+a)%mod;
    }
    return ans;
}
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
    for(T a:{2, 325, 9375, 28178, 450775, 9780504, 1795265022}){//https://miller-rabin.appspot.com/
        T v=fp(a,d,x),i=s-1;
        if(v!=1)while(v!=x-1&&i--&&v>1)v=v*v%x;
        if(v!=x-1&&a%x!=0&&i!=s-1)return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}