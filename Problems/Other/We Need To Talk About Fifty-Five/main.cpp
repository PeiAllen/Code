#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
const ll mod=1e9+7;
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
ll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll v;
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>v>>arr[i];
        tot=fix(tot+v);
    }
    sort(arr,arr+n);
    ll am=1;
    for(int i=n-3;i>=0;i--){
        tot=fix(tot-(arr[i]*am%mod));
        am++;
    }
    printf("%lli\n",tot);
    return 0;
}