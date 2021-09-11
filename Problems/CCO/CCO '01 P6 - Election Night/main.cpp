#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=101;
set<int> peeps[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    while(n!=0) {
        int a,b;
        for (int i = 0; i < m; i++) {
            cin>>a;
            peeps[i]=set<int>();
            for(int j=0;j<a;j++){
                cin>>b;
                peeps[i].insert(b);
            }
        }
        vector<int> may;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

            }
        }
        cin>>n>>m;
    }
    return 0;
}