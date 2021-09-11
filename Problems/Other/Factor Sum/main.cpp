#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll MV=1e12;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        ll a;
        cin>>a;
        int cnt=0;
        bool done=false;
        while(cnt<=1000&&a<=MV&&!done) {
            ll ne = 1,old=a;
            for (ll i = 2; i * i <= a; i++) {
                ll val=i;
                while(a%i==0){
                    val*=i;
                    a/=i;
                }
                ne*=((val-1)/(i-1));
            }
            if(ne==1){
                printf("%lli %d\n",a,cnt);
                done=true;
            }
            if(a>1)ne*=a+1;
            a=ne-old;
            cnt++;
        }
        if(!done)printf("INFINITY\n");
    }
    return 0;
}