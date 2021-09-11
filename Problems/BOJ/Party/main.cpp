#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3001;
bool matrix[MN][MN];
bool off[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a][b]=matrix[b][a]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&!off[i]&&!off[j]&&!matrix[i][j]){
                off[i]=true,off[j]=true;
            }
        }
    }
    vector<int> arr;
    for(int i=1;i<=n;i++){
        if(!off[i])arr.push_back(i);
    }
    for(int i=0;i<n/3;i++)printf("%d%c",arr[i]," \n"[i==n/3-1]);
    return 0;
}