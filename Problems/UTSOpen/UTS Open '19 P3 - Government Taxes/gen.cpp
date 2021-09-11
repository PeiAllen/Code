#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=5e5,MV=1e8,MS=1e5;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    //int n=rnd.next(1,MN),q=rnd.next(1,MN);
    int n=MN,q=MN;
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++){
        printf("%d%c",rnd.next(-MV,MV)," \n"[i==n]);
    }
    for(int i=1;i<=q;i++){
        int type=(i<=q/2?1:2);
        if(type==1){
            int left=rnd.next(1,n-MS+1);
            printf("%d %d %d %d\n",type,left,rnd.next(left+MS-1,n),rnd.next(-MV,MV));
        }
        else{
            int left=rnd.next(1,n-MS+1);
            printf("%d %d %d\n",type,left,rnd.next(left+MS-1,n));
        }
    }
    return 0;
}