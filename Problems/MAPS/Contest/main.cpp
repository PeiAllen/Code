#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, i, j, x, ans, dn; __int128 sna, res;

ll popcount(ll x){
    ll ret=0;
    while(x) x-=x&-x, ret++;
    return ret;
}

void rec(int d,int lst,__int128 res){
    if(!d){
        if(j<ans&&res%x==0){
            sna = res;
            ans = j;
            dn = 1;
        }
        return;
    }
    for(ll i=0;i<lst;i++){
        rec(d-1,i,res|(((__int128)1)<<i));
        if(dn) return;
    }
}

int main(){
    for(scanf("%lld",&N);N;N--){
        scanf("%lld",&x);
        ans = 6;
        for(j=1;j<10000000;j++){
            if(popcount(x*j)<ans){
                sna = x*j;
                ans = popcount(x*j);
            }
        }
        int lim = ans;
        long double kek = 1;
        while(kek*(lim+1)/(lim+1-ans)<5e7&&lim<130)
            kek*=(lim+1)/(long double)(lim+1-ans), lim++;
        for(j=1;j<=ans;j++) dn=0,rec(j,min(lim+1,127),0);
        for(j=0;j<128;j++){
            if((((__int128)1)<<j)&sna) printf("%lld ",j);
        }
        printf("\n");
    }
    return 0;
}
