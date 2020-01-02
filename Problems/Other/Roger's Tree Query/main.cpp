#include<bits/stdc++.h>
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
int n,m;
struct node{
    int data,lazy;
    int le,ri;
    struct node *left, *right;
    node(){
        data=0,lazy=0,le=0,ri=0;
        left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node(),right=new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
        }
    }
    void rl(){
        data+=lazy;
        if(le!=ri){
            left->lazy+=lazy;
            right->lazy+=lazy;
        }
        lazy=0;
    }
    void update(int l, int r){
        rl();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            lazy+=1;
            rl();
            return;
        }
        left->update(l,r),right->update(l,r);
    }
    int query(int a){
        rl();
        if(a>ri||a<le)return 0;
        if(le==ri)return data;
        return left->query(a)+right->query(a);
    }
};
vector<int> matrix[MAXN];
int depth[MAXN];
int curind[MAXN];
int cp[MAXN];
int sts[MAXN];
int chaind[MAXN];
int lift[MAXN][17];
vector<node> chains;
int dfs(int loc, int parent, int dep){
    lift[loc][0]=parent;
    sts[loc]=1;
    depth[loc]=dep;
    for(int x:matrix[loc])if(x!=parent)sts[loc]+=dfs(x,loc,dep+1);
    return sts[loc];
}
void ml(){
   rep(i,1,17){
       rep(j,1,n+1){
           lift[j][i]=lift[lift[j][i-1]][i-1];
       }
   }
}
int getlca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    rep(i,0,17){
        if(diff&(1<<i)){
            a=lift[a][i];
        }
    }
    if(a==b)return a;
    for(int i=16;i>=0;i--){
        if(lift[a][i]!=lift[b][i]){
            a=lift[a][i],b=lift[b][i];
        }
    }
    return lift[a][0];
}
void makechains(int loc, int parent, int rep, int ind){
    if(ind==1){
        chaind[loc]=sz(chains);
        chains.push_back(node());
    }
    curind[loc]=ind;
    cp[loc]=rep;
    chaind[loc]=chaind[rep];
    int ma=0;
    for(int x:matrix[loc])if(x!=parent)ma=max(ma,sts[x]);
    for(int x:matrix[loc]){
        if(x!=parent) {
            if (sts[x] == ma)makechains(x, loc,rep,ind+1), ma = -1;
            else makechains(x, loc, x, 1);
        }
    }
    if(ma==0){
        chains[chaind[loc]].mt(1,ind);
    }
}
void update(int loc, int stop){
    while(loc!=stop){
        if(depth[cp[loc]]>depth[stop]){
            chains[chaind[loc]].update(1,curind[loc]);
            loc=lift[cp[loc]][0];
        }
        else{
            chains[chaind[loc]].update(curind[stop]+1,curind[loc]);
            loc=stop;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m);
    int a,b;
    rep(i,1,n){
        sc(a,b);
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    ml();
    makechains(1,0,1,1);
    char c;
    while(m--){
        sc(c,a,b);
        if(c=='P'){
            int lca=getlca(a,b);
            update(a,lca);
            update(b,lca);
        }
        else{
            if(depth[a]<depth[b])swap(a,b);
            prl(chains[chaind[a]].query(curind[a]));
        }
    }
    return 0;
}