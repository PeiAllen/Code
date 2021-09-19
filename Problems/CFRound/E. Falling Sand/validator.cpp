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
    inf.readSpace();
    int m=inf.readInt(1,4e5,"m");
    inf.readEoln();
    ensuref(ll(n)*ll(m)<=4e5,"Grid is larger than 4e5");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x=inf.readChar();
            ensuref(x=='#'||x=='.',"Invalid character in grid!");
        }
        inf.readEoln();
    }
    for(int i=1;i<=m;i++){
        inf.readInt(0,n,"a_i");
        if(i==m)inf.readEoln();
        else inf.readSpace();
    }
    inf.readEof();
    return 0;
}