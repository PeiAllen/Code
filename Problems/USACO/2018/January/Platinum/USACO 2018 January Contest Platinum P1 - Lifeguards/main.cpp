#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
const int MAXK=101;
lli dp[MAXN][MAXK][2];
pll arr[MAXN];
int deq[MAXK][MAXN];
int le[MAXK],ri[MAXK];
int n,k;
int interpoint(int j, int a, int b){
    int lo=0,hi=n;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(j+(mid-b-1)<=k&&max(dp[a][j+(mid-a-1)][0],dp[a][j+(mid-a-1)][1])-max(arr[mid].first,arr[a].second)<=max(dp[b][j+(mid-b-1)][0],dp[b][j+(mid-b-1)][1])-max(arr[mid].first,arr[b].second))hi=mid;
        else lo=mid+1;
    }
    if(j+(lo-b-1)<=k&&max(dp[a][j+(lo-a-1)][0],dp[a][j+(lo-a-1)][1])-max(arr[lo].first,arr[a].second)<=max(dp[b][j+(lo-b-1)][0],dp[b][j+(lo-b-1)][1])-max(arr[lo].first,arr[b].second))return lo;
    return lo+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,k);
    rep(i,0,k+1)dp[0][i][0]=-INT_MAX,dp[0][i][1]=-INT_MAX,ri[i]=-1,deq[i][++ri[i]]=0;
    rep(i,1,n+1)sc(arr[i].first,arr[i].second);
    sort(arr+1,arr+n+1,[](const auto& lhs, const auto &rhs){
        if(lhs.second==rhs.second)return lhs.first<rhs.first;
        return lhs.second<rhs.second;
    });
    dp[0][k][0]=0;
    rep(i,1,n+1){
        rep(j,0,k+1){
            dp[i][j][0]=-INT_MAX;
            if(j<k)dp[i][j][0]=max(dp[i-1][j+1][0],dp[i-1][j+1][1]);
            dp[i][j][1]=-INT_MAX;
            while(ri[j]-le[j]>=1&&j+(i-deq[j][le[j]+1]-1)<=k&&max(dp[deq[j][le[j]+1]][j+(i-deq[j][le[j]+1]-1)][0],dp[deq[j][le[j]+1]][j+(i-deq[j][le[j]+1]-1)][1])+arr[i].second-max(arr[i].first,arr[deq[j][le[j]+1]].second)>=max(dp[deq[j][le[j]]][j+(i-deq[j][le[j]]-1)][0],dp[deq[j][le[j]]][j+(i-deq[j][le[j]]-1)][1])+arr[i].second-max(arr[i].first,arr[deq[j][le[j]]].second))le[j]++;
            if(j+(i-deq[j][le[j]]-1)<=k)dp[i][j][1]=max(dp[deq[j][le[j]]][j+(i-deq[j][le[j]]-1)][0],dp[deq[j][le[j]]][j+(i-deq[j][le[j]]-1)][1])+arr[i].second-max(arr[i].first,arr[deq[j][le[j]]].second);
                while (ri[j] - le[j] >= 1 && interpoint(j, deq[j][ri[j]], i) <= interpoint(j, deq[j][ri[j] - 1],deq[j][ri[j]]))ri[j]--;
                deq[j][++ri[j]] = i;
        }
    }
    prl(max(dp[n][0][0],dp[n][0][1]));
    return 0;
}
//max(dp[a][j+(i-a-1)][0],dp[a][j+(i-a-1)][1])-max(arr[i].first,arr[a].second)<=max(dp[b][j+(i-b-1)][0],dp[b][j+(i-b-1)][1])-max(arr[i].first,arr[b].second),a<b, b is better forever
//max(dp[a][j+(i-a-1)][0],dp[a][j+(i-a-1)][1])-max(arr[i].first,arr[a].second)<=max(dp[b][j+(i-b-1)][0],dp[b][j+(i-b-1)][1])-max(arr[i].first,arr[b].second)