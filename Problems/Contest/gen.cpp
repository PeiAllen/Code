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
    printf("%d\n",n);
    vector<int> vals(n);
    for(int i=0;i<n;i++){
        vals[i]=i+1;
    }
    shuffle(vals.begin(),vals.end());
    for(int i=0;i<n;i++){
        printf("%d%c",min(vals[(i-1+n)%n],vals[(i+1)%n])," \n"[i==n-1]);
    }
    return 0;
}