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
    int n=0,m=20;
    printf("%d %d\n",n,m);
    multiset<int> arr;
    for(int i=0;i<m;i++){
        int type=rnd.next(0,3);
        while(type==2&&sz(arr)==0)type=rnd.next(0,3);
        if(type==0){
            int val=rnd.next(1,MV);
            arr.insert(val);
            printf("I %d\n",val);
        }
        else if(type==1){
            int val=rnd.next(1,MV);
            auto it=arr.find(val);
            if(it!=arr.end())arr.erase(it);
            printf("R %d\n",val);
        }
        else if(type==2){
            printf("S %d\n",rnd.next(1,sz(arr)));
        }
        else{
            printf("L %d\n",rnd.next(1,MV));
        }
    }
    return 0;
}