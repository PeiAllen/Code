#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll dp[3];//sum of lengths of all starting positions that have last character as this
ll am[3];//number of starting locations that have last character as this
map<char,int> conver={{'F',0},{'O',1},{'X',2}};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("weak_typing_chapter_2_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int n;
        string a;
        cin>>n>>a;
        ll ans=0;
        am[0]=0,am[1]=0,am[2]=0;
        dp[0]=0,dp[1]=0,dp[2]=0;
        for(auto x:a){
            if(x=='F'){
                am[0]=(am[0]+1)%mod;
            }
            else{
                ll te=(dp[conver[x]]+am[0]+dp[(conver[x]==1?2:1)]+am[(conver[x]==1?2:1)]+1)%mod;
                dp[0]=dp[1]=dp[2]=0;
                dp[conver[x]]=te;
                te=(am[0]+am[1]+am[2]+1)%mod;
                am[0]=am[1]=am[2]=0;
                am[conver[x]]=te;
            }
            ans=(ans+dp[1]-am[1]+mod+dp[2]-am[2]+mod)%mod;
        }
        printf("Case #%d: %lli\n",cs,ans);
    }
    return 0;
}