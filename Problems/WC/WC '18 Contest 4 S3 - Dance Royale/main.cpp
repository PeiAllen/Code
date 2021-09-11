#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int to[MN];
int depth[MN];
int gone[MN];
ll cnt[MN];
pii dfs(int loc){
    if(gone[loc]!=-1)return {gone[loc],depth[loc]+1};
    gone[loc]=loc;
    pii te=dfs(to[loc]);
    gone[loc]=te.first,depth[loc]=te.second;
    return {gone[loc],depth[loc]+1};
}
map<int,ll> compile[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>to[i];
        if(to[i]==0)gone[i]=i;
        else gone[i]=-1;
    }
    for(int i=1;i<=m;i++)cin>>a,cnt[a]++;
    for(int i=1;i<=n;i++){
        if(gone[i]==-1)dfs(i);
        compile[gone[i]][depth[i]]+=cnt[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(gone[i]==i){
            if(to[i]==0){
                for(auto x:compile[i]){
                    ans+=x.second*(x.second-1)/2;
                }
            }
            else{
                int cyclelen=depth[i];
                map<int,ll> te;
                for(auto x:compile[i]){
                    te[x.first%cyclelen]+=x.second;
                }
                for(auto x:te){
                    ans+=x.second*(x.second-1)/2;
                }
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}