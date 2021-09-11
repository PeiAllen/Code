#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
vector<int> adj[MN];
bool insupport[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    vector<int> support;
    for(int i=1;i<=n;i++){
        cin>>a;
        adj[i].resize(a);
        for(int j=0;j<a;j++)cin>>adj[i][j];
        if(a>1){
            insupport[i]=true;
            support.push_back(i);
        }
    }

    return 0;
}