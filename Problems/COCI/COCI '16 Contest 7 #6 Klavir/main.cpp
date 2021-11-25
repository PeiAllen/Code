#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=1e6+1;
ll needed[MN];
int arr[MN];
int pi[MN];
ll sumofalllast[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    needed[0]=0;
    cin>>arr[1];
    needed[1]=n;
    printf("%lli\n",needed[1]);
    sumofalllast[0]=n;
    for(int i=2;i<=m;i++){
        cin>>arr[i];
        int loc=pi[i-2];
        while(loc>0&&arr[i]!=arr[loc+1])loc=pi[loc-1];
        if(arr[i]==arr[loc+1])loc++;
        pi[i-1]=loc;
        ll sum=n+needed[i-1]*(n-1)%mod;
        sum=(sum-sumofalllast[pi[i-2]]+needed[pi[i-1]]+mod)%mod;
        needed[i]=(needed[i-1]+sum)%mod;
        sumofalllast[i-1]=(sumofalllast[pi[i-2]]-needed[pi[i-1]]+mod+needed[i])%mod;
        printf("%lli\n",needed[i]);
    }
    return 0;
}