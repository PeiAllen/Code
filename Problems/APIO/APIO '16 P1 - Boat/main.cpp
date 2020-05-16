#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=501;
lli mod=1e9+7;
inline lli fix(lli a){
    if(a>=mod)a-=mod;
    else if(a<0)a+=mod;
    return a;
}
lli fastpow(lli a, lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
pii arr[MAXN];
lli dp[2*MAXN][MAXN];
lli psa[2*MAXN][MAXN];
lli inv[MAXN];
lli precalc[2*MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> points;
    inv[0]=1;
    for(int i=1;i<=n;i++){
        inv[i]=fastpow(i,mod-2);
        cin>>arr[i].first>>arr[i].second;
        points.push_back(arr[i].first);
        points.push_back(arr[i].second+1);
    }
    sort(points.begin(),points.end());
    points.resize(unique(points.begin(),points.end())-points.begin());
    lli ans=0;
    for(int i=0;i<sz(points);i++)dp[i][0]=1,psa[i][0]=1;
    for(int i=1;i<sz(points);i++){
        precalc[i][0]=1;
        for(int j=1;j<=n;j++){
            precalc[i][j]=precalc[i][j-1]*((points[i] - points[i - 1] + j - 1)*inv[j]%mod)%mod;
        }
        for(int j=n;j>=1;j--){
            if(arr[j].first<=points[i-1]&&arr[j].second>=points[i]-1) {
                int numsch = 1;
                lli curcombo=precalc[i][numsch];
                for (int m = j - 1; m >= 0; m--) {
                    dp[i][j] = fix(dp[i][j] + (curcombo * psa[i - 1][m]%mod));
                    if (arr[m].first <= points[i - 1] && arr[m].second >= points[i]-1)numsch++,curcombo=precalc[i][numsch];
                }
                ans = fix(ans + dp[i][j]);
            }
            psa[i][j] = fix(psa[i - 1][j] + dp[i][j]);
        }
    }
    printf("%lli\n",ans);
    return 0;
}