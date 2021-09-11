#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MV=5e4;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=5,m=4,q=100,k=0;
    printf("%d %d %d %d\n",n,m,q,k);
    for(int i=2;i<=n;i++){
        if(rnd.next(0,1)==0)printf("%d %d\n",rnd.next(1,i-1),i);
        else printf("%d %d\n",i,rnd.next(1,i-1));
    }
    for(int i=0;i<q;i++){
        printf("%d %d\n",rnd.next(1,n),rnd.next(1,n));
        printf("%d %d\n",rnd.next(1,n),rnd.next(1,n));
    }
    return 0;
}