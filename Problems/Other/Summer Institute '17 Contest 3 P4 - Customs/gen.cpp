#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
mt19937 gen(23);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n=100;
    uniform_int_distribution<int> rand(n-1,3*n);
    uniform_int_distribution<int> rand2(1,n);
    int m=rand(gen);
    printf("%d %d\n",n,m);
    for(int i=0;i<m;i++){
        printf("%d %d\n",rand2(gen),rand2(gen));
    }
    return 0;
}