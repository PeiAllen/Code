#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
char arr[MN][MN];
vector<int> adj[MN*MN];
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    pii st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='C')st={i,j},arr[i][j]='.';
            if(arr[i][j]=='F')en={i,j},arr[i][j]='.';
            if(arr[i][j]=='.'){

            }
        }
    }
    return 0;
}