#pragma GCC optimize "O3"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,int> pll;
template<typename T>
inline int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int liv[MAXN];
int livte[MAXN];
vector<int> vals;
int arr[MAXN];
pii bit[MAXN];
pii bit2[MAXN];
int curind=0;
int szv=0;
int bvals[MAXN];
int bcomp[MAXN];
int comp[MAXN];
int bvalsr;
void update(int loc, int val){
    for(;loc<=szv;loc+=loc&-loc){
        if(bit[loc].second!=curind)bit[loc]={0,curind};
        bit[loc].first+=val;
    }
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=(bit[loc].second==curind?bit[loc].first:0);
    return ans;
}
void update2(int loc, int val){
    for(;loc<=bvalsr;loc+=loc&-loc){
        if(bit2[loc].second!=curind)bit2[loc]={0,curind};
        bit2[loc].first+=val;
    }
}
int query2(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=(bit2[loc].second==curind?bit2[loc].first:0);
    return ans;
}
int sparse[18][2*MAXN];
int prelog[2*MAXN];
vector<int> matrix[MAXN];
pii queries[MAXN];
int depth[MAXN];
bool done[MAXN];
int et=0;
int etind=1;
int bs;
int st[MAXN];
int en[MAXN];
int parent[MAXN];
int blockr=-1;
int visitedr=-1;
int nodesr=-1;
int block[MAXN];
int visited[MAXN];
int nodes[MAXN];
int sts[MAXN];
int toind[MAXN];
int tot=0;
int dsts(int loc){
    sts[loc]=1;
    for(int x:matrix[loc]){
        sts[loc]+=dsts(x);
    }
    sort(matrix[loc].begin(),matrix[loc].end(),[&](auto lhs, auto rhs){
        return sts[lhs]<sts[rhs];
    });
    return sts[loc];
}
void dfs(int loc, int dep, int par){
    toind[loc]=etind++;
    depth[toind[loc]]=dep;
    parent[toind[loc]]=par;
    st[toind[loc]]=et;
    sparse[0][et++]=toind[loc];
    for(int x:matrix[loc]){
        dfs(x,dep+1,toind[loc]);
        sparse[0][et++]=toind[loc];
    }
    en[toind[loc]]=et;
}
int n;
inline int md(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=log2(et);i++){
        for(int j=0;j+(1<<(i-1))<et;j++){
            sparse[i][j]=md(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
inline int spquery(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=prelog[b-a+1];
    return md(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    //n=1e5;
    bs=330;
    for(int i=1;i<=n;i++){
        cin>>livte[i];
        //liv[i]=i;
        vals.push_back(livte[i]);
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    szv=sz(vals);
    for(int i=1;i<=n;i++)livte[i]=(lower_bound(vals.begin(),vals.end(),livte[i])-vals.begin())+1;
    for(int i=1;i<n;i++){
        cin>>queries[i].first>>queries[i].second;
        //queries[i]={i,i+1};
        matrix[queries[i].first].push_back(queries[i].second);
    }
    dsts(1);
    dfs(1,1,0);
    for(int i=1;i<=n;i++)liv[toind[i]]=livte[i];
    for(int i=1;i<n;i++)queries[i].first=toind[queries[i].first],queries[i].second=toind[queries[i].second];
    ms();
    arr[toind[1]]=liv[toind[1]];
    for(int i=0;i<=et;i++)prelog[i]=log2(i);
    bvalsr=-1;
    for(int j=1;j<min(n,bs);j++){
        bvals[++bvalsr]=liv[queries[j].second];
    }
    sort(bvals,bvals+bvalsr+1);
    bvalsr=(unique(bvals,bvals+bvalsr+1)-bvals)-1;
    for(int j=0;j<=bvalsr;j++)bcomp[bvals[j]]=j+1;
    int cind=0;
    for(int j=1;j<=szv;j++){
        if(cind<=bvalsr&&j>=bvals[cind])cind++;
        comp[j]=cind+1;
    }
    bvalsr++;
    bvalsr++;
    for(int i=1;i<n;i++){
        if(i%bs==0){
            for(int j=0;j<=nodesr;j++)done[nodes[j]]=false;
            for(;blockr>=0;blockr--){
                int cur=block[blockr];
                while(cur!=0&&!done[cur]){
                    done[cur]=true;
                    arr[cur]=liv[block[blockr]];
                    cur=parent[cur];
                }
            }
            for(;nodesr>=0;nodesr--)done[nodes[nodesr]]=false;
            bvalsr=-1;
            for(int j=i;j<min(n,i+bs);j++){
                bvals[++bvalsr]=liv[queries[j].second];
            }
            sort(bvals,bvals+bvalsr+1);
            bvalsr=(unique(bvals,bvals+bvalsr+1)-bvals)-1;
            for(int j=0;j<=bvalsr;j++)bcomp[bvals[j]]=j+1;
            cind=0;
            for(int j=1;j<=szv;j++){
                if(cind<=bvalsr&&j>=bvals[cind])cind++;
                comp[j]=cind+1;
            }
            bvalsr++;
            bvalsr++;
        }
        int cur=queries[i].first;
        int ans=0;
        while(cur!=0&&!done[cur]){
            ans+=query(arr[cur]-1);
            update(arr[cur],1);
            visited[++visitedr]=cur;
            update2(comp[arr[cur]],-1);
            cur=parent[cur];
        }
        int curdep=0;
        for(int j=blockr;j>=0;j--) {
            int lca=spquery(block[j],queries[i].first);
            int am=(depth[lca]-curdep<0?0:depth[lca]-curdep);
            if(depth[lca]>curdep)curdep=depth[lca];
            ans+=(tot-query2(bcomp[liv[block[j]]]))*am;
            update2(bcomp[liv[block[j]]],am);
            tot+=am;
        }
        printf("%d\n",ans);
        done[queries[i].second]=true;
        nodes[++nodesr]=queries[i].second;
        for(;visitedr>=0;visitedr--)done[visited[visitedr]]=true,nodes[++nodesr]=visited[visitedr];
        block[++blockr]=queries[i].second;
        curind++;
        tot=0;
    }
    return 0;
}