#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==2||n==3){
        printf("NO SOLUTION\n");
        return 0;
    }
    for(int i=2;i<=n;i+=2){
        printf("%d ",i);
    }
    for(int i=1;i<=n;i+=2){
        printf("%d%c",i," \n"[i+2>n]);
    }
    return 0;
}