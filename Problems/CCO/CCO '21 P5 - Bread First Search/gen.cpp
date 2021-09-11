#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(atoi(argv[1]));
    int n=7;
    uniform_int_distribution<int> dist(0,5);
    int m=dist(gen);
    uniform_int_distribution<int> dist2(1,n);
    printf("%d %d\n",n,m);
    for(int i=0;i<m;i++)printf("%d %d\n",dist2(gen),dist2(gen));
    return 0;
}