#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc, argv, 1);
    rnd.setSeed(time(NULL));
    cout << rnd.next(1, 10) << rnd.next(1, 10)<<endl;
    return 0;
}