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
    int n=10,q=10,a,b;
    printf("%d %d\n",n,q);
    for(int i=0;i<n;i++)printf("%d%c",rnd.next(1,10)," \n"[i==n-1]);
    for(int i=0;i<q;i++){
        a=rnd.next(1,2),b=rnd.next(1,n-1);
        if(a==1)printf("%d %d\n",a,b);
        else printf("%d %d %d\n",a,rnd.next(0,n-1),b);
    }
    return 0;
}