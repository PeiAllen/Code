#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+2;
lli col[MAXN];
vector<pii> matrix[MAXN];
vector<int> path;
lli val[MAXN];
lli psa[MAXN];
lli add=0;
int n,m,l,r;
int par[16][MAXN];
int depth[MAXN];
int ree[MAXN];
void dfs(int cur, int parent, int come, int dep){
    val[cur]=val[parent]+add;
    ree[cur]=come;
    par[0][cur]=parent;
    depth[cur]=dep;
    for(pii x:matrix[cur]){
        if(x.first!=parent){
            if(come!=x.second)add=col[x.second];
            else add=0;
            path.push_back(x.second);
            dfs(x.first,cur,x.second,dep+1);
        }
    }
}
void ml(){
    for(int i=1;i<16;i++){
        for(int j=1;j<=n;j++)par[i][j]=par[i-1][par[i-1][j]];
    }
}
lli anste=LLONG_MIN;
void go(int loc, int parent, int fromco, int dep, lli val){
    if(dep>=l&&dep<=r)anste=max(anste,val);
    for(pii x:matrix[loc]){
        if(x.first!=parent){
            go(x.first,loc,x.second,dep+1,val+(x.second!=fromco?col[x.second]:(lli)0));
        }
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<16;i++){
        if(diff&(1<<i))a=par[i][a];
    }
    if(a==b)return a;
    for(int i=15;i>=0;i--){
        if(par[i][a]!=par[i][b]){
            a=par[i][a],b=par[i][b];
        }
    }
    return par[0][a];
}
struct node{
    lli data;
    int le,ri;
    struct node*left, *right;
    node(){
        data=0;
        le=-1;
        ri=-1;
        left=NULL;
        right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left = new node();
            right = new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
        }
    }
    void update(int loc, lli val){
        if(loc>ri||loc<le)return;
        if(le==ri){
            data=val;
            return;
        }
        left->update(loc,val),right->update(loc,val);
        data=min(left->data,right->data);
    }
    lli query(int l, int r){
        if(l>ri||r<le)return LLONG_MAX;
        if(le>=l&&ri<=r)return data;
        return min(left->query(l,r),right->query(l,r));
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>l>>r;
    for(int i=1;i<=m;i++){
        cin>>col[i];
    }
    int touse=-1;
    int a,b,c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    if(n<=1e3){
        for(int i=1;i<=n;i++){
            go(i,0,0,0,0);
        }
        printf("%lli\n",anste);
    }
    else {
        for (int i = 1; i <= n; i++)if (sz(matrix[i]) == 1)touse = i;
        path.push_back(0);
        dfs(touse, -1,0, 0);
        lli ans = LLONG_MIN;
        node tree;
        tree.mt(0, sz(path));
        for (int i = 1; i < sz(path); i++) {
            psa[i] = (path[i] == path[i - 1] ? 0 : col[path[i]]) + psa[i - 1];
            ans = max(ans, psa[i] - tree.query(max(0, i - r), max(0, i - l)));
            if (i != sz(path) - 1)tree.update(i, psa[i] - (path[i + 1] == path[i] ? col[path[i]] : (lli) 0));
        }
        printf("%lli\n", ans);
    }
    return 0;
}