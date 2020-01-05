#include<bits/stdc++.h>
#include "grader.h"
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int lift[MAXN][17];
int depth[MAXN];
pii coords[MAXN];
int sts[MAXN];
int leftset;
int upset;
//void setFarmLocation(int loc, int x, int y){prl(loc,x,y);}
//int getN(){return 6;}
//void addBox(int x, int y, int x2, int y2){prl(x,y,x2,y2);}
int dfs(int loc, int parent, int dep){
    lift[loc][0]=parent;
    depth[loc]=dep;
    sts[loc]=1;
    for(int x:matrix[loc])if(x!=parent)sts[loc]+=dfs(x,loc,dep+1);
    return sts[loc];
}
void setboxes(int loc, int parent){
    coords[loc].first=leftset+sts[loc];
    coords[loc].second=++upset;
    setFarmLocation(loc-1,coords[loc].first,coords[loc].second);
    for(int x:matrix[loc])if(x!=parent)setboxes(x,loc);
    leftset=coords[loc].first;
}
void ml(){
    int n=getN();
    rep(i,1,17)rep(j,1,n+1)lift[j][i]=lift[lift[j][i-1]][i-1];
}
int getlca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    rep(i,0,17)if(diff&(1<<i))a=lift[a][i];
    if(a==b)return a;
    for(int i=16;i>=0;i--)if(lift[a][i]!=lift[b][i])a=lift[a][i],b=lift[b][i];
    return lift[a][0];
}
void addRoad(int a, int b){
    a++,b++;
    matrix[a].push_back(b);
    matrix[b].push_back(a);
}

void buildFarms(){
    dfs(1,0,0);
    ml();
    setboxes(1,0);
}

void notifyFJ(int a, int b){
    prl("");
    a++,b++;
    int lca=getlca(a,b);
    if(lca==a||lca==b){
        if(a==lca)swap(a,b);
        addBox(min(coords[a].first,coords[lca].first),min(coords[a].second,coords[lca].second),max(coords[a].first,coords[lca].first),max(coords[a].second,coords[lca].second));
        return;
    }
    if(coords[a].first>coords[b].first)swap(a,b);
    addBox(min(coords[a].first,coords[lca].first-1),min(coords[a].second,coords[lca].second+1),max(coords[a].first,coords[lca].first-1),max(coords[a].second,coords[lca].second+1));
    addBox(min(coords[b].first,coords[lca].first),min(coords[b].second,coords[lca].second),max(coords[b].first,coords[lca].first),max(coords[b].second,coords[lca].second));
}
//int main(){
//    addRoad(0,1);
//    addRoad(1,2);
//    addRoad(1,3);
//    addRoad(3,4);
//    addRoad(0,5);
//    buildFarms();
//    notifyFJ(0,0);
//    notifyFJ(0,4);
//    notifyFJ(0,3);
//    notifyFJ(1,5);
//    notifyFJ(1,4);
//    notifyFJ(2,3);
//}
