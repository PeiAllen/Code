#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=100000;
const ll MV=1e18;
bool nprime[MN];
ll largestpower[MN];
ll lval[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int> primes;
    for(ll i=2;sz(primes)<100;i++){
        if(!nprime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<MN;j+=i){
                nprime[j]=true;
            }
        }
    }
    for(int i=0;i<sz(primes);i++){
        ll val=1;
        while(val<=MV/primes[i]){
            largestpower[i]++;
            val*=primes[i];
            lval[i]=val;
        }
    }
    while(t--){
        ll k;
        cin>>k;
        ll needed;
        ll ans=0;
        for(int i=0;i<k;i++){
            cin>>needed;
            ll cur=lval[i];
            ll finm=0;
            for(ll j=largestpower[i];j>=1;j--){
                // in each multiple you gain
                ll gain=(cur-1)/(primes[i]-1);
                ll amgain=needed/gain;
                finm+=amgain*cur;
                needed-=amgain*gain;
            }
            ans=max(ans,finm);
        }
        printf("%lli\n",ans);
    }
    return 0;
}