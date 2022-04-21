#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if((a+b)%3==0&&max(a,b)<=min(a,b)*2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}