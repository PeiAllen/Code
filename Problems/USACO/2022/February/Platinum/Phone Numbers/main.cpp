#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll mod=1e9+7;
set<vector<int>> good;
int arr[3][3];
ll dp[MN][2];
ll dp2[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=num++;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i+1<3)good.insert({arr[i][j],arr[i+1][j]});
            if(j+1<3)good.insert({arr[i][j],arr[i][j+1]});
            if(i+1<3&&j+1<3)good.insert({arr[i][j],arr[i][j+1],arr[i+1][j],arr[i+1][j+1]});
        }
    }
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int n=sz(a);
        a="$"+a;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){//dcba
            for(int j=0;j<2;j++) {
                dp[i][j]=0;
                ll extra = 0;
                vector<int> te2, te4;
                if (i - 1 >= 1) {
                    te2.push_back(a[i] - '0');
                    te2.push_back(a[i - 1] - '0');
                }
                if (i - 3 >= 1) {
                    te4.push_back(a[i] - '0');
                    te4.push_back(a[i - 1] - '0');
                    te4.push_back(a[i - 2] - '0');
                    te4.push_back(a[i - 3] - '0');
                }
                sort(te2.begin(), te2.end()), sort(te4.begin(), te4.end());
                bool two=good.count(te2)||j;
                bool four=good.count(te4);
                if (four) {//end with c or d
                    dp[i][j] = (dp[i][j] + dp[i - 4][0] * ll(12) % mod) % mod;
                }
                if (four&&two) {//end with b
                    dp[i][j]=(dp[i][j]+dp[i-2][1]+dp[i-4][0]*ll(4)%mod)%mod;
                }
                else if(four){
                    dp[i][j]=(dp[i][j]+dp[i-4][0]*ll(6)%mod)%mod;
                }
                else if(two){
                    dp[i][j]=(dp[i][j]+dp[i-2][0])%mod;
                }
                if(four){//end with a
                    dp[i][j]=(dp[i][j]+dp2[i-1])%mod;
                }
                else{
                    dp[i][j]=(dp[i][j]+dp[i-1][0])%mod;
                }
            }
            dp2[i]=0;
            ll extra = 0;
            vector<int> te2, te4;
            if (i - 1 >= 1) {
                te2.push_back(a[i] - '0');
                te2.push_back(a[i - 1] - '0');
            }
            if (i - 3 >= 1) {
                te4.push_back(a[i] - '0');
                te4.push_back(a[i - 1] - '0');
                te4.push_back(a[i - 2] - '0');
                te4.push_back(a[i - 3] - '0');
            }
            sort(te2.begin(), te2.end()), sort(te4.begin(), te4.end());
            bool two=good.count(te2);
            bool four=good.count(te4);
            if (four) {//end with d
                dp2[i] = (dp2[i] + dp[i - 4][0] * ll(6) % mod) % mod;
            }
            if(four){//end with c
                dp2[i]=(dp2[i]+dp[i-3][0]*ll(2)%mod)%mod;
                dp2[i]=(dp2[i]+dp[i-4][0]*ll(4)%mod)%mod;
            }
            else{
                dp2[i]=(dp2[i]+dp[i-3][0]*ll(2)%mod)%mod;
            }
            if (four&&two) {//end with b
                dp2[i]=(dp2[i]+dp[i-2][1])%mod;
                dp2[i]=(dp2[i]+dp[i-3][0]%mod)%mod;
                dp2[i]=(dp2[i]+dp[i-4][0]*ll(3)%mod)%mod;
            }
            else if(four){
                dp2[i]=(dp2[i]+dp[i-3][0]*ll(2)%mod)%mod;
                dp2[i]=(dp2[i]+dp[i-4][0]*ll(4)%mod)%mod;
            }
            else if(two){
                dp2[i]=(dp2[i]+dp[i-2][0])%mod;
                dp2[i]=(dp2[i]+dp[i-3][0]%mod)%mod;
            }
            else{
                dp2[i]=(dp2[i]+dp[i-3][0]*ll(2)%mod)%mod;
            }
            if(four){//end with a
                dp2[i]=(dp2[i]+dp2[i-1])%mod;
                dp2[i]=(dp2[i]+dp[i-3][0])%mod;
                dp2[i] = (dp2[i] - dp[i - 4][0] + mod) % mod;
            }
            else{
                dp2[i]=(dp2[i]+dp[i-1][1])%mod;
            }
        }
        printf("%lli\n",dp[n][0]);
    }
    return 0;
}