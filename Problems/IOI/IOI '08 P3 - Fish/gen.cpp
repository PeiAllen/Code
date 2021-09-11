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
    int f=8,k=rnd.next(1,f),m=1e9+7;
    printf("%d\n%d\n%d\n",f,k,m);
    for(int i=0;i<f;i++){
        printf("%d %d\n",rnd.next(1,20),rnd.next(1,k));
    }
    return 0;
}