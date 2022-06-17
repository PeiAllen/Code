#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=12;
const ll mod=1e9+7;
ll dp[2][(1<<MN)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    char a;
    dp[0][0]=1;
    int cur=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            for(int mask=0;mask<(1<<m);mask++){
                dp[cur][mask]=0;
                if(j>0&&(mask&(1<<j))&&(mask&(1<<(j-1))))continue;
                if((mask&(1<<j))&&a=='0')continue;
                dp[cur][mask]+=dp[!cur][mask&((1<<m)-1-(1<<j))];
                if(!(mask&(1<<j)))dp[cur][mask]+=dp[!cur][mask+(1<<j)];
                dp[cur][mask]%=mod;
            }
            cur=!cur;
        }
    }
    ll ans=0;
    for(int mask=0;mask<(1<<m);mask++){
        ans+=dp[!cur][mask];
    }
    printf("%lli\n",ans%mod);
    return 0;
}