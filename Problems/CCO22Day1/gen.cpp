#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}

int main(int argc, char *argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(atoi(argv[1]));
    uniform_int_distribution<int> ns(1,3);
    int n1=ns(gen),n2=ns(gen);
    uniform_int_distribution<int> time(1,20);
    printf("%d %d %d\n",n1,n2,time(gen));
    int prev=1;
    for(int i=1;i<=n1;i++){
        uniform_int_distribution<int> t1(prev,30-(n1-i+1));
        int l=t1(gen);
        uniform_int_distribution<int> t2(l+1,30-(n1-i));
        int r=t2(gen);
        prev=r;
        printf("%d %d\n",l,r);
    }
    prev=1;
    for(int i=1;i<=n2;i++){
        uniform_int_distribution<int> t1(prev,30-(n2-i+1));
        int l=t1(gen);
        uniform_int_distribution<int> t2(l+1,30-(n2-i));
        int r=t2(gen);
        prev=r;
        printf("%d %d\n",l,r);
    }
    return 0;
}