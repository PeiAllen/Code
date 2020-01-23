#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int MAXW=301;
const int MAXWT=5e4+1;
vector<lli> items[MAXW];
lli dp[MAXW][MAXWT];
int deq[MAXW][MAXWT];
int l[MAXW],r[MAXW];
int n,w;
lli calc(int i, int j, int p){
    return dp[i-1][p]+items[i][min((int)items[i].size()-1,(j-p)/i)];
}
int inter(int i, int a, int b){
    int lo=a,hi=w;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(calc(i,mid,a)>=calc(i,mid,b))hi=mid;
        else lo=mid+1;
    }
    if(calc(i,lo,a)<calc(i,lo,b))return lo+1;
    return lo;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>w;
    int a;
    lli b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        items[a].push_back(b);
    }
    for(int i=1;i<=300;i++){
        sort(items[i].begin(),items[i].end(),greater<lli>());
        items[i].insert(items[i].begin(),0);
        for(int j=1;j<(int)items[i].size();j++)items[i][j]+=items[i][j-1];
        for(int j=0;j<i;j++) {
            l[j] = 0;
            r[j] = -1;
            deq[j][++r[j]] = 0;
        }
        for(int j=1;j<=w;j++){
            int jm=j%i;
            while (r[jm] - l[jm] >= 1 && inter(i, deq[jm][r[jm]], deq[jm][r[jm] - 1]) >= inter(i, j, deq[jm][r[jm]]))r[jm]--;
            deq[jm][++r[jm]]=j;
            while(r[jm]-l[jm]>=1&&calc(i,j,deq[jm][l[jm]])<=calc(i,j,deq[jm][l[jm]+1]))l[jm]++;
            dp[i][j]=max(dp[i][j-1],calc(i,j,deq[jm][l[jm]]));
        }
    }
    for(int i=1;i<=w;i++)printf("%lli ",dp[300][i]);
    return 0;
}