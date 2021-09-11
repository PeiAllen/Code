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
    ll n,x;
    cin>>n>>x;
    ll sum=0;
    for(ll i=1;i<n-1;i++){
        sum+=n-1-i;
    }
    if(x>sum){
        printf("-1\n");
        return 0;
    }
    ll torem=sum-x;
    vector<ll> notwanted,wanted;
    for(ll i=n-2;i>=1;i--){
        if(torem>(i-1)*i/2){
            notwanted.push_back(n-1-i);
            torem-=i;
        }
        else wanted.push_back(n-1-i);
    }
    printf("%lli ",n);
    for(auto x:wanted)printf("%lli ",x);
    printf("%lli ",n-1);
    reverse(notwanted.begin(),notwanted.end());
    for(auto x:notwanted)printf("%lli ",x);
    printf("\n");
    return 0;
}