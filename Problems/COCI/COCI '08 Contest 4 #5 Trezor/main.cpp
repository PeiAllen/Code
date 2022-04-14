#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

ll coprime(ll n, ll a){// number of numbers in range [1...n] coprime with a
    if(a==0)return 1;
    vector<ll> primes;
    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            primes.push_back(i);
            while(a%i==0)a/=i;
        }
    }
    if(a>1)primes.push_back(a);
    ll am=0;
    for(ll i=0;i<(1<<sz(primes));i++){
        ll val=1;
        for(int j=0;j<sz(primes);j++){
            if(i&(1<<j))val*=primes[j];
        }
        if(__builtin_popcount(i)%2==0)am+=n/val;
        else am-=n/val;
    }
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a,b,n;
    cin>>a>>b>>n;
    ll both=0,neither=0,one=0;
    for(ll i=-a;i<=b;i++){
        ll base1=i-(-a),base2=b-i;
        //number of nums which are coprime with a
        //number of nums which are coprime with a & b aka coprime with a*b;
        ll asee=coprime(n,base1),bsee=coprime(n,base2);
        ll bothsee=coprime(n,base1*base2);
        if(base1==0)bothsee=1;
        if(base2==0)bothsee=1;
        both+=bothsee;
        one+=asee-bothsee+bsee-bothsee;
        neither+=n-(asee+bsee-bothsee);
    }
    printf("%lli\n%lli\n%lli\n",neither,one,both);
    return 0;
}