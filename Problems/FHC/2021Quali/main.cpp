#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=51;
int sparse[7][2*MN];
vector<int> adj[MN],leaves;
int st[MN],depth[MN],psa[MN],n,et,dp[MN][MN];
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<7;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
void dfs(int loc, int parent){
    depth[loc]=depth[parent]+1;
    psa[loc]+=psa[parent];
    sparse[0][et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc]){
        if(x!=parent)dfs(x,loc),sparse[0][et++]=loc;
    }
    if(SZ(adj[loc])-(parent>0)==0)leaves.push_back(loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("gold_mine_chapter_2_sample_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int a,b,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>psa[i],adj[i]=vector<int>();
        for(int i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        et=0,leaves=vector<int>();
        dfs(1,0),ms();
        dp[0][0]=psa[1];
        for(int i=1;i<=SZ(leaves);i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=0;
                for(int from=0;from<i;from++){
                    int val=(from==0?psa[leaves[i-1]]-psa[1]:psa[leaves[i-1]]-psa[getlca(leaves[from-1],leaves[i-1])]);
                    dp[i][j]=max(dp[i][j],dp[from][j-1]+val);
                }
            }
        }
        int best=0;
        for(int i=0;i<=SZ(leaves);i++){
            for(int j=0;j<=k;j++)best=max(best,dp[i][j]);
        }
        printf("Case #%d: %d\n",cs,best);
    }
    return 0;
}