#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
int arr[MN];
int tot[MN];
ll sumrange(ll a, ll b){
    return b*(b+1)/2-a*(a-1)/2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        tot[i]=max(tot[i-1],arr[i]+1);
    }
    vector<pii> deq={{0,INT_MAX}};
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=-1-arr[i];
        while(sz(deq)>1&&deq.back().second<=tot[i]-(i-deq.back().first)){
            ans-=sumrange(deq.back().second-(deq.back().first-deq[sz(deq)-2].first)+1,deq.back().second);
            deq.pop_back();
        }
        ans+=sumrange(tot[i]-(i-deq.back().first)+1,tot[i]);
        deq.push_back({i,tot[i]});
        printf("%lli%c",ans," \n"[i==n]);
    }
    return 0;
}