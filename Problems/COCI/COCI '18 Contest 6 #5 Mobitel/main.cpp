#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll dp[301][301][1001];
int rnk[1001],val[1001];
ll mod=1e9+7;
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,s,n;
    cin>>r>>s>>n;
    vector<int> rnks;
    for(int i=1;i<n;i++)rnks.push_back(n/i);
    rnks.push_back(0);
    reverse(rnks.begin(),rnks.end());
    rnks.erase(unique(rnks.begin(),rnks.end()),rnks.end());
    rnks[n]=0;
    val[0]=n;
    for(int i=1;i<n;i++){
        rnk[i]=lower_bound(rnks.begin(),rnks.end(),n/i)-rnks.begin();
        val[rnk[i]]=i;
    }
    int cur;
    for(int i=0;i<r;i++)for(int j=0;j<s;j++){
        cin>>cur;
        cur=min(cur,n);
        if(i==0&&j==0)dp[i][j][rnk[cur]]=1;
        else {
            for (int k = 0; k <= rnk[(val[0]+cur-1) / cur]; k++) {
                if(i!=0)dp[i][j][0]=fix(dp[i][j][0]+dp[i-1][j][k]);
                if(j!=0)dp[i][j][0]=fix(dp[i][j][0]+dp[i][j-1][k]);
            }
            for (int k = 1; k < sz(rnks); k++) {
                if(rnk[(val[k]+cur-1)/cur*cur]==k) {
                    if (i != 0&&rnk[val[k] / cur*cur]==k)dp[i][j][k] = fix(dp[i][j][k] + dp[i - 1][j][rnk[val[k] / cur]]);
                    if (j != 0&&rnk[val[k] / cur*cur]==k)dp[i][j][k] = fix(dp[i][j][k] + dp[i][j - 1][rnk[val[k] / cur]]);
                }
            }
        }
    }
    printf("%lli\n",dp[r-1][s-1][0]);
    return 0;
}