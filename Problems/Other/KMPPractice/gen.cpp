#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(int argc, char *argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(atoi(argv[1]));
    uniform_int_distribution<int> length(1,10),character(0,25);
    int n=length(gen),m=length(gen);
    for(int i=0;i<n;i++)printf("%c",'a'+character(gen));
    printf("\n");
    for(int i=0;i<m;i++)printf("%c",'a'+character(gen));
    return 0;
}
