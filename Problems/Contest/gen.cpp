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
    int n=10,k=rnd.next(0,n);
    printf("%d %d\n",n,k);
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),1);
    shuffle(arr.begin(),arr.end());
    for(int i=0;i<k;i++)printf("%d%c",arr[i]," \n"[i==k-1]);
    return 0;
}