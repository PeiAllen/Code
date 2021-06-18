#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const ll MV=20;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=5,m=10,q=10;
    printf("%d %d %d\n",n,m,q);
    for(int i=2;i<=n;i++){
        printf("%d %d %lli\n",i,rnd.next(1,i-1),rnd.next(ll(0),MV));
    }
    for(int i=0;i<m-(n-1);i++){
        int a=rnd.next(1,n);
        int b=rnd.next(1,n);
        while(b==a)b=rnd.next(1,n);
        printf("%d %d %lli\n",a,b,rnd.next(ll(0),MV));
    }
    for(int i=0;i<q;i++){
        printf("%d %lli\n",rnd.next(1,m),rnd.next(ll(0),MV));
    }
    return 0;
}