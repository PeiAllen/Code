#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> adj[MN];
vector<int> radj[MN];
int am[MN],ram[MN],gone[MN],rgone[MN];
int n,m,q,k,bruteans;
void dfs(int loc, int ti){
    gone[loc]=ti;
    for(auto x:adj[loc])if(gone[x]<ti)dfs(x,ti);
}
void rdfs(int loc, int ti){
    rgone[loc]=ti;
    if(gone[loc]==ti)bruteans++;
    for(auto x:radj[loc])if(rgone[x]<ti)rdfs(x,ti);
}
void solvetree(){

}
void brute(){
    int a,b,st,en;
    fill(gone,gone+n+1,-1);
    fill(rgone,rgone+n+1,-1);
    for(int i=0;i<q;i++){
        cin>>st>>en;
        vector<int> topop,rtopop;
        for(int j=0;j<k;j++){
            cin>>a>>b;
            adj[a].push_back(b);
            topop.push_back(a);
            radj[b].push_back(a);
            rtopop.push_back(b);
        }
        bruteans=0;
        dfs(st,i),rdfs(en,i);
        printf("%d\n",bruteans);
        for(auto x:topop)adj[x].pop_back();
        for(auto x:rtopop)radj[x].pop_back();
    }
}
void solvekzero(){

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>n>>m>>q>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
//    if(m==n-1){
//        solvetree();
//    }
//    else if(k==0){
//        solvekzero();
//    }
//    else{
    brute();
//    }
    return 0;
}