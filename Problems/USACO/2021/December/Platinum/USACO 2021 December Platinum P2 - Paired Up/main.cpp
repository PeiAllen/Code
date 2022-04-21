#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=301;
ll dp[MN][MN][MN];//max sum of weights such that pairing for all cows <=i and <=j is done/they are determined, and all unpaired cows <=l are determined and fine with each other, with l most recently unpaired.
ll dp2[5001][5001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,n,k,b;
    char a;
    ll c;
    cin>>t>>n>>k;
    vector<pair<int,ll>> acow,bcow;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        if(a=='G')acow.push_back({b,c});
        else bcow.push_back({b,c});
    }
    if(t==1){
        for(int i=1;i<=sz(acow);i++)dp2[i][0]= dp2[i - 1][0] + acow[i - 1].second;
        for(int i=1;i<=sz(bcow);i++)dp2[0][i]= dp2[0][i - 1] + bcow[i - 1].second;
        for(int i=1;i<=sz(acow);i++){
            for(int j=1;j<=sz(bcow);j++){
                dp2[i][j]=LLONG_MAX;
                if(dp2[i - 1][j] != LLONG_MAX)dp2[i][j]=min(dp2[i][j], dp2[i - 1][j] + acow[i - 1].second);
                if(dp2[i][j - 1] != LLONG_MAX)dp2[i][j]=min(dp2[i][j], dp2[i][j - 1] + bcow[j - 1].second);
                if(abs(acow[i-1].first-bcow[j-1].first)<=k){
                    dp2[i][j]=min(dp2[i][j], dp2[i - 1][j - 1]);
                }
            }
        }
        printf("%lli\n", dp2[sz(acow)][sz(bcow)]);
    }
    else{
        for(int i=0;i<=sz(acow);i++) {
            for (int j = 0; j <= sz(bcow); j++) {
                for (int l = 0; l <= n; l++) {
                    dp[i][j][l]=LLONG_MIN;
                }
            }
        }
        dp[0][0][0]=0;
        for(int i=0;i<=sz(acow);i++){
            for(int j=0;j<=sz(bcow);j++){
                for(int l=0;l<=n;l++){
                    if(l!=0&&((l<=sz(acow)&&l>i)||(l>sz(acow)&&l>j+sz(acow))))continue;
                    if(dp[i][j][l]==LLONG_MIN)continue;
                    if(i<sz(acow)&&j<sz(bcow)&&abs(acow[i].first-bcow[j].first)<=k){
                        dp[i+1][j+1][l]=max(dp[i+1][j+1][l],dp[i][j][l]);
                    }
                    if(i<sz(acow)&&(l==0||l<=sz(acow)||(acow[i].first>bcow[l-sz(acow)-1].first&&abs(acow[i].first-bcow[l-sz(acow)-1].first)>k))){
                        dp[i+1][j][i+1]=max(dp[i+1][j][i+1],dp[i][j][l]+acow[i].second);
                    }
                    if(j<sz(bcow)&&(l==0||l>sz(acow)||(bcow[j].first>acow[l-1].first&&abs(acow[l-1].first-bcow[j].first)>k))){
                        dp[i][j+1][j+1+sz(acow)]=max(dp[i][j+1][j+1+sz(acow)],dp[i][j][l]+bcow[j].second);
                    }
                }
            }
        }
        printf("%lli\n", *max_element(dp[sz(acow)][sz(bcow)],dp[sz(acow)][sz(bcow)]+n+1));
    }
    return 0;
}