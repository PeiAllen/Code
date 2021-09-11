#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin>>a>>b>>c;
    c-=a+b;
    if(ll(4)*a*b<c*c&&c>=0)printf("Yes\n");
    else printf("No\n");
    return 0;
}