#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
#ifndef dormi
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
#endif
#ifdef dormi
    clock_t start = clock();
#endif
    printf("Hello, World!\n");
#ifdef dormi
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f seconds.\n", elapsed);
#endif
    return 0;
}