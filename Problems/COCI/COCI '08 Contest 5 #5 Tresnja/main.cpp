#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int vals[17];
pll dp[17][2][10][17];
pll go(int digit, bool max, int last, int am){
    if(digit==-1)return {0,1};
    if(dp[digit][max][last][am].second!=-1)return dp[digit][max][last][am];
    pll cur={0,0};
    for(int i=0;i<=(max?vals[digit]:9);i++){
        pll te=go(digit-1,max&&i==vals[digit],i,1+(i==last?am:0));
        cur.second+=te.second;
        cur.first+=te.first+te.second*(i==last?i*(2*am+1):i);
    }
    return dp[digit][max][last][am]=cur;
}
void clear(){
    for(int i=0;i<17;i++){
        vals[i]=0;
        for(int j=0;j<2;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<17;l++){
                    dp[i][j][k][l]={-1,-1};
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string b;
    ll ate;
    cin>>ate>>b;
    ate--;
    string a=to_string(ate);
    ll ans=0;
    clear();
    for(int i=0;i<sz(b);i++)vals[i]=b[sz(b)-i-1]-'0';
    ans+=go(16,1,0,0).first;
    clear();
    for(int i=0;i<sz(a);i++)vals[i]=a[sz(a)-i-1]-'0';
    ans-=go(16,1,0,0).first;
    printf("%lli\n",ans);
    return 0;
}