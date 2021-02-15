#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
ll dp[MAXN];
vector<pii> combined;
ll toup[MAXN];
pair<ll,int> deq[MAXN];
int n,st,loc,deql,deqr;
ll amstff=0;
ll getsegment(){
    ll presum=0;
    deql=0,deqr=-1;
    amstff=loc-st;
    for(int i=loc-1;i>=st;i--){
        presum+=combined[loc-1].first-combined[i].first;
        toup[loc-i]=min(dp[i],dp[i-1])+presum;
        ll val=min(dp[i],dp[i-1])+presum+ll(loc-i)*ll(combined[loc].first-combined[loc-1].first);
        while(deql<=deqr&&deq[deqr].first>=val)deqr--;
        deq[++deqr]={val,loc-i};
    }
    st=loc;
    return presum;
}
ll min_total_length(vector<int> r, vector<int> b){
    combined.push_back({0,0});
    for(int i=0,j=0;i<sz(r)||j<sz(b);){
        if(j==sz(b)||(i<sz(r)&&r[i]<b[j]))combined.push_back({r[i],0}),i++;
        else combined.push_back({b[j],1}),j++;
    }
    n=sz(combined),loc=1,st=1;
    while(combined[loc].second==combined[st].second)dp[loc++]=LLONG_MAX;
    ll masum=getsegment();
    for(;loc<n&&combined[loc].second==combined[st].second;loc++)masum+=combined[loc].first-combined[st].first,dp[loc]=masum+ll(combined[st].first-combined[st-1].first)*max(amstff,ll(loc-st+1));
    getsegment();
    while(loc<n){
        ll bestsecond=LLONG_MAX;
        ll presum=0;
        for(;loc<n&&combined[loc].second==combined[st].second;loc++){
            presum+=combined[loc].first-combined[st].first;
            if(loc-st+1<=amstff)bestsecond=min(bestsecond,toup[loc-st+1]);
            while(deql<=deqr&&deq[deql].second<=loc-st+1)deql++;
            dp[loc]=min(bestsecond+presum+ll(combined[st].first-combined[st-1].first)*ll(loc-st+1),(deql<=deqr?deq[deql].first+presum:LLONG_MAX));
        }
        getsegment();
    }
    return dp[n-1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("%lli\n",min_total_length({0,1,2,3,6}, {7,8,9,100}));
    return 0;
}