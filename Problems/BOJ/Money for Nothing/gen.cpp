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
    int n=3,m=3;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++){
        printf("%d %d\n",rnd.next(1,10),rnd.next(1,10));
    }
    for(int i=0;i<m;i++){
        printf("%d %d\n",rnd.next(1,10),rnd.next(1,10));
    }
    return 0;
}