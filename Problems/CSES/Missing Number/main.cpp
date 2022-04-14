#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll sum=n*ll(n+1)/2;
    ll a;
    for(int i=1;i<n;i++){
        cin>>a;
        sum-=a;
    }
    printf("%lli\n",sum);
    return 0;
}