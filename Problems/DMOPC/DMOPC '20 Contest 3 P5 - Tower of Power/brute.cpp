#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[3];
ll fp(ll a, ll b, ll mod){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll m;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        printf("%lli\n",arr[0]%m);
    }
    else if(n==2){
        printf("%lli\n",fp(arr[0],arr[1],m));
    }
    else{
        if(arr[0]%m==0)printf("0\n");
        else printf("%lli\n",fp(arr[0]%m,fp(arr[1],arr[2],m-1),m));
    }
    return 0;
}