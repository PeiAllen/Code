#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e4+1;
int arr[MN][4];
int st[MN*4+52];
vector<int> adj[4*MN+52];
bool dfs(int loc){
    st[loc]=1;
    for(auto x:adj[loc]){
        if(st[x]==1)return true;
        else if(!st[x]&&dfs(x))return true;
    }
    st[loc]=2;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
            if(arr[i][j]) {
                adj[4 * n + -arr[i][j] + 26].push_back(i * 4 + j);
                for (int k = 0; k < 4; k++) {
                    if (k != j)adj[i * 4 + k].push_back(4 * n + arr[i][j] + 26);
                }
            }
        }
    }
    for(int i=0;i<4*n;i++){
        if(!st[i]&&dfs(i)){
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}