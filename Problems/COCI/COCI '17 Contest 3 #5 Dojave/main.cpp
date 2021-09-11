#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int arr[(1<<20)+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    ll tot=0;
    for(int i=1;i<=(1<<m);i++){
        cin>>arr[i];
        arr[i]^=arr[i-1];
        tot+=ll(i);
    }
    ll am=0;
    for(int len=(1<<m);len>=(1<<m)-2;len--){

    }
    printf("%lli\n",tot);
    return 0;
}