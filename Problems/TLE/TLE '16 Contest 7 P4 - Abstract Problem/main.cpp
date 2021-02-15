#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int dp[100][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        vector<ll> bits;
        while(a>0){
            bits.push_back(a%2);
            a/=2;
        }
        reverse(bits.begin(),bits.end());
        dp[0][0]=0,dp[0][1]=2;
        for(int i=1;i<=sz(bits);i++){
            if(bits[i-1]){
                dp[i][1]=dp[i-1][1];
                dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1;
            }
            else{
                dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
                dp[i][0]=dp[i-1][0];
            }
        }
        printf("%d\n",dp[sz(bits)][0]+sz(bits)-1);
    }
    return 0;
}