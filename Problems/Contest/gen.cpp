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
    int n=rnd.next(1,5),q=rnd.next(1,10);
    n*=2;
    printf("%d %d\n",n,q);
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),1);
    shuffle(arr.begin(),arr.end());
    for(int i=1;i<=n;i++)printf("%d%c",arr[i-1]," \n"[i==n]);
    for(int i=1;i<=q;i++){
        printf("%d %d\n",rnd.next(0,n),rnd.next(1,n));
    }
    return 0;
}