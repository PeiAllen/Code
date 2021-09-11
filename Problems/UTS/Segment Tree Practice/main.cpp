#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll val[MN];
ll bit[MN];
int n,q;
void update(int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        update(i,val[i]);
    }
    char a;
    int b;
    ll c;
    while(q--){
        cin>>a>>b>>c;
        if(a=='S'){
            printf("%lli\n",query(c)-query(b-1));
        }
        else{
            update(b,c-val[b]);
            val[b]=c;
        }
    }
    return 0;
}