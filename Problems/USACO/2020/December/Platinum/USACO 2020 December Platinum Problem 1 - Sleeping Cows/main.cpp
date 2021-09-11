#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3002;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int cow[MN],barn[MN];
int am[MN],sufpsa[MN];
ll fact[MN],inv[MN];
ll C(ll a, ll b){return fact[a]*inv[b]%mod*inv[a-b]%mod;}
ll P(ll a, ll b){return fact[a]*inv[a-b]%mod;}
ll prefix[MN][MN],suffix[MN][MN];// prefix is current cow, number of cows that havent been taken yet suffix is current cow, number of barns that have not been taken.
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>cow[i];
    for(int i=1;i<=n;i++)cin>>barn[i];
    fact[0]=1,inv[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*ll(i)%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    sort(cow+1,cow+n+1),sort(barn+1,barn+n+1);
    cow[n+1]=INT_MAX;
    prefix[0][0]=1;
    for(int i=1;i<=n;i++){
        am[i]=lower_bound(barn+1,barn+n+1,cow[i+1])-lower_bound(barn+1,barn+n+1,cow[i]);
        for(int j=0;j<=i-1;j++){
            for(int k=0;k<=min(am[i],j+1);k++){
                prefix[i][j+1-k]=(prefix[i][j+1-k]+prefix[i-1][j]*C(j+1,k)%mod*P(am[i],k)%mod)%mod;
            }
        }
    }
    suffix[n+1][0]=1;
    for(int i=n;i>=1;i--){
        sufpsa[i]=sufpsa[i+1]+am[i];
        for(int j=sufpsa[i+1]-(n-i);j<=sufpsa[i+1];j++){
            suffix[i][j+am[i]]=(suffix[i][j+am[i]]+suffix[i+1][j])%mod;
            if(j+am[i]-1>=0)suffix[i][j+am[i]-1]=(suffix[i][j+am[i]-1]+suffix[i+1][j]*ll(j+am[i])%mod)%mod;
        }
    }
    ll ans=prefix[n][0];
    for(int i=1;i<=n;i++){
        ll fact=1;
        for(int j=2;j<=am[i];j++)fact=fact*ll(j)%mod;
        for(int j=am[i];j<=i-1;j++) {
            ans=(ans+prefix[i-1][j]*suffix[i+1][j-am[i]]%mod*fact%mod)%mod;
            fact=fact*ll(j+1)%mod;
        }
    }
    printf("%lli\n",ans);
    return 0;
}