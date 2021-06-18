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
    int n=10;
    int s=rnd.next(0,n-1),d=rnd.next(0,2*n+n/2);
    printf("%d %d %d\n",n,s,d);
    for(int i=0;i<n;i++)printf("%d%c",rnd.next(0,20)," \n"[i==n-1]);
    return 0;
}