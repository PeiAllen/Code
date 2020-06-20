#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e4+1;
const ll mod=1e9+7;
inline ll lfix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
inline ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=(ll)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int am[3];
string arr[3];
int k[4];
ll fact[MAXN],inv[MAXN];
int psa[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    assert(n<=1e4);
    fact[0]=1;

    inv[0]=1;
    for(int i=1;i<MAXN;i++)fact[i]=fact[i-1]*(ll)i%mod;
    inv[MAXN-1]=fp(fact[MAXN-1],mod-2);
    for(int i=MAXN-2;i>=1;i--)inv[i]=inv[i+1]*(ll)(i+1)%mod;
    for(int str=0;str<3;str++) {
        cin>>am[str]>>arr[str];
        am[str]=n-am[str]-1;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])k[0]++;
        else if(arr[0][i]==arr[1][i])k[1]++;
        else if(arr[0][i]==arr[2][i])k[2]++;
        else k[3]++;
    }
    for(int i=0;i<=k[0];i++){
        for(int j=0;j<=k[1];j++){
            psa[i+j][i+k[1]-j]=((fact[k[0]]*inv[i]%mod)*inv[k[0]-i]%mod)*((fact[k[1]]*inv[j]%mod)*inv[k[1]-j]%mod)%mod;
        }
    }
    for(int i=0;i<=k[0]+k[1];i++){
        for(int j=0;j<=k[0]+k[1];j++) {
            psa[i][j]=lfix(lfix(lfix(psa[i][j]+(i-1>=0?psa[i-1][j]:0))+(j-1>=0?psa[i][j-1]:0))-(i-1>=0&&j-1>=0?psa[i-1][j-1]:0));
        }
    }
    for(int i=0;i<=k[2];i++){
        for(int j=0;j<=k[3];j++){
            int fi=min({am[0]-i-j,am[1]-(k[2]-i)-(k[3]-j),k[0]+k[1]}),se=min(k[0]+k[1],am[2]-i-(k[3]-j));
            if(fi>=0&&se>=0&&psa[fi][se])ans=lfix(ans+(((ll)psa[fi][se]*((fact[k[2]]*inv[i]%mod)*inv[k[2]-i]%mod)%mod)*((fact[k[3]]*inv[j]%mod)*inv[k[3]-j]%mod)%mod));
        }
    }
    printf("%lli\n",lfix(fp(2,n)-ans));
    return 0;
}
// diff <=r diff >r, same <=n-r-1