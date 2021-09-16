#include "testlib.h"
#include "bits/stdc++.h"
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
    int n=stoi(argv[1]),mih=stoi(argv[2]),mah=stoi(argv[3]);
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        printf("%d%c",rnd.next(mih,mah)," \n"[i==n]);
    }
    return 0;
}