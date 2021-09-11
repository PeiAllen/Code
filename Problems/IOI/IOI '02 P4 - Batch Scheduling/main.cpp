#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+2;
ll tpsa[MN],fpsa[MN],fsuf[MN],dp[MN];
int l,r;
pll deq[MN];
ll overcome(pll a, pll b){
    return (b.second-a.second+(a.first-b.first-1))/(a.first-b.first);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>tpsa[i]>>fpsa[i];
        tpsa[i]+=tpsa[i-1],fpsa[i]+=fpsa[i-1];
    }
    dp[n+1]=0;
    l=0,r=-1;
    deq[++r]={tpsa[n]+s,dp[n+1]+fsuf[n+1]*s+(tpsa[n]+s)*fpsa[n]};
    for(int i=n;i>=1;i--){
        fsuf[i]=fsuf[i+1]+fpsa[i]-fpsa[i-1];
        while(r-l>=1&&deq[l+1].first*-fpsa[i-1]+deq[l+1].second<=deq[l].first*-fpsa[i-1]+deq[l].second)l++;
        dp[i]=deq[l].first*-fpsa[i-1]+deq[l].second;
        pll cur={tpsa[i-1]+s,dp[i]+fsuf[i]*s+(tpsa[i-1]+s)*fpsa[i-1]};
        while(r-l>=1&&overcome(deq[r],deq[r-1])>=overcome(cur,deq[r]))r--;
        deq[++r]=cur;
    }
    printf("%lli\n",dp[1]);
    return 0;
}