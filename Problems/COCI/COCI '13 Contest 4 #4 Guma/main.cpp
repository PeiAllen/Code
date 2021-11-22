#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int tot[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n,n++;
    set<int> bottoms;
    for(int i=0;i<n;i++){
        cin>>a;
        bottoms.insert(a);
        for(int j=2;j*j<=a;j++){
            if(a%j==0){
                bottoms.insert(a/j);
                bottoms.insert(j);
            }
        }
    }
    for(int i=2;i<MN;i++)tot[i]=i;
    for(int i=2;i<MN;i++){
        if(tot[i]==i){
            for(int j=i;j<MN;j+=i)tot[j]-=tot[j]/i;
        }
    }
    ll ans=0;
    for(auto x:bottoms)ans+=tot[x];
    printf("%lli\n",ans);
    return 0;
}