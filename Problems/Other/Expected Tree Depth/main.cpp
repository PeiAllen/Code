#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int n;
lli mod;
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
lli depth[25];
lli dp[25][25];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>mod;
    depth[1]=1;
    lli ans=1;
    for(int i=2;i<=n;i++){
        lli inv=fastpow(i-1,mod-2);
        for(int j=1;j<i;j++){
            depth[i]=fix(depth[i]+(inv*fix(depth[j]+1)%mod));
        }
    }
    printf("%lli\n",ans);
    return 0;
}