#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN][MN];
vector<int> adj[2*MN];
int st[2*MN],lst[2*MN],partof[2*MN],et=1,compcnt=0;
bool inst[2*MN];
vector<int> nodes;
void dfs(int loc){
    st[loc]=lst[loc]=et++;
    inst[loc]=true,nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(!st[x])dfs(x),lst[loc]=min(lst[loc],lst[x]);
        else if(inst[x])lst[loc]=min(lst[loc],st[x]);
    }
    if(lst[loc]==st[loc]){
        compcnt++;
        while(1){
            auto cur=nodes.back();
            nodes.pop_back();
            partof[cur]=compcnt;
            inst[cur]=false;
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i][j]){
                adj[2*i].push_back(2*j);
                adj[2*j].push_back(2*i);
                adj[2*i+1].push_back(2*j+1);
                adj[2*j+1].push_back(2*i+1);
            }
            else{
                adj[2*i+1].push_back(2*j);
                adj[2*j+1].push_back(2*i);
                adj[2*i].push_back(2*j+1);
                adj[2*j].push_back(2*i+1);
            }
        }
    }
    for(int i=1;i<=2*n+1;i++){
        if(!st[i])dfs(i);
    }
    for(int i=1;i<=n;i++)if(partof[i*2]==partof[i*2+1]){
        printf("NE\n");
        return 0;
    }
    printf("DA\n");
    return 0;
}