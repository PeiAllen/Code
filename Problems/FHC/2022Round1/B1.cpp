#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n;
        cin>>n;
        ll xsum=0,ysum=0,xpsum=0,ypsum=0;
        ll x,y;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            xsum=(x+xsum)%mod;
            xpsum=(x*x%mod+xpsum)%mod;
            ysum=(y+ysum)%mod;
            ypsum=(y*y%mod+ypsum)%mod;
        }
        int q;
        cin>>q;
        ll sum=0;
        while(q--){
            cin>>x>>y;
            sum=(sum+x*x%mod*n%mod+xpsum-2*x%mod*xsum%mod+mod)%mod;
            sum=(sum+y*y%mod*n%mod+ypsum-2*y%mod*ysum%mod+mod)%mod;
        }
        printf("Case #%d: %lli\n",cs,sum);
    }
    return 0;
}