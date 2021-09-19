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
    int r=10,c=10;
    int n=rnd.next(1,r),m=rnd.next(1,c);
    int prev=0;
    for(int i=0;i<n;i++){
        prev=rnd.next(prev+1,r-(n-i)+1);
        printf("%d\n",prev);
    }
    for(int i=0;i<m;i++){
        prev=rnd.next(prev+1,c-(m-i)+1);
        printf("%d\n",prev);
    }
    return 0;
}