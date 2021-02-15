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
    int d=1e9,k=rnd.next(1,d),n=10,q=20;
    printf("%d %d %d %d\n",d,k,n,q);
    set<int> a,b;
    for(int i=0;i<n;i++){
        int tea=rnd.next(1,int(1e9));
        while(a.count(tea))tea=rnd.next(1,int(1e9));
        int teb=rnd.next(1,int(1e9));
        while(b.count(teb))teb=rnd.next(1,int(1e9));
        a.insert(tea),b.insert(teb);
        printf("%d %d %d\n",tea,teb,rnd.next(1,int(1e9)));
    }
    while(q--){
        printf("%d %d\n",rnd.next(1,n),rnd.next(0,d-k));
    }
    return 0;
}