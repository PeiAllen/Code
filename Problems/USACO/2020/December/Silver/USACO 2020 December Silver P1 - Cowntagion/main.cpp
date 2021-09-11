#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++)cin>>a>>b,cnt[a]++,cnt[b]++;
    int ans=__lg(cnt[1]+1-1)+1+cnt[1];
    for(int i=2;i<=n;i++)ans+=(cnt[i]-1==0?-1:__lg(cnt[i]-1))+1+cnt[i]-1;
    printf("%d\n",ans);
    return 0;
}