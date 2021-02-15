#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
pii paths[MN];
int sparse[19][2*MN];
int et=0;
int st[MN];
int par[MN];
int dist[MN];
void dfs(int loc){
    dist[loc]=dist[par[loc]]+1;
    sparse[0][et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc]){
        dfs(x);
        sparse[0][et++]=loc;
    }
}
int mh(int a, int b){
    if(dist[a]<dist[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<19;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){//BRUCE ADD A CUSTOM CHECKER
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        cin>>par[i];
        adj[par[i]].push_back(i);
    }
    dfs(1);
    ms();
    int ans=-1;
    for(int i=0;i<k;i++){
        cin>>paths[i].first>>paths[i].second;
        for(int j=0;j<i;j++){
            int cur=0;
            pii a=paths[i],b=paths[j];
            int alca=getlca(paths[i].first,paths[i].second),blca=getlca(paths[j].first,paths[j].second);
            if(alca==blca){
                cur=-4*dist[alca];
                cur+=dist[getlca(a.first,b.first)]+dist[getlca(a.first,b.second)]+dist[getlca(a.second,b.first)]+dist[getlca(a.second,b.second)];
            }
            else{
                if(dist[alca]>dist[blca]){
                    swap(alca,blca);
                    swap(a,b);
                }
                int wanted=-1;
                if(getlca(blca,a.first)==blca)wanted=a.first;
                else if(getlca(blca,a.second)==blca)wanted=a.second;
                if(wanted!=-1){
                    cur=max(dist[getlca(b.first,wanted)],dist[getlca(b.second,wanted)])-dist[blca];
                }
            }
            if(cur>ans){
                ans=cur;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}