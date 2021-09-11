#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
struct mat{
    vector<vector<ll>> v;
    mat(){v=vector<vector<ll>>();}
    mat(int n, int m){v=vector<vector<ll>>(n,vector<ll>(m,0));}
    mat(const vector<vector<ll>> &a):v(a){}
    mat operator + (const mat &b){
        mat c(vector<vector<ll>>(sz(v),vector<ll>(sz(v[0]),0)));
        for(int i=0;i<sz(v);i++)for(int j=0;j<sz(v[i]);j++)c.v[i][j]=(v[i][j]+b.v[i][j])%mod;
        return c;
    }
    mat operator * (const mat &b){
        mat c(vector<vector<ll>>(sz(v),vector<ll>(sz(b.v[0]),0)));
        for(int i=0;i<sz(v);i++)for(int j=0;j<sz(v[i]);j++)if(v[i][j])for(int k=0;k<sz(b.v[j]);k++)c.v[i][k]=(c.v[i][k]+v[i][j]*b.v[j][k]%mod)%mod;
        return c;
    }
};
mat spec(const mat &a, const mat &b){//rip caching
    mat c(vector<vector<ll>>(sz(a.v),vector<ll>(sz(b.v[0]),0)));
    for(int j=0;j<sz(a.v[0]);j++)for(int k=0;k<sz(b.v[j]);k++)if(b.v[j][k])for(int i=0;i<sz(a.v);i++)c.v[i][k]=(c.v[i][k]+a.v[i][j]*b.v[j][k]%mod)%mod;
    return c;
}
mat dp[61][3][3];//A=0,S=1,T=2
/*need
 * <=i(A,A) = <=i-1(A,A) + <=i-1(A,A) * <=i-1(A,A)//assumes right after a button press of i+1
 * <=i(A,T) = <=i-1(A,T) + <=i-1(A,A) * <=i-1(A,T)//assumes anywhere is right after a button press of i+1
 * <=i(S,A) = <=i-1(S,A) + <=i-1(S,A) * <=i-1(A,A)
 * <=i(S,T) = <=i-1(S,T) + <=i-1(S,A) * <=i-1(A,T)
 */
int main(){//sketch op
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<ll>> matrix(n,vector<ll>(n,0));
    string in;
    for(int i=0;i<n;i++){
        cin>>in;
        for(int j=0;j<n;j++)matrix[i][j]=(in[j]=='1');
    }
    dp[0][0][0]=mat(matrix);
    for(int i=1;i<=k;i++)dp[i][0][0]=dp[i-1][0][0]+(dp[i-1][0][0]*dp[i-1][0][0]);
    int bs,s,bt,t;
    while(q--){
        cin>>bs>>s>>bt>>t,s-=1,t-=1;
        dp[min(bs,bt)-1][0][2]=mat(n,n);
        for(int i=0;i<n;i++)dp[min(bs,bt)-1][0][2].v[i][t]=dp[min(bs,bt)-1][0][0].v[i][t];
        dp[min(bs,bt)-1][1][0]=mat(n,n);
        for(int i=0;i<n;i++)dp[min(bs,bt)-1][1][0].v[s][i]=dp[min(bs,bt)-1][0][0].v[s][i];
        dp[min(bs,bt)-1][1][2]=mat(n,n);
        dp[min(bs,bt)-1][1][2].v[s][t]=(bs==bt?ll(0):dp[min(bs,bt)-1][0][0].v[s][t]);
        for(int i=min(bs,bt);i<=k;i++){
            dp[i][0][2]=dp[i-1][0][2]+(i==bt?mat(n,n):spec(dp[i-1][0][0],dp[i-1][0][2]));
            dp[i][1][0]=dp[i-1][1][0]+(i==bs?mat(n,n):dp[i-1][1][0]*dp[i-1][0][0]);
            dp[i][1][2]=dp[i-1][1][2]+((i==bs||i==bt)?mat(n,n):dp[i-1][1][0]*dp[i-1][0][2]);
        }
        printf("%lli\n",dp[k][1][2].v[s][t]+(s==t&&bs==bt?1:0));
    }
    return 0;
}