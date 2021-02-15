#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
const ll mod=1e9+7;
int n,m,d,nodes,cind;
ll bit[2*MAXN];
void update(int loc, ll val){
    for(;loc<=nodes;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int et,let;
int st[2*MAXN],en[2*MAXN],lst[2*MAXN],depth[2*MAXN];
int sparse[19][4*MAXN];
vector<int> matrix[2*MAXN];
int ind[MAXN],low[MAXN];
int rep[2*MAXN];
ll tosub[2*MAXN];
stack<int> comp;
void MBCT(int loc, int parent){
    low[loc]=ind[loc]=cind++;
    comp.push(loc);
    for(auto x:matrix[loc]){
        if(x!=parent){
            if(!ind[x]){
                MBCT(x,loc);
                low[loc]=min(low[loc],low[x]);
            }
            else low[loc]=min(low[loc],ind[x]);
        }
    }
    if(low[loc]==ind[loc]){
        int cur;
        nodes++;
        rep[nodes]=nodes;
        while(1){
            cur=comp.top();
            comp.pop();
            rep[cur]=nodes;
            if(cur==loc)break;
        }
    }
}
void dfs(int loc, int dep){
    st[loc]=et++,lst[loc]=let,sparse[0][let++]=loc,depth[loc]=dep;
    for(auto x:matrix[loc])if(!st[x])dfs(x,dep+1),sparse[0][let++]=loc;
    en[loc]=et-1;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<19;i++){
        for(int j=0;j+(1<<i)<=let;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=lst[a],b=lst[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>d;
        int a,b;
        nodes=n;
        for(int i=1;i<=n;i++)matrix[i]=vector<int>(),ind[i]=0,rep[i]=i,tosub[i]=0,bit[i]=0;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            matrix[a].push_back(b),matrix[b].push_back(a);
        }
        cind=1;
        for(int i=1;i<=n;i++)if(!ind[i])MBCT(i,0);
        for(int i=n+1;i<=nodes;i++)matrix[i]=vector<int>(),st[i]=0,bit[i]=0,tosub[i]=0;
        for(int i=1;i<=n;i++)for(auto x:matrix[i])if(rep[i]!=rep[x])matrix[rep[i]].push_back(rep[x]);
        et=1,let=0;
        for(int i=n+1;i<=nodes;i++)if(!st[i])dfs(i,1),sparse[0][let++]=0;
        ms();
        char type;
        ll c;
        ll ans=0;
        while(d--){
            cin>>type;
            if(type=='T'){
                cin>>a>>b>>c;
                a=rep[a],b=rep[b];
                int lca=getlca(a,b);
                if(lca){
                    update(st[a],c),update(st[b],c),update(st[lca],ll(-2)*c);
                    tosub[lca]-=c;
                }
            }
            else{
                cin>>a;
                ll am=query(en[rep[a]])-query(st[rep[a]]-1)-tosub[a]-tosub[rep[a]];
                tosub[a]+=am;
                ans+=am;
            }
        }
        printf("%lli\n",ans%mod);
    }
    return 0;
}