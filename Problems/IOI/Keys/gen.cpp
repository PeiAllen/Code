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
//    srand(atoi(argv[1]));
    registerGen(argc,argv,0);
    int n=5,m=rnd.next(0,20);
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++)printf("%d%c",rnd.next(0,1)," \n"[i==n-1]);
    for(int i=0;i<m;i++){
        printf("%d %d %d\n",rnd.next(0,n-1),rnd.next(0,n-1),0);
    }
    return 0;
}