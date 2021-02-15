#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod=998244353;
ll val[MN];
int rot[MN];
int le[MN],ri[MN];
int n,q;
int totrot;
ll getans(){
    if(n%2==1)return 0;
    ll ans=0;
    for(int i=0;i<n;i++){
        int ind=(i-totrot+n)%n;
        int l=(le[i]-rot[ind]+n)%n,r=(ri[i]-rot[ind]+n)%n;
        if(l<=r)ans=(ans+val[r]-(l-1>=0?val[l-1]:0)+mod)%mod;
        else ans=(ans+val[n-1]-val[l-1]+mod+val[r])%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    le[0]=(n/2)-(n-1)/2/2,ri[0]=(n/2)+(n-1)/2/2;
    for(int i=0;i<n;i++){
        cin>>val[i];
        if(i)val[i]=(val[i]+val[i-1])%mod,le[i]=(le[i-1]+1)%n,ri[i]=(ri[i-1]+1)%n;
    }
    printf("%lli\n",getans());
    int a,b,c;
    while(q--){
        cin>>a>>b;
        if(a==1)totrot=(totrot+b)%n;
        else cin>>c,rot[(b-totrot+n)%n]=(rot[(b-totrot+n)%n]+c)%n;
        printf("%lli\n",getans());
    }
    return 0;
}