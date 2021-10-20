#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("init.yml","w",stdout);
    printf("archive: data.zip\n"
           "checker: standard\n"
           "test_cases:\n"
           "- batched:\n"
           "  - {in: sample.in, out: sample.out}\n");
    printf("  points: 0\n");
    printf("- batched:\n");
    for(int i=1;i<=15;i++){
        printf("  - {in: in%d.txt, out: out%d.txt}\n",i,i);
    }
    printf("  points: 100\n");
    return 0;
}