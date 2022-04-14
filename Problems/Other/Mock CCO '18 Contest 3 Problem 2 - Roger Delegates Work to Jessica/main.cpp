#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
int arr[MN];
vector<pii> sorted;
int togo[MN];
bool gone[MN];
ll sum=0;
ll mi=0;
ll am=0;
void dfs(int loc){
    sum+=arr[loc];
    mi=min(mi,ll(arr[loc]));
    am++;
    gone[loc]=true;
    if(!gone[togo[loc]])dfs(togo[loc]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sorted.push_back({arr[i],i});
    }
    sort(sorted.begin(),sorted.end());
    for(int i=1;i<=n;i++){
        togo[sorted[i-1].second]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            sum=0,mi=INT_MAX,am=0;
            dfs(i);
            ans+=min(sum-mi+mi*(am-1),sum-mi+sorted[0].first*(am-1)+(sorted[0].first+mi)*2);
        }
    }
    printf("%lli\n",ans);
    return 0;
}