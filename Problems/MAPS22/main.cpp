#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+5;
int arr[MN];
int adj[MN];
int indeg[MN];
int good[MN];
int vis[MN];
vector<int> radj[MN];
bool incyc[MN];
int dfs(int loc){
    if(vis[loc]==2){
        return -1;
    }
    if(vis[loc]==1)return loc;
    vis[loc]++;
    int te=dfs(adj[loc]);
    vis[loc]++;
    return te;
}
int cnt[MN];
int nodeval[MN];
int tot=0;
void getans(int loc){
    cnt[nodeval[loc]]++;
    if(cnt[nodeval[loc]]==1)tot++;
    good[loc]=tot;
    for(auto x:radj[loc]){
        getans(x);
    }
    cnt[nodeval[loc]]--;
    if(cnt[nodeval[loc]]==0)tot--;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vals;
    for(int i=1;i<=n;i++){
        good[i]=-1;
        cin>>arr[i];
        vals.push_back(arr[i]);
        adj[i]=max(0,min(n+1,arr[i]+i));
        radj[max(0,min(n+1,arr[i]+i))].push_back(i);
        indeg[max(0,min(n+1,arr[i]+i))]++;
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=1;i<=n;i++){
        nodeval[i]=lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin();
    }
    good[0]=0;
    good[n+1]=0;
    vis[0]=vis[n+1]=2;
    ll ans=0;
    vector<pair<vector<int>,vector<int>>> rev;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int cycleend=dfs(i);
            if(cycleend!=-1){
                int cur=adj[cycleend];
                vector<int> nodes={cycleend};
                while(cur!=cycleend){
                    nodes.push_back(cur);
                    cur=adj[cur];
                }
                vector<int> am;
                for(auto x:nodes)am.push_back(nodeval[x]);
                sort(am.begin(),am.end());
                am.erase(unique(am.begin(),am.end()),am.end());
                for(auto x:nodes){
                    incyc[x]=true;
                    good[x]=sz(am);
                }
                rev.push_back({{},nodes});
                for(auto x:nodes){
                    for(auto y:radj[x]){
                        if(!incyc[y]){
                            rev.back().first.push_back(y);
                        }
                    }
                }
            }
        }
    }
    for(auto x:radj[0]){
        getans(x);
    }
    for(auto x:radj[n+1]){
        getans(x);
    }

    for(auto x:rev){
        int root=-1;
        for(auto y:x.second){
            root=y;
            cnt[nodeval[y]]++;
            if(cnt[nodeval[y]]==1)tot++;
        }
        for(auto y:x.first){
            getans(y);
        }
        for(auto y:x.second){
            cnt[nodeval[y]]--;
            if(cnt[nodeval[y]]==0)tot--;
        }
    }
    for(int i=1;i<=n;i++)ans+=good[i];
    printf("%lli\n",ans);
    return 0;
}