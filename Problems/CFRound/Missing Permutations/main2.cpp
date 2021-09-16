#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN][MN];
bool used[MN],gone[MN];
vector<int> can[MN];
vector<int> adj[MN];
vector<int> cols[MN];
bool done[2][MN];
vector<int> rows;
void dfs(int loc){
    gone[loc]=true;
    if(done[0][can[loc][0]])swap(can[loc][0],can[loc][1]);
    done[0][can[loc][0]]=true;
    done[1][can[loc][1]]=true;
    arr[rows[0]][loc]=can[loc][0];
    arr[rows[1]][loc]=can[loc][1];
    for(auto x:adj[loc])if(!gone[x])dfs(x);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
        if(arr[i][1]==0)rows.push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[j][i]!=0)used[arr[j][i]]=true;
        }
        for(int j=1;j<=n;j++){
            if(!used[j])can[i].push_back(j);
            used[j]=false;
        }
        cols[can[i][0]].push_back(i);
        cols[can[i][1]].push_back(i);
    }
    for(int i=1;i<=n;i++)adj[cols[i][0]].push_back(cols[i][1]),adj[cols[i][1]].push_back(cols[i][0]);
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d%c",arr[i][j]," \n"[j==n]);
        }
    }
    return 0;
}