#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
template<typename T>
ll sz(const T &a){return (ll)a.size();}
ll dp[50001][4][11];//number of ways at curloc with type is x
map<char,ll> conver={{'A',0},{'C',1},{'G',2},{'T',3}};
char bconver[4]={'A','C','G','T'};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll m,k;
    ll r;
    cin>>m>>k>>r;
    string s;
    cin>>s;
    for(ll i=1;i<11;i++)dp[sz(s)][3][i]=1;
    for(ll i=sz(s)-1;i>=0;i--){
        for(ll j=0;j<=3;j++){
            if(s[i]=='N'||conver[s[i]]==j)for(ll l=1;l<=k;l++){
                    for(ll j2=0;j2<=3;j2++){
                        if(l-(j2<j)>=1)dp[i][j][l]+=dp[i+1][j2][l-(j2<j)];
                    }
                }
        }
    }
    ll prevletter=0;
    for(ll i=0;i<sz(s);i++){
        if(s[i]=='N'){
            for(ll j=0;j<=3;j++){
                if(k-(j<prevletter)>=1&&dp[i][j][k-(j<prevletter)]>=r){
                    k-=(j<prevletter);
                    prevletter=j;
                    cout<<bconver[j];
                    break;
                }
                else if(k-(j<prevletter)>=1){
                    r-=dp[i][j][k-(j<prevletter)];
                }
            }
        }
        else{
           k-=(conver[s[i]]<prevletter);
            prevletter=conver[s[i]];
            cout<<s[i];
        }
    }
    cout<<"\n";
    return 0;
}