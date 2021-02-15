#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MV=20;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=5,q=20;
    int k=rnd.next(1,n);
    printf("%d %d %d\n",n,k,q);
    for(int i=0;i<n;i++){
        int begin=rnd.next(1,MV);
        printf("%d %d %d %d\n",rnd.next(1,MV),rnd.next(1,k),begin,rnd.next(begin,MV));
    }
    for(int i=0;i<q;i++){
        printf("%d %d\n",rnd.next(1,MV),rnd.next(1,MV));
    }
    return 0;
}