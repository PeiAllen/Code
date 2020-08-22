#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc, argv, 1);
    int n=10;
    for(int i=0;i<n;i++){
        cout<<rnd.next("[a-z]{1}");
    }
    return 0;
}