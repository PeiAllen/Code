#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int pre[MN],suf[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string p,s,t;
    cin>>p>>s>>t;
    string a=p+s;
    for(int i=1,l=0,r=0;i<sz(a);i++){
        if(i<=r)pre[i]=min(r-i+1,pre[i-l]);
        while(pre[i]+i<sz(a)&&a[pre[i]]==a[pre[i]+i])pre[i]++;
        if(pre[i]+i-1>r)l=i,r=pre[i]+i-1;
    }
    a=t+s;
    for(int i=1,l=0,r=0;i<sz(a);i++){
        if(i<=r)suf[i]=min(r-i+1,suf[i-l]);
        while(suf[i]+i<sz(a)&&a[suf[i]]==a[suf[i]+i])suf[i]++;
        if(suf[i]+i-1>r)l=i,r=suf[i]+i-1;
    }
    int last=-1;
    multiset<int> vals;
    int best=0;
    for(int i=0;i<sz(s);i++){
        while(last<i+pre[i+sz(p)]-1)last++,vals.insert(suf[last+sz(t)]);
        best=max(best,)
        vals.erase(vals.find(suf[i+sz(t)]-i));
    }
    return 0;
}