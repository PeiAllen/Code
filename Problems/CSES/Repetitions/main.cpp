#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    int last=0;
    int best=0;
    for(int i=0;i<sz(a);i++){
        if(a[i]!=a[last]){
            best=max(best,i-last);
            last=i;
        }
    }
    best=max(best,sz(a)-last);
    printf("%d\n",best);
    return 0;
}