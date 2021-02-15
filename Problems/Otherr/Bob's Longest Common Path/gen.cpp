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
    int n=10,k=5;
    printf("%d %d\n",n,k);
    for(int i=2;i<=n;i++){
        printf("%d%c",rnd.next(1,i-1)," \n"[i==n]);
    }
    for(int i=0;i<k;i++){
        printf("%d %d\n",rnd.next(1,n),rnd.next(1,n));
    }
    return 0;
}