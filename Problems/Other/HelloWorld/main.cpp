#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i*i<=n;i++){
        ans=i;
    }
    printf("The largest square has side length %d.\n",ans);
    return 0;
}