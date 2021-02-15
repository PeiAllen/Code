#include "bits/stdc++.h"
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
    registerGen(argc,argv,0);
    int n=10;
    int m=rnd.next(2,n),k=rnd.next(2,n);
    printf("%d %d %d\n",n,m,k);
    for(int i=2;i<=n;i++)printf("%d %d %d\n",i,rnd.next(1,i-1),rnd.next(0,10));
    return 0;
}