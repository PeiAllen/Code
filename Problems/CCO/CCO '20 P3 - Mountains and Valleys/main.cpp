#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=500001;
int dp[21][(1<<20)];
vector<pii> matrix[MAXN];
int olddist[21][21];
int dist[MAXN];
int parent[MAXN];
bool gone[MAXN];
int n,m;
int solve(int loc, int state){
    if(__builtin_popcount(state)==1){
        if(state&(1<<loc))return 0;
        assert(0);
        return 2*n;
    }
    if(dp[loc][state]!=-1)return dp[loc][state];
    int ans=2*n;
    for(int i=0;i<n;i++){
        if(i!=loc&&(state&(1<<i))){
            ans=min(ans,solve(i,state-(1<<loc))+olddist[i][loc]);
        }
    }
    return dp[loc][state]=ans;
}
void dfsdis(int loc, int par, int dis){
    dist[loc]=dis;
    parent[loc]=par;
    for(auto x:matrix[loc])if(x.first!=par)dfsdis(x.first,loc,dis+1);
}
int getdia(){
    dfsdis(0,-1,0);
    int onedia=max_element(dist,dist+n)-dist;
    dfsdis(onedia,-1,0);
    return *max_element(dist,dist+n);
}
int dfsdep(int loc, int dep){
    int ans=dep;
    gone[loc]=true;
    for(auto x:matrix[loc]){
        if(!gone[x.first]){
            ans=max(ans,dfsdep(x.first,dep+1));
        }
    }
    return ans;
}
int sfg(int a, int b, int c){
    vector<int> cycle;
    vector<int> te;
    while(a!=b){
        if(dist[a]>=dist[b]){
            cycle.push_back(a);
            a=parent[a];
        }
        else{
            te.push_back(b);
            b=parent[b];
        }
    }
    cycle.push_back(a);
    for(int i=sz(te)-1;i>=0;i--)cycle.push_back(te[i]);
    for(auto x:cycle)gone[x]=true;
    int ans=INT_MAX;
    vector<int> longdep;
    for(auto x:cycle)longdep.push_back(dfsdep(x,0));
    int ma=-2*n;
    for(int i=0;i<2*sz(cycle);i++){
        ma=max(ma-(i==0||i==sz(cycle)?c:1),(i%sz(cycle)==0||i%sz(cycle)==sz(cycle)-1?-2*n:longdep[i%sz(cycle)]));
        if(!(i%sz(cycle)==0||i%sz(cycle)==sz(cycle)-1))ans=min(ans,2*(n-1)-(sz(cycle)-1)+c-(ma+longdep[(i+1)%sz(cycle)])-1);
    }
    for(int i=0;i<sz(cycle);i++){
        ans=min(ans,2*(n-1)-(sz(cycle)-1)+c-longdep[i]);
        if(i!=0)ans=min(ans,2*(n-1)-(sz(cycle)-1)+c-longdep[0]-longdep[i]-max(1-(i-1),c-(sz(cycle)-i-1)));
    }
    reverse(cycle.begin(),cycle.end());
    for(int i=0;i<sz(cycle);i++){
        if(i!=0)ans=min(ans,2*(n-1)-(sz(cycle)-1)+c-longdep[0]-longdep[i]-max(1-(i-1),c-(sz(cycle)-i-1)));
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    if(n<=20){
        int a,b,c;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            matrix[a].push_back({b,c});
            matrix[b].push_back({a,c});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)olddist[i][j]=INT_MAX;
            priority_queue<pii,vector<pii>,greater<>> q;
            olddist[i][i]=0;
            q.push({0,i});
            while(sz(q)){
                auto cur=q.top();
                q.pop();
                if(olddist[i][cur.second]>=cur.first){
                    for(auto x:matrix[cur.second]){
                        if(x.second+cur.first<olddist[i][x.first]){
                            olddist[i][x.first]=x.second+cur.first;
                            q.push({olddist[i][x.first],x.first});
                        }
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)dp[i][j]=-1;
        for(int i=0;i<n;i++)ans=min(ans,solve(i,(1<<n)-1));
        printf("%d\n",ans);
    }
    else{
        vector<pair<pii,int>> extraedges;
        int a,b,c;
        int miedge=INT_MAX;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            if(c==1) {
                matrix[a].push_back({b, c});
                matrix[b].push_back({a, c});
            }
            else{
                extraedges.push_back({{a,b},c});
                miedge=min(miedge,c);
            }
        }
        if(c>=(n+1)/2) {
            int ans = 2 * (n - 1) - getdia();
            for (auto x:extraedges) {
                ans = min(ans, sfg(x.first.first, x.first.second, x.second));
            }
            printf("%d\n", ans);
        }
        else{
            int ans = 2 * (n - 1) - getdia();
            for(int i=0;i<sz(extraedges);i++){
                for(int j=i+1;j<sz(extraedges);j++){

                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}