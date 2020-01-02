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
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
vector<int> mintree[MAXN];//all can go to without going to somewhere smaller
vector<int> mitour;
pii miloc[MAXN];
int milift[MAXN][18];
vector<int> maxtree[MAXN];//all can go to without going to somewhere larger
vector<int> matour;
pii maloc[MAXN];
int malift[MAXN][18];
int disjoint[MAXN];
int n;
struct node{
    vector<int> data;
    int le,ri;
    struct node*left,*right;
    node(){
        data={};
        le=0,ri=0;
        left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node(),right=new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
            int lp=0,rp=0;
            while(!(lp==sz(left->data)&&rp==sz(right->data))){
                if((lp==sz(left->data)?INT_MAX:left->data[lp])<(rp==sz(right->data)?INT_MAX:right->data[rp]))data.push_back(left->data[lp++]);
                else data.push_back(right->data[rp++]);
            }
        }
        else data={maloc[mitour[l]].first};
    }
    int query(int l, int r, int lb,int rb){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r){
            return upper_bound(data.begin(),data.end(),rb)-lower_bound(data.begin(),data.end(),lb);
        }
        return left->query(l,r,lb,rb)+right->query(l,r,lb,rb);
    }
};
int find(int a){
    if(a==disjoint[a])return a;
    return disjoint[a]=find(disjoint[a]);
}
void dfsma(int loc, int parent){
    malift[loc][0]=parent;
    maloc[loc]={sz(matour),0};
    matour.push_back(loc);
    for(int x:maxtree[loc])if(x!=parent)dfsma(x,loc);
    maloc[loc].second=sz(matour)-1;
}
void dfsmi(int loc, int parent){
    milift[loc][0]=parent;
    miloc[loc]={sz(mitour),0};
    mitour.push_back(loc);
    for(int x:mintree[loc])if(x!=parent)dfsmi(x,loc);
    miloc[loc].second=sz(mitour)-1;
}
void ml(){
    rep(i,1,18){
        rep(j,0,n){
            milift[j][i]=(milift[j][i-1]==-1?-1:milift[milift[j][i-1]][i-1]);
            malift[j][i]=(malift[j][i-1]==-1?-1:malift[malift[j][i-1]][i-1]);
        }
    }
}
vector<int> check_validity(int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R){
    n=N;
    rep(i,0,sz(X))matrix[X[i]].push_back(Y[i]),matrix[Y[i]].push_back(X[i]);
    rep(i,0,N)disjoint[i]=i;
    rep(i,0,N){
        for(int x:matrix[i]){
            x=find(x);
            if(x<i){//gone before, and can go to
                disjoint[x]=i;
                maxtree[i].push_back(x);
                maxtree[x].push_back(i);
            }
        }
    }
    dfsma(N-1,-1);
    rep(i,0,N)disjoint[i]=i;
    for(int i=N-1;i>=0;i--){
        for(int x:matrix[i]){
            x=find(x);
            if(x>i){//gone before, and can go to
                disjoint[x]=i;
                mintree[i].push_back(x);
                mintree[x].push_back(i);
            }
        }
    }
    dfsmi(0,-1);
    ml();
    node tree;
    tree.mt(0,N-1);
    vector<int> ans;
    rep(i,0,sz(S)){
        for(int j=17;j>=0;j--)if(milift[S[i]][j]!=-1&&milift[S[i]][j]>=L[i])S[i]=milift[S[i]][j];
        for(int j=17;j>=0;j--)if(malift[E[i]][j]!=-1&&malift[E[i]][j]<=R[i])E[i]=malift[E[i]][j];
        ans.push_back(min(1,tree.query(miloc[S[i]].first,miloc[S[i]].second,maloc[E[i]].first,maloc[E[i]].second)));
    }
    return ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> ans = check_validity(6, {5,1,1,3,3,5}, {1,2,3,4,0,2}, {4,4,5}, {2,2,4}, {1,2,3}, {2,2,4});
    for(int x:ans)pr(x,"");
    return 0;
}