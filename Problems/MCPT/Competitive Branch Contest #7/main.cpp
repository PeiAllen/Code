#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int dp[3001];
lli arr[3001];
lli type[3001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli m,c;
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)cin>>type[i];
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        lli cursize=0;
        set<int> types;
        for(int j=1;j<=i;j++){
            types.insert(type[i-j+1]);
            cursize+=arr[i-j+1];
            if(cursize>=m&&cursize<=c){
                dp[i]=max(dp[i],dp[i-j]==-1?-1:dp[i-j]+sz(types));
            }
        }
    }
    if(dp[n]==-1)printf("FIRED\n");
    else printf("%d\n",dp[n]);
    return 0;
}