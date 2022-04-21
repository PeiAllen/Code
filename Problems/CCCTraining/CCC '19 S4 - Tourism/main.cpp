#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
int sparse[__lg(MN)+1][MN];
int n,k;
void ms(){
    for(int i=1;i<=__lg(n);i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getmax(int l, int r){
    int lg=__lg(r-l+1);
    return max(sparse[lg][l],sparse[lg][r-(1<<lg)+1]);
}
ll dp[2][MN];
int extradays;
ll calc(int j, int i, int day, int cur){
    return dp[!cur][j]+getmax((day-1)*k-j+1,day*k-i);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i],sparse[0][i]=arr[i];
    ms();
    if(k==n){
        printf("%lli\n",getmax(1,n));
        return 0;
    }
    extradays=(k-(n%k))%k;
    for(int i=0;i<=extradays;i++){
        dp[0][i]=getmax(1,k-i);
    }
    int cur=1;
    for(int day=2;day*k<n;day++){
        function<void(int,int,int,int)> solve=[&](int l, int r, int lans, int rans)->void{
            if(l==r){
                ll best=0;
                for(int i=lans;i<=min(l,rans);i++){
                    best=max(best,calc(i,l,day,cur));
                }
                dp[cur][l]=best;
                return;
            }
            int mid=(l+r)/2;
            ll best=0;
            int bestj=-1;
            for(int i=lans;i<=min(mid,rans);i++){
                if(calc(i,mid,day,cur)>best){
                    best=calc(i,mid,day,cur),bestj=i;
                }
            }
            solve(l,mid,lans,bestj),solve(mid+1,r,bestj,rans);
        };
        solve(0,extradays,0,extradays);
        cur=!cur;
    }
    ll ans=0;
    for(int i=0;i<=extradays;i++){
        ans=max(ans,dp[!cur][i]+getmax((n-1)/k*k-i+1,n));
    }
    printf("%lli\n",ans);
    return 0;
}