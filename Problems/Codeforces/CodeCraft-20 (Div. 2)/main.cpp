#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli mod=1e9+7;
const int MAXN=3e5+1;
lli arr[MAXN];
lli precalc[MAXN];
lli val[MAXN];
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    lli div=fastpow(fastpow(2,n),mod-2);
    sort(arr+1,arr+1+n);
    precalc[0]=1;
    for(int i=1;i<=n;i++){
        precalc[i]=precalc[i-1]*(lli)2%mod;
    }
    lli sum=0;
    lli ans=0;
    for(int i=n;i>=1;i--){
        val[i]=arr[i]*precalc[n-i];
        ans=(ans+((sum*arr[i]%mod)*precalc[i-1]%mod))%mod;
        sum=(sum+val[i])%mod;
    }
    printf("%lli\n",ans*div%mod);
    int q;
    cin>>q;
    while(q--){

    }
    return 0;
}