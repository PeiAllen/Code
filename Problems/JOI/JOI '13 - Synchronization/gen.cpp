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
    int n=5,m=10,q=5;
    printf("%d %d %d\n",n,m,q);
    for(int i=2;i<=n;i++)printf("%d %d\n",i,rnd.next(1,i-1));
    while(m--)printf("%d\n",rnd.next(1,n-1));
    for(int i=1;i<=n;i++)printf("%d\n",i);
    return 0;
}