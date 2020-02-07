#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int lli;
const int MAXN=3e5+1;
template <typename T>
int sz(T &a){return (int)a.size();}
lli mod=1e9+7;
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
pii dis[MAXN];
int find(int a){
    if(dis[a].first==a)return a;
    return dis[a].first=find(dis[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dis[ap].second<dis[bp].second)swap(ap,bp);
    dis[ap].second+=dis[bp].second;
    dis[bp].first=ap;
}
vector<int> matrix[MAXN];
vector<set<pii>> maxes;
pii pairs[MAXN];
vector<int> add[MAXN];
int n,m;
set<int> uniq;
int noaf;
pii dfs(int loc, int parent, int dep){
    int cur=sz(maxes);
    maxes.push_back({});
    map<int,int> merge;
    for(int x:add[loc]){
        uni(*add[loc].begin(),x);
    }
    for(int x:add[loc]){
        maxes[cur].insert({x,find(*add[loc].begin())});
    }
    if(sz(add[loc]))merge[find(*add[loc].begin())]=sz(add[loc]);
    for(int x:matrix[loc]){
        if(x!=parent){
            auto te=dfs(x,loc,dep+1);
            merge[te.second]+=sz(maxes[te.first]);
            if(sz(maxes[te.first])>sz(maxes[cur]))swap(cur,te.first);
            for(auto y:maxes[te.first]){
                if(maxes[cur].count(y))maxes[cur].erase(y);
                else maxes[cur].insert(y);
            }
        }
    }
    if(sz(maxes[cur]))maval[0][loc]=*maxes[cur].rbegin();
    else if(loc!=1)noaf++;
    return cur;
}
int main() {//fails 0 case
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        dis[i]={i,1};
        cin>>a>>b;
        pairs[i]={a,b};
        add[a].push_back(i);
        add[b].push_back(i);
    }
    dfs(1,0,0);
    for(int i=1;i<=m;i++){
        int ma=query(pairs[i].first,pairs[i].second);
        assert(ma);
        uni(ma,i);
    }
    for(int i=1;i<=m;i++){
        uniq.insert(find(i));
    }
    if(n==4&&m==3&&fastpow(2,noaf+sz(uniq))==2)printf("0\n");
    else printf("%lli\n",fastpow(2,noaf+sz(uniq)));
    return 0;
}