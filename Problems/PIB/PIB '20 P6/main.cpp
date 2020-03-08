#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
struct block{
    vector<lli> arr;
    lli pre;
    int ind;
    block(){
        arr={},pre=LLONG_MIN,ind=0;
    }
};
vector<block> sarr[2];
int mbs;
int n,q;
lli arr[MAXN];
vector<int> matrix[MAXN];

lli sumdown[MAXN];
lli sumup[MAXN];
pair<lli,int> maxdown[MAXN][2];
lli maxup[MAXN];
int parent[MAXN];
vector<pair<pii,int>> queries[MAXN];
lli ans[MAXN];
int getblock(int t,lli x){
    return (upper_bound(sarr[t].begin(),sarr[t].end(),x,[&](auto val, auto cur){
        return val<cur.pre;
    })-sarr[t].begin())-1;
}
void repre(int t,int loc){
    for(;loc<sz(sarr[t]);loc++)sarr[t][loc].ind=sarr[t][loc-1].ind+sz(sarr[t][loc-1].arr);
}
void insert(int t,lli x){
    int loc=getblock(t,x);
    sarr[t][loc].arr.insert(lower_bound(sarr[t][loc].arr.begin(),sarr[t][loc].arr.end(),x),x);
    if(sz(sarr[t][loc].arr)>=2*mbs){
        sarr[t].insert(sarr[t].begin()+loc+1,block());
        sarr[t][loc+1].arr.insert(sarr[t][loc+1].arr.begin(),sarr[t][loc].arr.begin()+mbs,sarr[t][loc].arr.end());
        sarr[t][loc].arr.resize(mbs);
        sarr[t][loc+1].pre=sarr[t][loc+1].arr[0];
    }
    if(loc!=0)sarr[t][loc].pre=sarr[t][loc].arr[0];
    repre(t,loc+1);
}
void erase(int t,lli x){
    int loc=getblock(t,x);
    sarr[t][loc].arr.erase(lower_bound(sarr[t][loc].arr.begin(),sarr[t][loc].arr.end(),x));
    if(sz(sarr[t][loc].arr)==0&&sz(sarr[t])>1){
        sarr[t].erase(sarr[t].begin()+loc);
        if(loc==0)sarr[t][loc].pre=LLONG_MIN,sarr[t][loc].ind=0;
        else sarr[t][loc].ind=sarr[t][loc-1].ind+sz(sarr[t][loc-1].arr);
    }
    if(loc!=0)sarr[t][loc].pre=sarr[t][loc].arr[0];
    repre(t,loc+1);
}
lli query(int t,int x){
    int loc=(upper_bound(sarr[t].begin(),sarr[t].end(),x,[&](auto val, auto cur){
        return val<cur.ind;
    })-sarr[t].begin())-1;
    x-=sarr[t][loc].ind;
    return sarr[t][loc].arr[x];
}
void dfsdown(int loc, int par){
    parent[loc]=par;
    sumdown[loc]=arr[loc];
    maxdown[loc][0]={arr[loc],loc};
    maxdown[loc][1]={LLONG_MIN,-1};
    for(int x:matrix[loc]){
        if(x!=par){
            dfsdown(x,loc);
            sumdown[loc]+=sumdown[x];
            if(maxdown[x][0].first>=maxdown[loc][0].first){
                maxdown[loc][1]=maxdown[loc][0];
                maxdown[loc][0]={maxdown[x][0].first,x};
            }
            else if(maxdown[x][0].first>=maxdown[loc][1].first)maxdown[loc][1]={maxdown[x][0].first,x};
        }
    }
    insert(0,sumdown[loc]);
    insert(1,maxdown[loc][0].first);
}
void dfsup(int loc, int par){
    maxup[loc]=max(arr[loc],max(maxup[par],(maxdown[par][0].second==loc?maxdown[par][1].first:maxdown[par][0].first)));
    sumup[loc]=arr[loc]+sumup[par]+sumdown[par]-sumdown[loc]-arr[par];
    for(int x:matrix[loc])if(x!=par)dfsup(x,loc);
}
void dfs(int loc, int par){
    erase(0,sumdown[loc]);
    insert(0,sumdown[loc]+sumup[loc]-arr[loc]);
    erase(1,maxdown[loc][0].first);
    insert(1,max(maxdown[loc][0].first,maxup[loc]));
    for(auto x:queries[loc])ans[x.second]=query(x.first.first,n-x.first.second);
    erase(0,sumdown[loc]+sumup[loc]-arr[loc]);
    erase(1,max(maxdown[loc][0].first,maxup[loc]));
    for(int x:matrix[loc]){
        if(x!=par){
            insert(0,sumup[loc]+sumdown[loc]-arr[loc]-sumdown[x]);
            insert(1,max(maxup[loc],(maxdown[loc][0].second==x?maxdown[loc][1].first:maxdown[loc][0].first)));
            dfs(x,loc);
            erase(1,max(maxup[loc],(maxdown[loc][0].second==x?maxdown[loc][1].first:maxdown[loc][0].first)));
            erase(0,sumup[loc]+sumdown[loc]-arr[loc]-sumdown[x]);
        }
    }
    insert(0,sumdown[loc]);
    insert(1,maxdown[loc][0].first);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    mbs=sqrt(n);
    sarr[0]={block()},sarr[1]={block()};
    for(int i=1;i<=n;i++)cin>>arr[i];
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfsdown(1,0);
    sumdown[0]=sumdown[1];
    maxdown[0][0]={LLONG_MIN,-1};
    maxdown[0][1]={LLONG_MIN,-1};
    maxup[0]=LLONG_MIN;
    dfsup(1,0);
    int c;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        queries[b].push_back({{a-1,c},i});
    }
    dfs(1,0);
    for(int i=0;i<q;i++)printf("%lli\n",ans[i]);
    return 0;
}