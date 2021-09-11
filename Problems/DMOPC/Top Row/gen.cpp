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
    printf("%s\n",rnd.next("[a-z]{100}").c_str());
    int q=100;
    printf("%d\n",q);
    for(int i=0;i<q;i++){
        int a=rnd.next(1,100);
        printf("%d %d\n",a,rnd.next(a,100));
    }
    return 0;
}