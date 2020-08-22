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
    int n=10,m=20,p=rnd.next(1,n),q=100;
    printf("%d %d %d %d\n",n,m,p,q);
    for(int i=0;i<m-n;i++){
        printf("%d %d\n",rnd.next(0,n-1),rnd.next(0,n-1));
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n",i,rnd.next(0,n-1));
    }
    for(int i=0;i<q;i++)printf("%d\n",rnd.next(1,int(100)));
    return 0;
}