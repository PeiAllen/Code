#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=1e5+1;
const int BS=3000;
int encounters[101][MN];
vector<int> locs[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a;
    cin>>n>>m;
    vector<int> large;
    for(int i=1;i<=n;i++){
        cin>>a;
        locs[i].resize(a);
        for(int j=0;j<a;j++)cin>>locs[i][j];
    }
    for(int i=1;i<=n;i++){
        if(SZ(locs[i])>BS){
            large.push_back(i);
            for(int j=1;j<=n;j++){
                if(i!=j){

                }
            }
        }
    }
    return 0;
}