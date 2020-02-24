#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=1e7+1;
const lli mod=1e9+7;
int inv[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli sum=0;
    inv[1]=1;
    lli ans=0;
    for(int i=2;i<=n;i++){
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    }
    for(int i=n-1;i>=1;i--){
        ans=(sum+n-i+1)*inv[n-i]%mod;
        sum=(sum+ans)%mod;
    }
    printf("%lli\n",ans);
    return 0;
}