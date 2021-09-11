#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first;
#define B second;
template<typename T> int SZ(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    ll asum=0,dsum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==1)asum+=(a+1)/2;
        else dsum+=a/2;
    }
    if(asum>=dsum)printf("Alice\n");
    else printf("Duke\n");
    return 0;
}