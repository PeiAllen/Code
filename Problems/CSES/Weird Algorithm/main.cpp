#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    while(n!=1){
        printf("%lli ",n);
        if(n%2==0)n/=2;
        else n=n*3+1;
    }
    printf("%lli\n",n);
    return 0;
}