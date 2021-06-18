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
    int n=5,k=rnd.next(0,n);
    printf("%d %d\n",n,k);
    vector<int> xcoords,ycoords;
    for(int i=1;i<=n;i++)xcoords.push_back(i),ycoords.push_back(i);
    for(int i=0;i<k;i++){
        int a=rnd.next(0,sz(xcoords)-1),b=rnd.next(0,sz(ycoords)-1);
        printf("%d %d\n",xcoords[a],ycoords[b]);
        xcoords.erase(xcoords.begin()+a),ycoords.erase(ycoords.begin()+b);
    }
    return 0;
}