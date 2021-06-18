#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e4+7;
const int MN=1e3+1;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    auto solve=[&](ll monkeys){
        ll te=1;
        for(int i=1;i<n;i++){
            te=te*(arr[i]/monkeys)%mod;
        }
        return te;
    };
    for(ll i=1;i*i<=arr[0];i++){
        if(arr[0]%i==0){
            ans=(ans+solve(i))%mod;
            if(arr[0]/i!=i)ans=(ans+solve(arr[0]/i))%mod;
        }
    }
    printf("%lli\n",ans);
    return 0;
}