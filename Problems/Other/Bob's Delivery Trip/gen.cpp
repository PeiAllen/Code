#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int parent[MAXN];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=10,q=20;
    printf("%d %d\n",n,q);
    for(int i=1;i<=n;i++)printf("%lli ",rnd.next(ll(1),ll(20)));
    printf("\n");
    for(int i=2;i<=n;i++){
        parent[i]=rnd.next(1,i-1);
        printf("%d %d %lli\n",i,parent[i],rnd.next(ll(1),ll(10)));
    }
    while(q--){
        int op=rnd.next(1,2);
        printf("%d ",op);
        if(op==1){
            printf("%d %lli\n",rnd.next(1,n),rnd.next(ll(1),ll(20)));
        }
        else{
            int node=rnd.next(2,n);
            printf("%d %d %lli\n",node,parent[node],rnd.next(ll(1),ll(10)));
        }
    }
    return 0;
}