#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e4+1;
vector<int> adj[MN];
int par[MN],dep[MN];
ll value[MN];
ll cnt[MN];
ll k;
vector<vector<vector<ll>>> dp;
int firstbad[MN][2];
ll solvedp(int j, int aloc, ll (*a)(int,int),int amin, int amax, int bloc, ll (*b)(int,int), int bmin, int bmax){
    int lo=max(amin,j-bmax),hi=min(amax,j-bmin);
    if(lo>hi)return LLONG_MIN;
    else {
        auto calc=[&](int am){
            if(am<0||am>j||am<=amin||am>=amax||j-am<=bmin||j-am>=bmax)return LLONG_MIN;
            return a(aloc,j)+b(bloc,j-am);
        };
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (calc(mid) <= calc(mid + 1))lo = mid + 1;
            else hi = mid;
        }
        return calc(lo);
    }
}
void dfs(int loc){
    dp[loc][0][0]=0;
    firstbad[loc][0]=1;
    firstbad[loc][1]=0;
    for(auto x:adj[loc]){
        dfs(x);
        int first=k+1;
        for(int j=k;j>=0;j--){
            ll bestresult=LLONG_MIN;
            bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][1][a];},0,firstbad[loc][1]-1,x,[](int loc,int a){return dp[loc][0][a];},0,firstbad[x][0]-1));
            bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][0][a];},0,firstbad[loc][0]-1,x,[](int loc,int a){return dp[loc][1][a];},0,firstbad[x][1]-1));
            dp[loc][1][j]=bestresult;
            if(dp[loc][1][j]==LLONG_MIN)first=j;
        }
        firstbad[loc][1]=first;
        first=k+1;
        for(int j=k;j>=0;j--) {
            ll bestresult=LLONG_MIN;
            bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][0][a];},0,firstbad[loc][0]-1,x,[](int loc,int a){return dp[loc][0][a];},0,firstbad[x][0]-1));
            dp[loc][0][j]=bestresult;
            if(dp[loc][0][j]==LLONG_MIN)first=j;
        }
        firstbad[loc][0]=first;
    }
    int first=k+1;
    for(int j=k;j>=0;j--){
        ll bestresult=LLONG_MIN;
        bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][1][a];},0,firstbad[loc][1]-1,loc,[](int loc,int a){return a*value[loc]+value[loc];},0,cnt[loc]-1));
        bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][0][a];},0,firstbad[loc][0]-1,loc,[](int loc,int a){return a*value[loc]+value[loc];},0,cnt[loc]-1));
        dp[loc][1][j]=bestresult;
        if(dp[loc][1][j]==LLONG_MIN)first=j;
    }
    firstbad[loc][1]=first;
    first=k+1;
    for(int j=k;j>=0;j--) {
        ll bestresult=LLONG_MIN;
        bestresult=max(bestresult,solvedp(j,loc,[](int loc,int a){return dp[loc][0][a];},0,firstbad[loc][0]-1,loc,[](int loc,int a){return a*value[loc];},0,cnt[loc]));
        dp[loc][0][j]=bestresult;
        if(dp[loc][0][j]==LLONG_MIN)first=j;
    }
    firstbad[loc][0]=first;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        int madepth=1;
        bool vsubtask=true;
        for(int i=1;i<=n;i++){
            adj[i]=vector<int>();
            cin>>par[i]>>cnt[i]>>value[i];
            adj[par[i]].push_back(i);
            if(value[i]!=1)vsubtask=false;
            dep[i]=dep[par[i]]+1;
            madepth=max(madepth,dep[i]);
        }
        if(madepth==2){
            ll amtake=min(cnt[1],k+1);
            ll ans=amtake*value[1];
            amtake=k+1;
            ll cur=value[1];
            cnt[1]--;
            cnt[1]=min(cnt[1],amtake-1);
            vector<int> ord;
            for(int i=1;i<=n;i++){
                ord.push_back(i);
            }
            sort(ord.begin(),ord.end(),[&](const int &lhs, const int &rhs){
                return value[lhs]>value[rhs];
            });
            for(auto x:ord){
                ll totake=min(amtake,cnt[x]);
                cur+=totake*value[x];
                amtake-=totake;
            }
            printf("%lli\n",max(ans,cur));
            continue;
        }
        if(vsubtask){
            ll amtake=k+madepth;
            ll tot=0;
            for(int i=1;i<=n;i++){
                tot+=cnt[i];
            }
            printf("%lli\n",min(tot,amtake));
            continue;
        }
        dp=vector<vector<vector<ll>>>();
        dp.resize(n+1,vector<vector<ll>>(2,vector<ll>(k+1,LLONG_MIN)));
        dfs(1);
        ll best=0;
        for(int a=0;a<2;a++) {
            for (int i = 0; i <= k; i++) {
                best=max(best,dp[1][a][i]);
            }
        }
        printf("%lli\n",best);
    }
    return 0;
}