#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int mi[MN],n;
vector<pii> dp[MN];
int offset[MN];
int main(int argc, char *argv[]) {// same as given an array of values, make it sorted, can change any element to any element smaller.
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)mi[i]=n+1;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mi[a]=min(mi[a],b);
        mi[b]=min(mi[b],a);
    }
    dp[0].push_back({0,0});
    for(int i=2;i<=n;i++){
        vector<pii> toupdate;
        if(mi[i]>i-1){
            for(int k=0;(k<i-1||k==0);k++) {
                toupdate.push_back({k,(sz(dp[k]))?dp[k].back().second+offset[k] + 1:n+1});
            }
        }
        else{
            for(int k=0;(k<i-1||k==0)&&k<mi[i];k++) {
                toupdate.push_back({k,(sz(dp[k]))?dp[k].back().second+offset[k]:n+1});
            }
        }
        if(i==2)dp[0]=vector<pii>(),offset[0]=0;
        dp[i-1]=vector<pii>(),offset[i-1]=0;
        sort(toupdate.begin(),toupdate.end());
        for(auto x:toupdate){
            if(!sz(dp[i-1])||dp[i-1].back().second>x.second)dp[i-1].push_back(x);
        }
        for(int j=1;j<i-1;j++){
            if(mi[i]>j){
                offset[j]++;
            }
            else {
                while(sz(dp[j])&&dp[j].back().first>=min(mi[i],max(0,j-1)+1))dp[j].pop_back();
            }
        }
    }
    int best=n+1;
    for(int j=0;j<=n;j++)best=min(best,(sz(dp[j]))?dp[j].back().second+offset[j] :n+1);
    assert(best!=n+1);
    printf("%d\n",best);
    return 0;
}