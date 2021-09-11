#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MV=20;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=5,q=20;
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++)printf("%d%c",rnd.next(1,MV)," \n"[i==n]);
    for(int i=0;i<q;i++){
        int type=rnd.next(1,2);
        if(type==1){
            printf("%d %d %d\n",type,rnd.next(1,n),rnd.next(1,MV));
        }
        else{
            int l=rnd.next(1,n);
            printf("%d %d %d\n",type,l,rnd.next(l,n));
        }
    }
    return 0;
}