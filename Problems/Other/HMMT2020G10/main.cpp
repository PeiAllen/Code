#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt=0;
    for(int i=1;i<=10000;i++){
        int val=i;
        for(int j=1;j<30;j++){
            val=j*(val/j)+1;
        }
        if(val==30)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}