#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4e5+1;
int sufarr[MAXN];
int ans[MAXN];
pair<pii,int> identity[MAXN];
int n;
void reindex(){
    sort(identity,identity+n+1);
    int last=0;
    sufarr[identity[0].second]=last;
    for(int i=1;i<=n;i++)last+=(identity[i].first!=identity[i-1].first),sufarr[identity[i].second]=last;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    n=sz(a);
    a.push_back('$');
    for(int i=0;i<=n;i++)identity[i]={{a[i]-'a',0},i};
    reindex();
    for(int i=1;i<n;i*=2){
        for(int j=0;j<=n;j++)identity[j]={{sufarr[j],sufarr[(j+i)%(n+1)]},j};
        reindex();
    }
    for(int i=0;i<=n;i++)ans[sufarr[i]]=i;
    for(int i=0;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}