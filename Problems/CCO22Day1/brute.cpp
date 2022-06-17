#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=11;
pii arr[2][MN];
int n[2];
ll dp[MN][MN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n1,n2,k;
    cin>>n1>>n2>>k;
    n[0]=n1,n[1]=n2;
    for(int i=0;i<=1;i++)for(int j=0;j<n[i];j++){
        cin>>arr[i][j].first>>arr[i][j].second;
        arr[i][j].second--;
    }
    sort(arr[0],arr[0]+n[0]);
    sort(arr[1],arr[1]+n[1]);
    int ans=0;
    for(int i=0;i<(1<<(n1+n2));i++){
        vector<pll> timesa,timesb;
        for(int j=0;j<n1;j++){
            if(i&(1<<j)){
                timesa.push_back({arr[0][j].first,arr[0][j].second});
            }
        }
        for(int j=0;j<n2;j++){
            if(i&(1<<(j+n1))){
                timesb.push_back({arr[1][j].first,arr[1][j].second});
            }
        }
        dp[0][0][0]=0;
        dp[0][0][1]=k;
        for(int a=0;a<=sz(timesa);a++){
            for(int b=0;b<=sz(timesb);b++){
                if(a==0&&b==0)continue;
                dp[a][b][0]=dp[a][b][1]=INT_MAX;
                if(a>=1&&dp[a-1][b][0]!=INT_MAX&&dp[a-1][b][0]<=timesa[a-1].second){
                    dp[a][b][0]=min(dp[a][b][0],max(dp[a-1][b][0],timesa[a-1].first));
                }
                if(b>=1&&dp[a][b-1][1]!=INT_MAX&&dp[a][b-1][1]<=timesb[b-1].second){
                    dp[a][b][1]=min(dp[a][b][1],max(dp[a][b-1][1],timesb[b-1].first));
                }
                if(dp[a][b][0]!=INT_MAX)dp[a][b][1]=min(dp[a][b][1],dp[a][b][0]+k);
                if(dp[a][b][1]!=INT_MAX)dp[a][b][0]=min(dp[a][b][0],dp[a][b][1]+k);
            }
        }
        if(dp[sz(timesa)][sz(timesb)][0]!=INT_MAX||dp[sz(timesa)][sz(timesb)][1]!=INT_MAX)ans=max(ans,sz(timesa)+sz(timesb));
    }
    printf("%d\n",ans);
    return 0;
}