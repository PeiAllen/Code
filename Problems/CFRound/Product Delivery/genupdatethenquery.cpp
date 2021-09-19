#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=2e5+1;
int q;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    q=stoi(argv[1]);
    printf("%d\n",q);
    int maxloc=stoi(argv[2]),maxoth=stoi(argv[3]),amupd=stoi(argv[4]),miuprange=stoi(argv[5]),miqurange=stoi(argv[6]);
    for(int i=1;i<=amupd;i++){
        int a=rnd.next(1,maxloc),b=rnd.next(miuprange,maxloc),c=rnd.next(1,maxoth),d=rnd.next(1,maxoth);
        printf("1 %d %d %d %d\n",a,b,c,d);
    }
    for(int i=amupd+1;i<=q;i++){
        int l=rnd.next(1,maxloc-miqurange+1);
        int r=rnd.next(l+miqurange-1,maxloc),c=rnd.next(1,maxoth);
        printf("3 %d %d %d\n",l,r,c);
    }
    return 0;
}