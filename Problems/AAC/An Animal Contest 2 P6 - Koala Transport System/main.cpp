#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1,ML=__lg(2*MN)+1;
vector<int> adj[MN];
int sparse[ML][2*MN],depth[MN],st[MN],et;
ll val[MN];
void dfs(int loc, int parent){
    st[loc]=et,depth[loc]=depth[parent]+1;
    sparse[0][et++]=loc;
    for(auto x:adj[loc])if(x!=parent){
        dfs(x,loc);
        sparse[0][et++]=loc;
    }
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ml(){
    for(int i=1;i<ML;i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return sparse[k][a],sparse[k][b-(1<<k)+1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0),ml();
    while(q--){
        cin>>a;
        vector<int> arr(a);
        for(int i=0;i<a;i++)cin>>arr[i];
        if(a==1){
            printf("0\n");
            continue;
        }
        sort(arr.begin(),arr.end(),[&](const auto &lhs, const auto &rhs){
            return st[lhs]<st[rhs];
        });
        ll cur=0,psa=0;
        cur=psa=val[1]=depth[arr[1]]-depth[getlca(arr[0],arr[1])];
        for(int i=2;i<a;i++){
            val[i]=depth[arr[i]]-depth[getlca(arr[i-1],arr[i])]-(depth[arr[i-1]]-depth[getlca(arr[i-1],arr[i])]);
            psa+=val[i];
            cur+=psa;
        }
        ll best=cur;
        for(int i=1;i<a;i++){
            cur-=depth[arr[i]]-depth[getlca(arr[i-1],arr[i])];

        }
        printf("%lli\n",best);
    }
    return 0;
}