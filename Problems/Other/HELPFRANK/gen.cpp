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
    printf("1\n");
    int n=20;
    int m=rnd.next(1,n*n);
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)printf("%d %d\n",rnd.next(1,n),rnd.next(1,n));
    return 0;
}