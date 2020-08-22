#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
int par[MAXN];
int depth[MAXN];
vector<int> matrix[MAXN];
int l,r,x;
int dontgo;
ll dfs(ll a){
    ll te=0;
    if(a>=l&&a<=r)te++;
    for(auto x:matrix[a])if(x!=dontgo)te+=dfs(x);
    return te;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    depth[0]=1;
    for(int i=1;i<n;i++){
        cin>>par[i];
        depth[i]=depth[par[i]]+1;
        matrix[par[i]].push_back(i);
    }
    while(q--){
        cin>>l>>r>>x;
        ll ans=0;
        dontgo=0;
        while(x!=0){
            ans+=depth[x]*dfs(x);
            dontgo=x;
            x=par[x];
        }
        ans+=depth[x]*dfs(x);
        printf("%lli\n",ans);
    }
    return 0;
}