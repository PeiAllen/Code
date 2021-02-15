#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll prev=LLONG_MAX;
    ll cur;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i<n-1)cin>>cur;
        else cur=LLONG_MAX;
        ans+=min(prev,cur);
        prev=cur;
    }
    printf("%lli\n",ans);
    return 0;
}