#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
vector<int> matrix[MAXN];
int sts[MAXN];
pii bestdown[MAXN][2];
lli sumdown[MAXN];
int bestup[MAXN];
lli ans[MAXN];
int n;
int dfs(int loc, int parent){
    sts[loc]=1;
    bestdown[loc][0]={0,-1};
    bestdown[loc][1]={0,-1};
    for(int x:matrix[loc]){
        if(x!=parent){
            sts[loc]+=dfs(x,loc);
            sumdown[loc]+=sumdown[x]+sts[x];
            if(bestdown[x][0].first+1>bestdown[loc][0].first){
                bestdown[loc][1]=bestdown[loc][0];
                bestdown[loc][0]={bestdown[x][0].first+1,x};
            }
            else if(bestdown[x][0].first+1>bestdown[loc][1].first){
                bestdown[loc][1]={bestdown[x][0].first+1,x};
            }
        }
    }
    return sts[loc];
}
void dfs2(int loc, int parent){
    if(parent)bestup[loc]=max(bestup[parent]+1,(bestdown[parent][0].second==loc?bestdown[parent][1].first+1:bestdown[parent][0].first+1));
    if(parent)sumdown[loc]+=sumdown[parent]-(sumdown[loc]+sts[loc])+n-sts[loc];
    int am=n-1;
    bool done=false;
    if(sts[loc]==n-sts[loc]){
        ans[loc]=2*sumdown[loc]-(bestup[loc]);
        done=true;
    }
    else if(n-sts[loc]>sts[loc])ans[loc]=-1,done=true;
    for(int x:matrix[loc]){
        if(x!=parent){
            if(am-sts[x]+1==sts[x]){
                ans[loc]=2*sumdown[loc]-(bestdown[x][0].first+1);
                done=true;
            }
            else if(sts[x]>am-sts[x]+1)ans[loc]=-1,done=true;
        }
    }
    if(!done){
        ans[loc]=2*sumdown[loc]-max(bestdown[loc][0].first,bestup[loc]);
    }
    for(int x:matrix[loc])if(x!=parent)dfs2(x,loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)printf("%lli\n",ans[i]);
    return 0;
}