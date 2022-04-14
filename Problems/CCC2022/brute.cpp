#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll arr[MN];
vector<int> adj[MN];
bool done[MN];
bool vis[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        done[i]=(s[i-1]=='Y');
    }
    for(int i=1;i<=n;i++)cin>>arr[i];
    ll best=1e16;
    for(int mask=0;mask<(1<<n);mask++){
        ll ans=0;
        queue<int> q;
        for(int i=1;i<=n;i++){
            vis[i]=false;
            if(done[i])vis[i]=true;
            if(mask&(1<<(i-1))){
                ans+=arr[i];
                if(done[i]){
                    q.push(i);
                }
            }
        }
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            for(auto x:adj[cur]){
                if(!vis[x]){
                    vis[x]=true;
                    if(mask&(1<<(x-1))){
                        q.push(x);
                    }
                }
            }
        }
        bool work=true;
        for(int i=1;i<=n;i++){
            if(!vis[i])work=false;
        }
        if(work)best=min(best,ans);
    }
    printf("%lli\n",best);
    return 0;
}