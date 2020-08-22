#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int tot=0;
    int bought=n,leftover=0;
    while(bought){
        tot+=bought;
        int te=(bought+leftover)/k;
        leftover=(bought+leftover)%k;
        bought=te;
    }
    printf("%d\n",tot);
    return 0;
}