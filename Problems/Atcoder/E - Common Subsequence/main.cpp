#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e3+1;
const int mod=1e9+7;
int arr[2][MN],psa[MN],tepsa[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[0][i];
    for(int i=1;i<=m;i++)cin>>arr[1][i],psa[i]=1;
    psa[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tepsa[j]=(tepsa[j-1]+(arr[0][i]==arr[1][j])*(psa[j-1]-tepsa[j-1]+mod)%mod)%mod;
            psa[j]=(psa[j]+tepsa[j])%mod;
        }
    }
    printf("%d\n",psa[m]);
    return 0;
}