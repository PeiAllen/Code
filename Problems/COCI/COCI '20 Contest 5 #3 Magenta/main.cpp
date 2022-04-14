#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pii> adj[MN];
int conver(string a){
    if(a=="plava")return 1;
    if(a=="crvena")return 2;
    return 3;
}
int dist[MN];
int cnt[3];
int a,b;
bool dfs(int loc, int dis){
    dist[loc]=dis;
    if(loc==b)return true;
    for(auto x:adj[loc]){
        if(dist[x.first]!=-1)continue;
        if(x.second==1)cnt[1]++;
        if(x.second==2)cnt[2]++;
        if(dfs(x.first,dis+1))return true;
        if(x.second==1)cnt[1]--;
        if(x.second==2)cnt[2]--;
    }
    return false;
}
pii parent[MN];
void root(int loc, int par){
    for(auto x:adj[loc]){
        if(x.first!=par){
            parent[x.first]={loc,x.second};
            root(x.first,loc);
        }
    }
}
bool checkifposs(int loc, int type){
    bool good=false;
    for(auto x:adj[loc]){
        if(x.first!=parent[loc].first&&(x.second&type))good=true;
    }
    if(parent[loc].second==type&&good){
        return true;
    }
    for(auto x:adj[loc]){
        if(x.first!=parent[loc].first&&(x.second&type)&&checkifposs(x.first,type)){
            return true;
        }
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>a>>b;
    int l,r;
    string s;
    for(int i=1;i<n;i++){
        cin>>l>>r>>s;
        adj[l].push_back({r,conver(s)});
        adj[r].push_back({l,conver(s)});
    }
    bool bada=true,badb=true;
    for(auto x:adj[a]){
        if((x.second&1)&&x.first!=b)bada=false;
    }
    for(auto x:adj[b]){
        if(x.second&2)badb=false;
    }
    if(bada){
        printf("Marin\n");
        return 0;
    }
    if(badb){
        printf("Paula\n");
        return 0;
    }
    fill(dist,dist+n+1,-1);
    dfs(a,0);
    if(dist[b]%2==1){//marin is playing for win
        root(b,0);
        int best=a;
        for(int steps=0;steps<dist[b]/2&&(parent[best].second&1);steps++)best=parent[best].first;
        if(checkifposs(best,1)){
            printf("Magenta\n");
        }
        else{
            if(cnt[1]==0)printf("Marin\n");
            else if(cnt[1]>=2)printf("Magenta\n");
            else if(cnt[1]==1&&parent[a].second!=1)printf("Magenta\n");
            else printf("Marin\n");//this case is covered by checkifposs
        }
    }
    else{//paula is playing for win
        root(a,0);
        int best=b;
        for(int steps=0;steps<(dist[b]-1)/2&&(parent[best].second&2);steps++)best=parent[best].first;
        if(checkifposs(best,2)){
            printf("Magenta\n");
        }
        else{
            if(cnt[2]==0)printf("Paula\n");
            else if(cnt[2]>=2)printf("Magenta\n");
            else if(cnt[2]==1&&parent[b].second!=2)printf("Magenta\n");
            else printf("Paula\n");//this case is covered by checkifposs
        }
    }
    return 0;
}