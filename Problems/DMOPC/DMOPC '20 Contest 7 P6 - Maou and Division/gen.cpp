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
    int n=1e5;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        printf("%d %d\n",rnd.next(1,int(1e9)),rnd.next(1,int(1e9)));
    }
    return 0;
}