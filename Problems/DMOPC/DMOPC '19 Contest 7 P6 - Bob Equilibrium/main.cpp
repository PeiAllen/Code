#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
vector<int> matrix[MAXN];
vector<int> shops;
int radi[MAXN];
int lift[19][MAXN];
int depth[MAXN];
int n,k;
void dfs(int loc, int parent){
    depth[loc]=depth[parent]+1;
    lift[0][loc]=parent;
    for(int x:matrix[loc])if(x!=parent)dfs(x,loc);
}
void ml(){
    for(int i=1;i<=18;i++){
        for(int j=1;j<=n;j++){
            lift[i][j]=lift[i-1][lift[i-1][j]];
        }
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<=18;i++)if(diff&(1<<i))a=lift[i][a];
    if(a==b)return a;
    for(int i=18;i>=0;i--)if(lift[i][a]!=lift[i][b])a=lift[i][a],b=lift[i][b];
    return lift[0][a];
}
void multibfs(){
    queue<int> q;
    for(int x:shops){
        radi[x]=0;
        q.push( x);
    }
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(int x:matrix[cur]){
            if(radi[x]>radi[cur]+1){
                radi[x]=radi[cur]+1;
                q.push(x);
            }
        }
    }
}
bool cent[MAXN];
int sts[MAXN];
int ans[MAXN];
vector<int> toadd;
vector<int> updates;
int bit[MAXN];
void update(int loc, int val){
    if(loc<=0)return;
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int gtsz(int loc, int parent){
    sts[loc]=1;
    for(int x:matrix[loc])if(x!=parent&&!cent[x])sts[loc]+=gtsz(x,loc);
    return sts[loc];
}
int dst(int loc, int parent, int size){
    for(int x:matrix[loc])if(x!=parent&&!cent[x]&&sts[x]>size)return dst(x,loc,size);
    return loc;
}
void calc(int loc, int parent, int dep){
    ans[loc]+=query(n)-query(dep-1);
    toadd.push_back(radi[loc]-dep);
    for(int x:matrix[loc])if(!cent[x]&&x!=parent)calc(x,loc,dep+1);
}
void process(int loc, bool dort){
    if(dort){
        update(radi[loc],1);
        updates.push_back(radi[loc]);
        if(radi[loc]>=0)ans[loc]++;
    }
    for(int x:matrix[loc]){
        if(!cent[x]){
            calc(x,loc,1);
            for(int y:toadd){
                updates.push_back(y);
                update(y,1);
                if(dort&&y>=0)ans[loc]++;
            }
            toadd.clear();
        }
    }
    for(int x:updates)update(x,-1);
    updates.clear();
}
void dft(int loc){
    int next=dst(loc,0,gtsz(loc,0)/2);
    cent[next]=true;
    process(next,true);
    reverse(matrix[next].begin(),matrix[next].end());
    process(next,false);
    for(int x:matrix[next])if(!cent[x])dft(x);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    int a,b;
    radi[n]=INT_MAX;
    for(int i=1;i<n;i++){
        radi[i]=INT_MAX;
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0);
    ml();
    for(int i=0;i<k;i++){
        cin>>a;
        shops.push_back(a);
    }
    multibfs();
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int dist=depth[a]+depth[i]-2*depth[lca(a,i)];
        radi[i]=min(radi[i],dist-b-1);
    }
    dft(1);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}