#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll dp[201][201][61][2];
ll arr[201];
ll psa[201];
ll m;
ll go(int l, int r, ll bit, bool atm){
    if(r<l)return 0;
    if(bit==-1&&l!=r)return -1e18;
    if(dp[l][r][bit][atm]!=LLONG_MIN)return dp[l][r][bit][atm];
    if(l==r){
        if(arr[l]<=0)return dp[l][r][bit][atm]=0;
        else{
            if(atm){
                while(bit>=0&&!(m&(ll(1)<<bit)))bit--;
                int cnt=0;
                for(int i=0;i<=bit;i++){
                    if(m&(ll(1)<<i))cnt++;
                }
                return dp[l][r][bit][atm]=arr[l]*max((ll)cnt,bit);
            }
            return dp[l][r][bit][atm]=arr[l]*(bit+1);
        }
    }
    if(atm&&!(m&(ll(1)<<bit)))return dp[l][r][bit][atm]=go(l,r,bit-1,atm);
    for(int i=l-1;i<=r;i++){
        dp[l][r][bit][atm]=max(dp[l][r][bit][atm],go(l,i,bit-1,0)+go(i+1,r,bit-1,atm)+psa[r]-psa[i]);
    }
    return dp[l][r][bit][atm];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i]=arr[i]+psa[i-1];
        for(int j=i;j<=n;j++){
            for(int k=0;k<=60;k++){
                for(int l=0;l<2;l++)dp[i][j][k][l]=LLONG_MIN;
            }
        }
    }
    printf("%lli\n",go(1,n,60,1));
    return 0;
}
