#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
set<pii> locs;
int dist(pii a, pii b){
    a.second=abs(a.second),b.second=abs(b.second);
    int ans=b.first-a.first+abs(a.second-b.second);
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    int x,y;
    locs.insert({1,1});
    for(int i=0;i<n;i++){
        cin>>x>>y;
        pii te={x,(x%2==1?y:-y)};
        auto it=locs.lower_bound(te);
        pii before=*prev(it,1);
        ans+=dist(before,te);
        if(it!=locs.end())ans-=dist(before,*it),ans+=dist(te,*it);
        locs.insert(te);
        printf("%d\n",ans);
    }
    return 0;
}