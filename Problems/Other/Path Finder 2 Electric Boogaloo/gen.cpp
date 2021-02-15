#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int n=1e3,m=1e3,q=100,k;
set<pii> used;
pii getpoint(){
    int x=rnd.next(1,n),y=rnd.next(1,m);
    while(used.count({x,y}))x=rnd.next(1,n),y=rnd.next(1,m);
    return {x,y};
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    k=rnd.next(n*m/2,n*m-2);
    printf("%d %d %d %d\n",n,m,k,q);
    for(int i=0;i<k;i++){
        pii te=getpoint();
        used.insert(te);
        printf("%d %d\n",te.first,te.second);
    }
    for(int i=0;i<q;i++){
        pii te=getpoint(),te2=getpoint();
        printf("%d %d %d %d\n",te.first,te.second,te2.first,te2.second);
    }
    return 0;
}