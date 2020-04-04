#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli dp[MAXN][450];
vector<string> dp2[MAXN][450];
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    dp[0][0]=1;
    dp2[0][0]={""};
    dp[1][1]=1;
    dp2[1][1]={"1^1"};
    for(int i=1;i<=n;i++){
        lli ans=dp[i][1];
        for(int j=2;j<=sqrt(2*i);j++){
            int cur=j;
            int pow=1;
            while(cur<=i){
                dp[i][j]=(dp[i][j]+dp[i-cur][j-1])%mod;
                for(auto x:dp2[i-cur][j-1]){
                    dp2[i][j].push_back(x+"+"+to_string(j)+"^"+to_string(pow));
                }
                pow++;
                cur*=j;
            }
            ans=(ans+dp[i][j])%mod;
        }
        cout<<"\n"<<ans<<" "<<i<<" solutions.\n";
        for(int j=1;j<=sqrt(2*i);j++)for (auto x:dp2[i][j])cout << x << "\n";
    }
    return 0;
}