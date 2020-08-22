#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int kek=0;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};
    v = v.apply([](int n)->int {
        return n*2;
    });
    for(auto n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}