#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=2e5+1;
int am[MN];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=6,m=5,k=rnd.next(1,10);
    int d=rnd.next(0,n-1);
    printf("%d %d %d %d\n",n,m,k,d);
    for(int i=0;i<m;i++){
        int loc=rnd.next(1,n-d);
        int cnt=rnd.next(-am[loc],10);
        printf("%d %d\n",loc,cnt);
        am[loc]+=cnt;
    }
    return 0;
}