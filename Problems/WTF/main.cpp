#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll dp[5001][5001];
ll arr[5001];
int n,q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            ll ans=0;
            for(int k=i;k<=j;k++){
                ll optiona=arr[k]+(k-2>=0?dp[i][k-2]:0)+(k+1<=j?dp[k+1][j]:0);
                ll optionb=arr[k]+(k-1>=0?dp[i][k-1]:0)+(k+2<=j?dp[k+2][j]:0);
                ll taken;
                if(k-1<i){
                    if(k+1>j){
                        if(optiona<optionb)taken=optiona;
                        else taken=optionb;
                    }
                    else taken=optionb;
                }
                else{
                    if(k+1>j){
                        taken=optiona;
                    }
                    else{
                        if(optiona<optionb)taken=optiona;
                        else taken=optionb;
                    }
                }
                ans=max(ans,taken);
            }
            dp[i][j]=ans;
        }
    }
    printf("%lli\n",dp[1][n]);
    while(q--){
        n++;
        cin>>arr[n];
        for(int i=n;i>=1;i--){
            int j=n;
            ll ans=0;
            for(int k=i;k<=j;k++){
                ll optiona=arr[k]+(k-2>=0?dp[i][k-2]:0)+(k+1<=j?dp[k+1][j]:0);
                ll optionb=arr[k]+(k-1>=0?dp[i][k-1]:0)+(k+2<=j?dp[k+2][j]:0);
                ll taken;
                if(k-1<i){
                    if(k+1>j){
                        if(optiona<optionb)taken=optiona;
                        else taken=optionb;
                    }
                    else taken=optionb;
                }
                else{
                    if(k+1>j){
                        taken=optiona;
                    }
                    else{
                        if(optiona<optionb)taken=optiona;
                        else taken=optionb;
                    }
                }
                ans=max(ans,taken);
            }
            dp[i][j]=ans;
        }
        printf("%lli\n",dp[1][n]);
    }
    return 0;
}