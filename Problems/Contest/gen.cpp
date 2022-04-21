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
    int n=rnd.next(3,10),q=rnd.next(3,10);
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++){
        printf("%d%c",rnd.next(-10,10)," \n"[i==n]);
    }
    for(int i=1;i<=q;i++){
        int type=rnd.next(0,1);
        printf("%d ",type);
        if(type==0){
            int l=rnd.next(1,n);
            int r=rnd.next(l,n);
            printf("%d %d %d\n",l,r,rnd.next(-10,10));
        }
        else{
            int l=rnd.next(1,n);
            int r=rnd.next(l,n);
            printf("%d %d\n",l,r);
        }
    }
    return 0;
}