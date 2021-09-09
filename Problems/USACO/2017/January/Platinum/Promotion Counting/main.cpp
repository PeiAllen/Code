#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int bit[MN],st[MN],en[MN],et,ans[MN];
vector<int> adj[MN];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
void dfs(int loc){
    st[loc]=et++;
    for(auto x:adj[loc])dfs(x);
    en[loc]=et-1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int a;
    map<int,vector<int>> vals;
    for(int i=1;i<=n;i++){
        cin>>a;
        vals[-a].push_back(i);
    }
    for(int i=2;i<=n;i++){
        cin>>a;
        adj[a].push_back(i);
    }
    et=1;
    dfs(1);
    for(auto x:vals){
        for(auto y:x.second){
            ans[y]=query(en[y])-query(st[y]-1);
        }
        for(auto y:x.second){
            update(st[y],1);
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}