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
    int n=6;
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        int a=rnd.next(1,n);
        printf("%d %d\n",a,rnd.next(a,n));
    }
    int q=20;
    printf("%d\n",q);
    for(int i=0;i<q;i++){
        int m=rnd.next(1,n);
        printf("%d ",m);
        for(int j=0;j<m;j++)printf("%d%c",rnd.next(1,n)," \n"[j==m-1]);
    }
    return 0;
}