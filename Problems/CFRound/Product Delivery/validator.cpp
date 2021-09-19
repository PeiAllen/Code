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
    int q=inf.readInt(1,2e5,"q");
    inf.readEoln();
    set<int> stores;
    for(int i=1;i<=q;i++){
        int type=inf.readInt(1,3,"t");
        inf.readSpace();
        if(type==1){
            inf.readInt(1,1e6,"a");
            inf.readSpace();
            inf.readInt(0,1e6,"b");
            inf.readSpace();
            inf.readInt(1,1e9,"r1");
            inf.readSpace();
            inf.readInt(1,1e9,"c1");
            stores.insert(i);
        }
        else if(type==2){
            int x=inf.readInt(1,i-1,"x");
            ensuref(stores.count(x),"Store DNE");
        }
        else{
            inf.readInt(1,1e6,"l");
            inf.readSpace();
            inf.readInt(1,1e6,"r2");
            inf.readSpace();
            inf.readInt(1,1e9,"c2");
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}