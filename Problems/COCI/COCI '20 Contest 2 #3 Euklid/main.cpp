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
    int t;
    cin>>t;
    while(t--){
        ll g,h;
        cin>>g>>h;
        ll te=h;
        ll g2=2*g;
        while(te<g2)te*=h;
        ll gv=(te+g2-1)/g2*g2;
        printf("%lli %lli\n",gv,gv*h+g);
    }
    return 0;
}

