#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll solve(ll a){
    ll fib1=1,fib2=2;
    while(a>=fib2){
        ll te=fib2;
        fib2+=fib1;
        fib1=te;
    }
    if(a==fib1)return a;
    return solve(a-fib1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    printf("%lli\n",solve(n));
    return 0;
}