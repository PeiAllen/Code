#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=1e5+1;
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int n=inf.readInt(1,1e5,"n");
    inf.readEoln();
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    int a,b;
    for(int i=1;i<n;i++){
        a=inf.readInt(1,n,"a_i");
        inf.readSpace();
        b=inf.readInt(1,n,"b_i");
        inf.readEoln();
        ensuref(uni(a,b),"Graph is Not A Tree");
    }
    inf.readEof();
    return 0;
}