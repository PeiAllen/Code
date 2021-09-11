#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll MAXV=1e12;
ll dp[301][301][(1<<8)];
vector<pair<int,ll>> to[2];
int n,k;
int finallength(int l, int r){
    return (r-l)%(k-1)+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    string s;
    cin>>s;
    int a;
    ll val;
    for(int i=0;i<(1<<k);i++){
        cin>>a>>val;
        to[a].push_back({i,val});
    }
    for(int i=0;i<n;i++)dp[i][i][s[i]-'0']=0,dp[i][i][!(s[i]-'0')]=-MAXV;
    for(int len=2;len<=n;len++){
        for(int l=0;l+len<=n;l++){
            int r=l+len-1;
            int curlen=finallength(l,r);
            for(int final=(1<<curlen)-1;final>=0;final--){
                dp[l][r][final]=-MAXV;
                if(curlen==1){
                    for(auto x:to[final]){
                        for(int mid=r-1;mid>=l;mid-=k-1){
                            if(finallength(l,mid)==k-1&&finallength(mid+1,r)==1)dp[l][r][final]=max(dp[l][r][final],x.second+dp[l][mid][x.first>>1]+dp[mid+1][r][x.first&1]);
                        }
                    }
                }
                else{
                    for(int mid=r-1;mid>=l;mid-=k-1){
                        if(finallength(l,mid)==curlen-1&&finallength(mid+1,r)==1)dp[l][r][final]=max(dp[l][r][final],dp[l][mid][final>>1]+dp[mid+1][r][final&1]);
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int final=(1<<finallength(0,n-1))-1;final>=0;final--)ans=max(ans,dp[0][n-1][final]);
    printf("%lli\n",ans);
    return 0;
}