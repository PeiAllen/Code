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
    int maxloc=stoi(argv[2]),maxoth=stoi(argv[3]),upd1=stoi(argv[4]),updrange=stoi(argv[5]),qurange=stoi(argv[6]);
    for(int i=1;i<=q;i++){
        int per=rnd.next(1,100);
        if(per<=upd1) {
            int a = maxloc / 2 + rnd.next(-updrange/2, updrange/2), b = maxloc / 2 - rnd.next(0, updrange), c = rnd.next(1, maxoth), d = rnd.next(1, maxoth);
            printf("1 %d %d %d %d\n", a, b, c, d);
        }
        else{
            int l=rnd.next(1,qurange);
            int r=maxloc-rnd.next(0,qurange),c=rnd.next(1,maxoth);
            printf("3 %d %d %d\n",l,r,c);
        }
    }
    return 0;
}