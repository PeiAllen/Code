#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
const int blocksize=550;
const int MAXB=MAXN/blocksize+1;
lli mod=998244353;
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
int n,q;
lli k;
lli am[MAXN][MAXB];
lli pre[MAXN];
int etst2[MAXN];
vector<int> et2;
vector<vector<int>> sparse;
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
lli precalc[MAXN][MAXB];
int block[MAXN];
vector<int> matrix[MAXN];
int depth[MAXN];
lli bit[MAXB][MAXN];
void update(int ind,int loc, lli val){
    for(;loc<=n;loc+=loc&-loc)bit[ind][loc]=fix(bit[ind][loc]+val);
}
lli query(int ind,int loc){
    lli ans=0;
    for(;loc>0;loc-=loc&-loc)ans=fix(ans+bit[ind][loc]);
    return ans;
}
int etst[MAXN];
int eten[MAXN];
int et=1;
int mh(int a, int b){
    if(a>b)swap(a,b);
    if(a==-1)return b;
    if(depth[a]<depth[b])return a;
    return b;
}
void dfs(int loc, int dep){
    am[loc][block[loc]]++;
    etst[loc]=et++;
    etst2[loc]=sz(et2);
    et2.push_back(loc);
    depth[loc]=dep;
    for(int x:matrix[loc]){
        dfs(x,dep+1);
        for(int i=0;i<=block[n-1];i++){
            am[loc][i]+=am[x][i];
        }
        et2.push_back(loc);
    }
    eten[loc]=et;
    for(int x:matrix[loc]){
        for(int i=0;i<=block[n-1];i++){
            am[loc][i]-=am[x][i];
            lli val=pre[dep]*am[loc][i]%mod;
            update(i,etst[x],val);
            update(i,eten[x],fix(-val));
            am[loc][i]+=am[x][i];
        }
    }
    for(int i=0;i<=block[n-1];i++){
        precalc[loc][i]=pre[dep]*am[loc][i]%mod;
    }
}
int lca(int a, int b){
    a=etst2[a],b=etst2[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q>>k;
    k%=mod;
    int a;
    block[0]=0/blocksize;
    pre[1]=fastpow(1,k);
    for(int i=1;i<n;i++){
        pre[i]=fastpow(i,k);
        block[i]=i/blocksize;
        cin>>a;
        a-=1;
        matrix[a].push_back(i);
    }
    pre[n]=fastpow(n,k);
    dfs(0,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<=block[n-1];j++) {
            precalc[i][j]=fix(precalc[i][j]+query(j,etst[i]));
            if(j)precalc[i][j]=fix(precalc[i][j]+precalc[i][j-1]);
        }
    }
    int lg2=max(1,(int)log2(sz(et2))+1);
    sparse.resize(lg2);
    sparse[0].resize(sz(et2),-1);
    for(int i=0;i<sz(et2);i++)sparse[0][i]=et2[i];
    for(int i=1;i<lg2;i++){
        sparse[i].resize(sz(et2),-1);
        for(int j=0;j<=sz(et2)-(1<<i);j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
    int b;
    while(q--){
        cin>>a>>b;
        a-=1,b-=1;
        lli ans=0;
        if(block[a])ans=precalc[b][block[a]-1];
        for(int i=block[a]*blocksize;i<=a;i++){
            ans=fix(ans+pre[depth[lca(b,i)]]);
        }
        printf("%lli\n",ans);
    }
    return 0;
}