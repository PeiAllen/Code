#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll cnt[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    for(int i=0;i<26;i++)cnt[i]=1;
    for(auto x:a)cnt[x-'a']++;
    ll ans=1;
    for(int i=0;i<26;i++)ans=ans*cnt[i]%mod;
    printf("%lli\n",ans);
    return 0;
}