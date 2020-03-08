#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
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
lli dp[MAXN][17];
lli sum[MAXN][17];
int height;
void dfsdown(int loc,int parent){
    dp[loc][0]=1;
    sum[loc][0]=1;
    for(int i=1;i<height;i++)dp[loc][i]=0,sum[loc][i]=0;
    for(int x:matrix[loc]){
        if(x!=parent){
            dfsdown(x,loc);
            for(int i=0;i<height-1;i++){
                dp[loc][i+1]=fix(dp[loc][i+1]+(dp[x][i]*sum[loc][i]%mod));
                sum[loc][i]=fix(sum[loc][i]+dp[x][i]);
            }
        }
    }
}
void dfsup(int loc, int parent){
    for(int i=0;i<height-1;i++){
        lli up=fix(dp[parent][i]-(i?dp[loc][i-1]*fix(sum[parent][i-1]-dp[loc][i-1])%mod:(lli)0));
        dp[loc][i+1]=fix(dp[loc][i+1]+(up*sum[loc][i]%mod));
        sum[loc][i]=fix(sum[loc][i]+up);
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
    for(int i=2;i<=l3m;i++){
        height=log((double)n)/log((double)i)+1;
        dfsdown(1,0),dfsup(1,0);
        for(int j=1;j<=n;j++){
            for(int l=1;l<height;l++)ans=fix(ans+dp[j][l]);
        }
    }
    printf("%lli\n",ans);
    return 0;
}