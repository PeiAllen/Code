#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}

int main(int argc, char *argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 seed(atoi(argv[1]));
    int n=5;
    printf("%d\n",n);
    uniform_int_distribution<int> arrv(-(n+3),n+3);
    for(int i=1;i<=n;i++)printf("%d%c",arrv(seed)," \n"[i==n]);
    return 0;
}