#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXT=2e4+1,MAXN=51,MAXS=51;
ll points[MAXT];
int resultspsa[MAXN][MAXT];
ll dp[MAXS][MAXT];
pair<ll,int> deq[MAXT];
pii range[MAXS][MAXT];
int l=0,r=-1;
int n,t,s;
int calc(int le, int ri){
    int am=0;
    for(int i=1;i<=n;i++){
        if(resultspsa[i][ri]-resultspsa[i][le]==ri-le)am++;
    }
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>t>>s;
    for(int i=1;i<=t;i++){
        cin>>points[i];
        points[i]+=points[i-1];
    }
    string a;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=1;j<=t;j++){
            resultspsa[i][j]=resultspsa[i][j-1];
            if(a[j-1]=='1')resultspsa[i][j]++;
        }
    }
    for(int k=0;k<=n;k++) {
        int left=0,right=-1;
        for (int i = 1; i <= t; i++) {
            while(right+1<=i-1&&calc(right+1,i)<=k)right++;
            while(left<=right&&calc(left,i)<k)left++;
            range[k][i]={left,right};
        }
    }
    for(int i=1;i<=t;i++)dp[0][i]=INT_MAX;
    dp[0][0]=0;
    for(int j=1;j<=s;j++){
        for(int i=0;i<=t;i++)dp[j][i]=INT_MAX;
        for(int k=0;k<=n;k++){
            l=0,r=-1;
            int right=-1;
            for(int i=1;i<=t;i++){
                while(right+1<=range[k][i].second){
                    right++;
                    ll val=dp[j-1][right]-ll(k)*points[right];
                    while(l<=r&&deq[r].first>=val)r--;
                    deq[++r]={val,right};
                }
                while(l<=r&&deq[l].second<range[k][i].first)l++;
                if(l<=r)dp[j][i]=min(dp[j][i],deq[l].first+ll(k)*points[i]);
            }
        }
        printf("%lli\n",dp[j][t]);
    }
    return 0;
}