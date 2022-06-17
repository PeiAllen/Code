#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
vector<int> sau[MN];
ll dp[4];
ll choose(ll a, ll b){
    assert(b==4);
    if(a<4)return 0;
    return __int128(a)*(a-1)*(a-2)*(a-3)/4/3/2/1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],sau[arr[i]].push_back(i);
    ll ans=0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(i!=j){
                dp[0]=dp[1]=dp[2]=dp[3]=0;
                for(int lptr=0,rptr=0;lptr<sz(sau[i])||rptr<sz(sau[j]);){
                    if(lptr<sz(sau[i])&&(rptr==sz(sau[j])||sau[i][lptr]<sau[j][rptr])){
                        dp[3]+=dp[2];
                        dp[0]++;
                        lptr++;
                    }
                    else{
                        dp[2]+=dp[1];
                        dp[1]+=dp[0];
                        rptr++;
                    }
                }
                ans+=dp[3];
            }
        }
        ans+=choose(sz(sau[i]),4);
    }
    printf("%lli\n",ans);
    return 0;
}