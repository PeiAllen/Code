#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pair<int,ll>> matrix[MAXN];
vector<vector<vector<ll>>> sparse;
int depth[MAXN];
ll dist[MAXN];
ll dp[MAXN];
pii edge[MAXN];
int ind[MAXN];
int hind[MAXN];
int lowest[MAXN];
int highest[MAXN];
int par[MAXN];
bool shop[MAXN];
int sts[MAXN];
int curind=1;
int n,s,q,e;
int dfs(int loc, int parent){
    par[loc]=parent;
    sts[loc]=1;
    depth[loc]=depth[parent]+1;
    if(shop[loc])dp[loc]=0;
    else dp[loc]=1e17;
    for(auto x:matrix[loc]){
        if(x.first!=parent){
            dist[x.first]=dist[loc]+x.second;
            sts[loc]+=dfs(x.first,loc);
            dp[loc]=min(dp[loc],dp[x.first]+x.second);
        }
    }
    return sts[loc];
}
void gethld(int loc){
    sparse[ind[loc]][0].push_back(dp[loc]-dist[loc]);
    sort(matrix[loc].begin(),matrix[loc].end(),[&](auto lhs, auto rhs){
        return sts[rhs.first]<sts[lhs.first];
    });
    for(int i=(loc==e?0:1);i<sz(matrix[loc]);i++){
        if(i==(loc==e?0:1)){
            ind[matrix[loc][i].first]=ind[loc];
            hind[matrix[loc][i].first]=hind[loc]+1;
            lowest[ind[matrix[loc][i].first]]=matrix[loc][i].first;
        }
        else{
            ind[matrix[loc][i].first]=curind++;
            highest[ind[matrix[loc][i].first]]=matrix[loc][i].first;
            lowest[ind[matrix[loc][i].first]]=matrix[loc][i].first;
            hind[matrix[loc][i].first]=0;
            sparse.push_back({{}});
        }
        gethld(matrix[loc][i].first);
    }
}
void ms(int a){
    for(int i=0;i<sz(sparse[a][0]);i++){
        sparse[a][0][i]+=dist[lowest[a]];
    }
    sparse[a].resize(log2(sz(sparse[a][0]))+1);
    for(int i=1;i<=log2(sz(sparse[a][0]));i++){
        for(int j=0;j+(1<<(i-1))<sz(sparse[a][i-1]);j++){
            sparse[a][i].push_back(min(sparse[a][i-1][j],sparse[a][i-1][j+(1<<(i-1))]));
        }
    }
}
ll getmi(int a, int l, int r){
    int k=log2(r-l+1);
    return min(sparse[a][k][l],sparse[a][k][r-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>s>>q>>e;
    int a,b;
    ll c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        edge[i]={a,b};
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    for(int i=1;i<=s;i++){
        cin>>a;
        shop[a]=true;
    }
    dfs(e,0);
    for(int i=1;i<n;i++){
        if(depth[edge[i].first]>depth[edge[i].second])swap(edge[i].first,edge[i].second);
    }
    highest[0]=e;
    lowest[0]=e;
    sparse.push_back({{}});
    gethld(e);
    for(int i=0;i<curind;i++)ms(i);
    for(int i=1;i<=q;i++){
        cin>>b>>a;
        b=edge[b].second;
        if(depth[a]<depth[b]){
            printf("escaped\n");
            continue;
        }
        ll ans=dp[a];
        int te=a;
        bool escape=false;
        if(ind[te]==ind[b])ans=min(ans,getmi(ind[te],hind[b],hind[te])-(dist[lowest[ind[te]]]-dist[te]));
        else ans=min(ans,getmi(ind[te],0,hind[te])-(dist[lowest[ind[te]]]-dist[te]));
        if(ind[te]!=ind[b]&&ind[te]!=ind[e])te=par[highest[ind[te]]];
        while(ind[te]!=ind[b]){
            if(ind[te]==ind[e]){
                printf("escaped\n");
                escape=true;
                break;
            }
            ans=min(ans,getmi(ind[te],0,hind[te])-(dist[lowest[ind[te]]]-dist[te])+dist[a]-dist[te]);
            te=par[highest[ind[te]]];
        }
        if(!escape&&depth[te]<depth[b]){
            printf("escaped\n");
            escape=true;
        }
        if(!escape) {
            ans = min(ans, getmi(ind[te], hind[b], hind[te])-(dist[lowest[ind[te]]]-dist[te]) + dist[a] - dist[te]);
            if (ans >= 1e16)printf("oo\n");
            else printf("%lli\n", ans);
        }
    }
    return 0;
}