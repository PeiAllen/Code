#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1,MAXV=1e6;
pii dp[MAXN][7][3];
int dir(int a, int b){
    if(a==b)return 0;
    if(a<b)return 1;
    return 2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    cin>>a;
    vector<int> nodes;
    nodes.resize(a);
    while(a--)cin>>nodes[a],nodes[a]--;
    for(int i=0;i<7;i++)for(int j=0;j<=2;j++)dp[0][i][j]={MAXV,0};
    for(auto x:nodes)for(int i=0;i<=2;i++)dp[0][x][i]={0,0};
    for(int i=1;i<n;i++){
        cin>>a;
        nodes.resize(a);
        while(a--)cin>>nodes[a],nodes[a]--;
        for(int j=0;j<7;j++)for(int k=0;k<=2;k++)dp[i][j][k]={MAXV,0};
        for(auto x:nodes)for(int j=0;j<7;j++)for(int k=0;k<=2;k++){
            dp[i][x][dir(j,x)]=min(dp[i][x][dir(j,x)],{dp[i-1][j][k].first+abs(j-x),dp[i-1][j][k].second+(dir(j,x)!=k)});
        }
    }
    pii ans={MAXV,0};
    for(int i=0;i<7;i++)for(int j=0;j<=2;j++)ans=min(ans,dp[n-1][i][j]);
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}