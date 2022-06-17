#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    getline(cin,a);
    int cnt=0;
    for(auto x:a)if(x=='z'||x=='Z')cnt++;
    if(cnt>=3)printf("YES\n");
    else printf("NO\n");
    return 0;
}