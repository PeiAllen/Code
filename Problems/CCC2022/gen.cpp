#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(int argc, char *argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(atoi(argv[1]));
    uniform_int_distribution<int> ngen(1,5);
    int n=ngen(gen);
    printf("%d\n",n);
    for(int i=2;i<=n;i++){
        uniform_int_distribution<int> egen(1,i-1);
        printf("%d %d\n",egen(gen),i);
    }
    uniform_int_distribution<int> pgen(1,2);
    for(int i=1;i<=n;i++){
        if(pgen(gen)==1){
            printf("Y");
        }
        else printf("N");
    }
    printf("\n");
    uniform_int_distribution<int> cgen(1,100);
    for(int i=1;i<=n;i++)printf("%d%c",cgen(gen)," \n"[i==n]);
    return 0;
}