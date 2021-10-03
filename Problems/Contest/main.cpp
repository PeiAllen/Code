#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=2e5+1;
const long double PI=acos((long double)-1);
bool why(pll a,pll b){
    long double te=atan2(b.B,b.A)-atan2(a.B,a.A);
    if(te<0)te+=2*PI;
    return te<PI;
}
pll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].A>>arr[i].B;
    }
    sort(arr,arr+n,[&](const auto &lhs, const auto &rhs){
        return atan2((long double)lhs.B,(long double)lhs.A)<atan2((long double)rhs.B,(long double)rhs.A);
    });
    int rptr=0;
    pll loc={0,0};
    ll best=0;
    for(int i=0;i<n;i++){
        best=max(best,loc.A*loc.A+loc.B*loc.B);
        while(rptr<i+n&&((i==rptr)||why(arr[i],arr[rptr%n]))){
            loc.A+=arr[rptr%n].A;
            loc.B+=arr[rptr%n].B;
            best=max(best,loc.A*loc.A+loc.B*loc.B);
            rptr++;
        }
        loc.A-=arr[i].A;
        loc.B-=arr[i].B;
        best=max(best,loc.A*loc.A+loc.B*loc.B);
    }
    printf("%lli\n",best);
    return 0;
}

