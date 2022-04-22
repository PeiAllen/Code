#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const ll MN=1e6+1;
int arr[MN];
int bit[MN];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int am){
    int loc=0;
    for(int i=__lg(n);i>=0;i--){
        if(loc+(1<<i)<=n&&bit[loc+(1<<i)]<am){
            loc+=(1<<i);
            am-=bit[loc];
        }
    }
    return loc+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)update(i,1);
    for(int i=1;i<=n;i++){
        ll lo=0,hi=(n-i)/2;
        while(lo!=hi){
            ll mid=(lo+hi+1)/2;
            if(mid*(n-i-mid)<=k)lo=mid;
            else hi=mid-1;
        }
        k-=lo*(n-i-lo);
        int loc=query(lo+1);
        arr[loc]=i;
        update(loc,-1);
    }
    if(k>0)printf("-1\n");
    else{
        for(int i=1;i<=n;i++)printf("%d%c",arr[i]," \n"[i==n]);
    }
    return 0;
}