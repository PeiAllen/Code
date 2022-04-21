#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        ll a;
        cin>>a;
        for(ll i=1,am=9;;i++,am*=10){
            if(am*i>=a){
                a--;
                ll val=am/9+a/i;
                printf("%c\n",to_string(val)[a%i]);
                break;
            }
            a-=am*i;
        }
    }
    return 0;
}