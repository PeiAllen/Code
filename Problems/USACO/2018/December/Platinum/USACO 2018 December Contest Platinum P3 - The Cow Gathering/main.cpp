#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int sparse[18][MN];
int sparse2[17][MN];
vector<int> adj[MN];
int st[MN],st2[MN],en2[MN];
int ind=0,ind2=0;
int depth[MN];
int psa[MN];
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=17;i++){
        for(int j=0;j+(1<<i)<=ind;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1;i<=16;i++){
        for(int j=0;j+(1<<i)<=ind2;j++){
            sparse2[i][j]=mh(sparse2[i-1][j],sparse2[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int getchild(int a, int b){
    a=st[a]+1,b=st[b];
    int k=log2(b-a+1);
    return mh(sparse2[k][a],sparse2[k][b-(1<<k)+1]);
}
void dfs(int loc, int par, int dep){
    depth[loc]=dep;
    sparse[0][ind]=loc;
    st[loc]=ind++;
    sparse2[0][ind2]=loc;
    st2[loc]=ind2++;
    for(auto x:adj[loc])if(x!=par)dfs(x,loc,dep+1),sparse[0][ind++]=loc;
    en2[loc]=ind-1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,1);
    ms();
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(getlca(a,b)!=a){
            psa[st2[a]]++;
            psa[en2[a]+1]--;
        }
        else{
            b=getchild(a,b);
            psa[0]++;
            psa[st2[b]]--;
            psa[en2[b]+1]++;
            psa[ind2]--;
        }
    }
    for(int i=1;i<ind;i++)psa[i]+=psa[i-1];
    for(int i=1;i<=n;i++){
        if(psa[st[i]])printf("0\n");
        else printf("1\n");
    }
    return 0;
}