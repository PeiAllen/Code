#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
pii ans[MAXN];
int findSample(int n, int confidence[], int host[], int protocol[]){
    for(int i=0;i<n;i++)ans[i]={confidence[i],0};
    for(int i=n-1;i>=1;i--){
        if(protocol[i]==0)ans[host[i]]={ans[host[i]].first+ans[i].second,ans[host[i]].second+max(ans[i].first,ans[i].second)};
        else if(protocol[i]==1)ans[host[i]]={max({ans[host[i]].first+ans[i].first,ans[host[i]].first+ans[i].second,ans[host[i]].second+ans[i].first}),ans[host[i]].second+ans[i].second};
        else ans[host[i]]={max(ans[host[i]].first+ans[i].second,ans[host[i]].second+ans[i].first),ans[host[i]].second+ans[i].second};
    }
    return max(ans[0].first,ans[0].second);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}