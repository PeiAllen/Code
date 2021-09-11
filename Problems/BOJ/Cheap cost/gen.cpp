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
    int n=2,m=2;
    printf("%d %d\n",n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d%c",rnd.next(-10,10)," \n"[j==m-1]);
        }
    }
    return 0;
}