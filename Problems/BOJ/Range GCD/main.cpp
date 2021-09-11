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
    for(int i=0;i<1000;i++){
        int n=rnd.next(2,10);
        vector<int> arr;
        for(int j=0;j<n;j++){
            arr.push_back(rnd.next(0,100));
        }
        int gc=0;
        for(int j=1;j<n;j++)gc=__gcd(gc,abs(arr[j]-arr[j-1]));
        sort(arr.begin(),arr.end());
        int gc2=0;
        for(int j=1;j<n;j++)gc2=__gcd(gc2,arr[j]-arr[j-1]);
        if(gc!=gc2){
            printf("%d\n",n);
            for(auto x:arr)printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}