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
    int n=10,m=5;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)printf("%d%c",rnd.next(1,100)," \n"[i==m]);
    int q=20;
    printf("%d\n",q);
    while(q--){
        int a=rnd.next(1,n),b=rnd.next(1,m);
        printf("%d %d\n",a,b);
    }
    return 0;
}