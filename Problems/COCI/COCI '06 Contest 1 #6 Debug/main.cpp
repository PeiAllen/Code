#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=302;
const ll base=31;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll inv[MN];
ll hashhr[MN][MN];
ll hashhl[MN][MN];
ll hashvu[MN][MN];
ll hashvd[MN][MN];
ll pcalc[MN];
bool work[2][MN][MN];
char arr[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    pcalc[0]=inv[0]=1;
    for(int i=1;i<=max(r,c);i++)pcalc[i]=pcalc[i-1]*base%mod,inv[i]=fp(pcalc[i],mod-2);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>arr[i][j];
            hashhr[i][j]=(hashhr[i][j-1]+pcalc[j]*(arr[i][j]+1))%mod;
            hashvd[i][j]=(hashvd[i-1][j]+pcalc[i]*(arr[i][j]+1))%mod;
        }
    }
    for(int i=r;i>=1;i--){
        for(int j=c;j>=1;j--){
            hashhl[i][j]=(hashhl[i][j+1]+pcalc[c-j+1]*(arr[i][j]+1))%mod;
            hashvu[i][j]=(hashvu[i+1][j]+pcalc[r-i+1]*(arr[i][j]+1))%mod;
        }
    }
    for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)work[1][i][j]=work[0][i][j]=true;
    int ans=-1;
    for(int si=2;si<=min(r,c);si++){
        for(int i=1;i+si-1<=r;i++){
            for(int j=1;j+si-1<=c;j++){
                if(work[si%2][i+1][j+1]){
                    if((hashhr[i][j+si-1]-hashhr[i][j-1]+mod)*inv[j]%mod==(hashhl[i+si-1][j]-hashhl[i+si-1][j+si]+mod)*inv[c-(j+si-1)+1]%mod){
                        if((hashvd[i+si-1][j]-hashvd[i-1][j]+mod)*inv[i]%mod==(hashvu[i][j+si-1]-hashvu[i+si][j+si-1]+mod)*inv[r-(i+si-1)+1]%mod){
                            ans=si;
                            work[si%2][i][j]=true;
                        }
                        else{
                            work[si%2][i][j]=false;
                        }
                    }
                    else{
                        work[si%2][i][j]=false;
                    }
                }
                else{
                    work[si%2][i][j]=false;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}