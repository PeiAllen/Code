#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=4001;
vector<int> adj[MN];
int main(int argc, char *argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(atoi(argv[1]));
    uniform_int_distribution<int> ngen(2,10);
    int n=ngen(gen);
    uniform_int_distribution<int> kgen(0,n*(n-1)/2);
    int k=kgen(gen);
    uniform_int_distribution<int> egen(0,10);
    int a=egen(gen),b=egen(gen);
    printf("%d %d %d %d\n",n,a,b,k);
    uniform_int_distribution<int> nodegen(1,n/2);
    uniform_int_distribution<int> edgegen(1,10);
    for(int i=1;i<=a;i++){
        printf("%d %d %d\n",nodegen(gen),nodegen(gen),edgegen(gen));
    }
    uniform_int_distribution<int> node2gen(n/2+1,n);
    for(int i=1;i<=b;i++){
        printf("%d %d %d\n",node2gen(gen),node2gen(gen),edgegen(gen));
    }
    return 0;
}