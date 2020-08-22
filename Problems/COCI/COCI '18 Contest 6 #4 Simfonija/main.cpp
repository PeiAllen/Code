#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
ll arr[MAXN];
vector<ll> diffs;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll a;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        diffs.push_back(arr[i]-a);
    }
    sort(diffs.begin(),diffs.end());
    for(int i=0;i<n-k;i++){
        sum+=diffs[i]-diffs[0];
    }
    ll ans=LLONG_MAX;
    int l=0,r=n-k;
    for(int i=0;i<n;i++){
        if(i) {
            sum += (diffs[i] - diffs[i - 1]) * ll(i - l);
            sum -= (diffs[i] - diffs[i - 1]) * ll(r - i);
        }
        while(r<n&&abs(diffs[l]-diffs[i])>=abs(diffs[r]-diffs[i])){
            sum+=abs(diffs[r]-diffs[i]);
            sum-=abs(diffs[l]-diffs[i]);
            r++,l++;
        }
        ans=min(ans,sum);
    }
    printf("%lli\n",ans);
    return 0;
}