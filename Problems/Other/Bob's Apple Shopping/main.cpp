#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
ll mi[2*MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int v;
    ll w;
    for(int i=1;i<2*MAXN;i++)mi[i]=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>v>>w;
        for(int j=v;j<2*MAXN;j++){
            mi[j]=min(mi[j],(mi[j-v]==LLONG_MAX?LLONG_MAX:mi[j-v]+w));
        }
    }
    ll ans=LLONG_MAX;
    for(int j=m;j<2*MAXN;j++)ans=min(ans,mi[j]);
    printf("%lli\n",ans);
    return 0;
}