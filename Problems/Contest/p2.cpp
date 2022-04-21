#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=3001;
int node[MN];
set<int> can[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int groups=n*(n-1)/2/3;
    printf("%d\n",groups);
    int nodes=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<n;j++){
            can[i].insert(j);
        }
    }
    for(int i=1;i<=n;i++){
        node[i]=nodes;

        for(int j=i+1;j<=n;j++){
            if(!gone.count({i,j})) {
                for (int k = j + 1; k <= n; k++) {
                    if(!gone.count({i,k})) {
                        if (!gone.count({j, k})) {
//                            printf("%d %d\n", nodes + (j - i), nodes + (k - i));
                            gone.insert({j, k});
                            if(sz(gone)==groups)return 0;
                            break;
                        }
                    }
                }
            }
        }
        nodes+=n-i;
    }
    return 0;
}