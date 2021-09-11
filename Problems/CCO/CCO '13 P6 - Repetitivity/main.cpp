#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
int psa[MN],tepsa[MN];
int main(){//refer to https://atcoder.jp/contests/abc130/tasks/abc130_e
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    int mod;
    cin>>a>>mod;
    for(int i=0;i<=sz(a);i++)psa[i]=1;
    for(int i=1;i<=sz(a);i++){
        for(int j=1;j<=sz(a);j++){
            tepsa[j]=(tepsa[j-1]+(a[i-1]==a[j-1])*(psa[j-1]-tepsa[j-1]+mod)%mod)%mod;
            psa[j]=(psa[j]+tepsa[j])%mod;
        }
    }
    printf("%d\n",psa[sz(a)]);
    return 0;
}