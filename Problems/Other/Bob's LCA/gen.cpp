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
   // srand(atoi(argv[1]));
    registerGen(argc,argv,0);
    int n=20,q=5e4;
    printf("%d %d\n",n,q);
    for(int i=1;i<n;i++){
        printf("%d\n",rnd.next(0,i-1));
    }
    for(int i=0;i<q;i++){
        int a=rnd.next(0,n-1),b=rnd.next(0,n-1),c=rnd.next(0,n-1);
        if(a>b)swap(a,b);
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}