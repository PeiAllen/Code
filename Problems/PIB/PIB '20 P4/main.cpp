#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e3+1;
lli mod=1e9+7;
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
lli fact[MAXN];
lli inv[MAXN];
lli choose(lli a,lli b){
    return ((fact[a]*inv[b]%mod)*inv[a-b])%mod;
}
vector<int> matrix[MAXN];
lli dp[MAXN][17][142];
int height;
int degree;
void dfsdown(int loc,int parent){
    lli ways[17][317];
    for(int i=0;i<=degree;i++)dp[loc][0][i]=0;
    dp[loc][0][degree]=1;
    for(int i=1;i<height;i++){
        for(int k=0;k<=degree;k++)ways[i][k]=0;
        ways[i][0]=1;
    }
    for(int x:matrix[loc]){
        if(x!=parent){
            dfsdown(x,loc);
            for(int i=0;i<height-1;i++){
                for(int j=degree;j>=1;j--) {
                    ways[i+1][j]=fix(ways[i+1][j]+(ways[i+1][j-1]*dp[x][i][degree]%mod));
                }
            }
        }
    }
    for(int i=1;i<height;i++) {
        for(int j=0;j<=degree;j++)dp[loc][i][j] = ways[i][j];
    }
}
void dfsup(int loc, int parent){
    if(loc!=1)for(int i=height-1;i>=0;i--){
        lli up=1;
        if(i) {
            up = fix(dp[parent][i][1] - dp[loc][i - 1][degree]);
            for (int j = 2; j <= degree; j++) {
                up = fix(dp[parent][i][j] - (up * dp[loc][i - 1][degree]%mod));
            }
        }
        for(int j=degree;j>=1;j--)dp[loc][i+1][j]=fix(dp[loc][i+1][j]+(up*dp[loc][i+1][j-1]%mod));
    }
    for(int x:matrix[loc]){
        if(x!=parent){
            dfsup(x,loc);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    fact[0]=1;
    inv[0]=1;
    for(lli i=1;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fastpow(fact[i],mod-2);
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    lli ans=n;
    int l3m=sqrt(n);
    for(int i=1;i<=n;i++)for(int j=l3m+1;j<=sz(matrix[i]);j++){
        ans=fix(ans+choose(sz(matrix[i]),j));
    }
    for(degree=2;degree<=l3m;degree++){
        height=log((double)n)/log((double)degree)+1;
        dfsdown(1,0),dfsup(1,0);
        for(int j=1;j<=n;j++){
            for(int l=1;l<height;l++)ans=fix(ans+dp[j][l][degree]);
        }
    }
    printf("%lli\n",ans);
    return 0;
}