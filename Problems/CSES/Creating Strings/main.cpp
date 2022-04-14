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
    cin>>a;
    sort(a.begin(),a.end());
    vector<string> ans;
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(),a.end()));
    printf("%d\n",sz(ans));
    for(auto x:ans)printf("%s\n",x.c_str());
    return 0;
}