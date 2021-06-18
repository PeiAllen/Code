#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=8e5+1;
int ptr[MN];
int cnt=0;
bool gone[MN];
vector<int> adj[MN];
vector<int> ord;
vector<int> repord;
void dfs(int loc, int parent){
    ord.push_back(loc);
    if(!gone[loc])gone[loc]=true,cnt++;
    int am=0;
    while(1){
        ptr[loc]=(ptr[loc]+1)%sz(adj[loc]);
        if(adj[loc][ptr[loc]]==parent)return;
        dfs(adj[loc][ptr[loc]],loc);
        am++;
        ord.push_back(loc);
        if(am==sz(adj[loc])&&loc==1)return;
    }
}
void getord(int loc, int parent){
    repord.push_back(loc);
    int am=0;
    while(1){
        ptr[loc]=(ptr[loc]+1)%sz(adj[loc]);
        if(adj[loc][ptr[loc]]==parent)return;
        getord(adj[loc][ptr[loc]],loc);
        am++;
        repord.push_back(loc);
        if(am==sz(adj[loc])&&loc==1)return;
    }
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        adj[i].resize(a);
        for(int j=0;j<a;j++)cin>>adj[i][j];
    }
    while(cnt!=n){
        dfs(1,0);
        ord.pop_back();
    }
    getord(1,0);
    repord.pop_back();
    ll t;
    while(q--){
        cin>>t;
        t++;
        if(t<=sz(ord))printf("%d\n",ord[t-1]);
        else{
            t-=sz(ord);
            t--;
            t%=sz(repord);
            printf("%d\n",repord[t]);
        }
    }
    return 0;
}