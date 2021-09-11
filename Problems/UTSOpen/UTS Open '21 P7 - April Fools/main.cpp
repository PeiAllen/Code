#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
inline ll fix(ll a){
    if(a>=mod)a-=mod;
    return a;
}
ll dp[2][2][MN][MN];// loc, number of segments ending with number with <=msb(ai)-2, number of segments ending with number with msb(ai)-1,number of segments ending with number with msb(ai)
ll sum[2][2];
ll fact[MN],inv[MN];
int arr[MN];
ll P(ll a, ll b){
    return fact[a]*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==1){
        printf("1\n");
        return 0;
    }
    fact[0]=inv[0]=1;
    for(int i=1;i<=n;i++)cin>>arr[i],fact[i]=fact[i-1]*ll(i)%mod,inv[i]=fp(fact[i],mod-2);
    sort(arr+1,arr+n+1);
    dp[0][0][0][1]=1;
    sum[0][1]=1;
    int cur=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=1;j++){
            sum[cur][j]=0;
            for(int p=0;p+j<=i;p++)for(int q=0;q+p+j<=i;q++)dp[cur][j][p][q]=0;
        }
        if(__lg(arr[i])==__lg(arr[i-1])){
            for(int j=0;j<=1;j++){
                for(int p=0;p+j<=i-1;p++){
                    for(int q=0;q+p+j<=i;q++){
                        if(q)dp[cur][j][p][q]=fix(dp[cur][j][p][q]+dp[!cur][j][p][q-1]);
                        dp[cur][j][p][q]=fix(dp[cur][j][p][q]+ll(j+p+q)*dp[!cur][j][p][q]%mod);
                        if(j+p+1<=i-1){
                            if(q)dp[cur][j][p][q]=fix(dp[cur][j][p][q]+ll(p+1)*dp[!cur][j][p+1][q-1]%mod);
                            dp[cur][j][p][q]=fix(dp[cur][j][p][q]+ll(p+1)*ll(q)*dp[!cur][j][p+1][q]%mod);
                            dp[cur][j][p][q]=fix(dp[cur][j][p][q]+P(p+1,2)*dp[!cur][j][p+1][q]%mod);
                            dp[cur][j][p][q]=fix(dp[cur][j][p][q]+ll(p+1)*ll(j)*dp[!cur][j][p+1][q]%mod);
                        }
                    }
                }
            }
        }
        else if(__lg(arr[i])==__lg(arr[i-1])+1){
            for(int j=0;j<=1;j++){
                for(int k=0;k+j<=i-1;k++){
                    dp[cur][j][k][0]=fix(dp[cur][j][k][0]+ll(j+k)*(fix(dp[!cur][0][j][k]+(j>=1?dp[!cur][1][j-1][k]:0)))%mod);
                    if(k+1+j<=i-1){
                        dp[cur][j][k][0]=fix(dp[cur][j][k][0]+P(k+1,2)*fix(dp[!cur][0][j][k+1]+(j>=1?dp[!cur][1][j-1][k+1]:0))%mod);
                        dp[cur][j][k][0]=fix(dp[cur][j][k][0]+ll(k+1)*ll(j)*fix(dp[!cur][0][j][k+1]+(j>=1?dp[!cur][1][j-1][k+1]:0))%mod);
                        dp[cur][j][k][1]=fix(dp[cur][j][k][1]+ll(k+1)*fix(dp[!cur][0][j][k+1]+(j>=1?dp[!cur][1][j-1][k+1]:0))%mod);
                    }
                    dp[cur][j][k][1]=fix(dp[cur][j][k][1]+fix(dp[!cur][0][j][k]+(j>=1?dp[!cur][1][j-1][k]:0)));
                }
            }
        }
        else{
            for(int j=0;j<=1;j++){
                dp[cur][j][0][1]=fix(dp[cur][j][0][1]+sum[!cur][j]);
                dp[cur][j][0][0]=fix(dp[cur][j][0][0]+ll(j)*sum[!cur][j]%mod);
            }
        }
        for(int j=0;j<=1;j++)for(int p=0;p+j<=1;p++)for(int q=0;q+p+j<=1;q++)sum[cur][j+p+q]=fix(sum[cur][j+p+q]+dp[cur][j][p][q]);
        cur=!cur;
    }
    printf("%lli\n",sum[!cur][1]);
    return 0;
}
/*
 * Ops:
 * append to the end of a segment (can only append to msb(ai)-1)
 * make a new segment
 * append to the front of a segment
 * use to merge two segments. (Front segment much have end msb(ai)-1)
 *      ai-1, ai-1
 */