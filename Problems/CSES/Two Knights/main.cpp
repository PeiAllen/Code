#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==1)return 0*printf("0\n");
    if(n==2)return 0*printf("0\n6\n");
    printf("0\n6\n28\n");
    ll last=28;
    for(int i=4;i<=n;i++){
        last+=ll(i+i-1)*ll(i+i-2)/2+ll(i+i-1)*ll(i-1)*ll(i-1)-(2*3+3*4+4*(i+i-8)-2);
        printf("%lli\n",last);
    }
    return 0;
}