#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int n=inf.readInt(1,4e5,"n");
    inf.readEoln();
    for(int i=1;i<=n;i++){
        inf.readInt(0,1e9,"a_i");
        if(i==n)inf.readEoln();
        else inf.readSpace();
    }
    inf.readEof();
    return 0;
}