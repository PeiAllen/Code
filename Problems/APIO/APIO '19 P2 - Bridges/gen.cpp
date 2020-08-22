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
    int n=10,m=9;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        printf("%d %d %d\n",i,i+1,rnd.next(1,int(100)));
    }
    int q=5;
    printf("%d\n",q);
    while(q--){
        int type=rnd.next(1,2);
        if(type==1)printf("%d %d %d\n",type,rnd.next(1,m),rnd.next(1,int(100)));
        else printf("%d %d %d\n",type,rnd.next(1,n),rnd.next(1,int(100)));
    }
    return 0;
}