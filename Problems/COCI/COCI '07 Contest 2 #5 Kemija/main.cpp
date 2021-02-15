#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e4+1;
ll arr[MAXN],ans[MAXN];
int fix(int a, int mod){
    return ((a%mod)+mod)%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n%3){
        for(int i=3;i!=0;i=(i+3)%n)ans[i]=arr[fix(i-1,n)]-arr[fix(i-2,n)]+ans[fix(i-3,n)];
        ll totsumarr=accumulate(arr,arr+n,ll(0)),totsumans=accumulate(ans,ans+n,ll(0));
        ll needed=(totsumarr/3-totsumans)/n;
        for(int i=0;i<n;i++)printf("%lli\n",ans[i]+needed);
    }
    else{
        for(int st=0;st<3;st++){
            ans[st]=1;
            ll mi=1;
            for(int i=st+3;i<n;i+=3)ans[i]=arr[i-1]-arr[i-2]+ans[i-3],mi=min(mi,ans[i]);
            for(int i=st;i<n;i+=3)ans[i]+=1-mi;
        }
        for(int st=0;st<3;st++) {
            ll inc = arr[st] - ans[st] - ans[fix(st-1,n)] - ans[fix(st+1,n)];
            for (int i = st; i < n; i += 3)ans[i] += inc;
        }
        for(int i=0;i<n;i++)printf("%lli\n",ans[i]);
    }
    return 0;
}