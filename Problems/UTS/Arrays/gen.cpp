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
    if(atoi(argv[2])==1) {
        int n = rnd.next(1, int(2e5));
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", rnd.next(1, int(1e8)), " \n"[i == n]);
        }
    }
    else if(atoi(argv[2])==2) {
        int n = 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", rnd.next(1, int(1e8)), " \n"[i == n]);
        }
    }
    else{
        int n = 2e5;
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", rnd.next(1, int(1e8)), " \n"[i == n]);
        }
    }
    return 0;
}