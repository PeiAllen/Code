#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int dp[MN][2];
int suffix[MN];
map<int,pii> mist;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> ends={-1};
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ends.push_back(b);
        if(mist.count(b))mist[b].first=min(mist[b].first,a),mist[b].second=max(mist[b].second,a);
        else mist[b]={a,a};
    }
    sort(ends.begin(),ends.end()),ends.erase(unique(ends.begin(),ends.end()),ends.end());
    set<int> starts;
    for(int i=sz(ends)-1;i>=1;i--)suffix[i]=min((i+1<sz(ends)?suffix[i+1]:INT_MAX),mist[ends[i]].first);
    multiset<int> froms={INT_MAX};
    int last=1;
    for(int i=1;i<sz(ends);i++){
        starts.insert(mist[ends[i]].second);
        while(ends[last]<=*starts.rbegin())froms.erase(froms.find(dp[last][0])),last++;
        dp[i][0]=dp[upper_bound(ends.begin(),ends.end(),suffix[i])-ends.begin()-1][1]+1;
        dp[i][1]=min(dp[i][0],*froms.begin());
        froms.insert(dp[i][0]);
    }
    printf("%d\n",dp[sz(ends)-1][1]);
    return 0;
}