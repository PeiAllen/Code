#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
int grundy[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=sz(s);
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;

        }
    }
    return 0;
}