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
    ll k;
    cin>>k;
    for(ll i=1;i<=1e6+1;i++){
        ll leftover=k-i*(i-1)/2;
        if(leftover<0)break;
        ll checkloc=sqrtl(2*leftover);
        for(ll off=-2;off<=2;off++){
            if(off+checkloc>=0){
                if((off+checkloc)*(off+checkloc-1)/2==leftover){
                    if(off+checkloc+i-1<=ll(1e6)&&off+checkloc+i-1>=1){
                        int n=off+checkloc+i-1;
                        printf("%d\n",n);
                        for(int j=1;j<i;j++){
                            printf("2%c"," \n"[j==n]);
                        }
                        if(i<=n)printf("3%c"," \n"[i==n]);
                        for(int j=i+1;j<=n;j++){
                            printf("2%c"," \n"[j==n]);
                        }
                        return 0;
                    }
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

//(a)*(a-1)/2 + b*(b-1)/2 = k