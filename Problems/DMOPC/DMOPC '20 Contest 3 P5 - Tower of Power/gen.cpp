#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MV=20+1;
ll nprime[MV];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    srand(atoi(argv[1]));
    registerGen(argc,argv,0);
    int n=rnd.next(1,3);
    vector<ll> primes;
    for(ll i=2;i<MV;i++){
        if(!nprime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<MV;j+=i){
                nprime[j]=true;
            }
        }
    }
    ll m=primes[rnd.next(0,sz(primes)-1)];
    printf("%d %lli\n",n,m);
    for(int i=1;i<=n;i++)printf("%d%c",rnd.next(1,int(30))," \n"[i==n]);
    return 0;
}