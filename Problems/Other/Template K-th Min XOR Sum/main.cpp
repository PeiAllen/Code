#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
template <const int MAXB, class T> struct XORBasis{
    vector<T> basis;
    int sz;
    XORBasis(){sz=0,basis.resize(MAXB+1,0);}
    T setsize(){return T(1)<<sz;}
    bool addvector(T a){
        for(int i=MAXB;i>=0;i--){
            if(!(a&(T(1)<<i)))continue;
            if (!basis[i]) {
                basis[i] = a;
                sz++;
                return true;
            }
            a ^= basis[i];
        }
        return false;
    }
    T kth(T a){
        T ans=0,am=setsize();
        if(a>am)return -1;
        for(int i=MAXB;i>=0;i--){
            if(!basis[i])continue;
            am>>=1;
            if((a>am)^(!!(ans&(T(1)<<i))))ans^=basis[i];
            if(a>am)a-=am;
        }
        return ans;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n;
    XORBasis<50,ll> arr;
    ll a;
    bool canmake0=false;
    for(int i=0;i<n;i++){
        cin>>a;
        canmake0|=!arr.addvector(a);
    }
    cin>>q;
    while(q--){
        cin>>a;
        printf("%lli\n",arr.kth(a+!canmake0));
    }
    return 0;
}