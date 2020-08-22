#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll dp[19][11][11][2];
string a,b;
string te;
ll go(int pos, int secondlast, int last, bool ma){
    if(pos==sz(te))return 1;
    if(dp[pos][secondlast][last][ma]!=-1)return dp[pos][secondlast][last][ma];
    ll ans=0;
    for(int i=0;i<=(ma?te[pos]-'0':9);i++){
        if(i!=secondlast&&i!=last)ans+=go(pos+1,last,((last==10&&i==0)?10:i),ma&&(te[pos]-'0'==i));
    }
    return dp[pos][secondlast][last][ma]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>a>>b;
    a=to_string(stoll(a)-1);
    memset(dp,-1,sizeof(dp));
    te=b;
    ll la=go(0,10,10,true);
    ll sm;
    if(a=="-1"){
        sm=0;
    }
    else {
        memset(dp, -1, sizeof(dp));
        te = a;
        sm=go(0, 10, 10, true);
    }
    printf("%lli\n",la-sm);
    return 0;
}