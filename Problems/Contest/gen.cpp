#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MV=5e4;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int p=5,n=10;
    printf("%d %d\n",p,n);
    for(int i=1;i<=p;i++)printf("%d ",i);
    for(int i=p+1;i<=n;i++)printf("%d%c",rnd.next(1,p)," \n"[i==n]);
    int k=rnd.next(0,10);
    printf("%d\n",k);
    set<pii> used;
    for(int i=0;i<k;i++){
        int a=rnd.next(1,n-1);
        int b=rnd.next(a+1,n);
        while(used.count({a,b})){
            a=rnd.next(1,n-1);
            b=rnd.next(a+1,n);
        }
        used.insert({a,b});
        printf("%d %d\n",a,b);
    }
    return 0;
}