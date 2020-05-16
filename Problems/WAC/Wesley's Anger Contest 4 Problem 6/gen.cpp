#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc, argv, 1);
    rnd.setSeed(time(0));
    freopen("data.in","w",stdout);
    int n=100000,m=300000,q=300000;
    printf("%d %d %d\n",n,m,q);
    for(int i=0;i<m;i++){
        int a=rnd.next(1,n),b=rnd.next(1,n),d=rnd.next(1,(int)1e9),t=rnd.next(1,(int)1e9);
        while(b==a)b=rnd.next(1,n);
        printf("%d %d %d %d\n",a,b,d,t);
    }
    for(int i=0;i<q;i++){
        int d=rnd.next(1,(int)1e9),t=rnd.next(1,(int)1e9);
        printf("%d %d\n",d,t);
    }
//    for(int i=1;i<=m+1;i++){
//        for(int j=1;j<=m+1;j++){
//            printf("%d %d\n",i,j);
//        }
//    }
    return 0;
}