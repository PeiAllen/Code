#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
map<int,set<pii>> same;
map<int,set<pii>> same2;
map<char,int> conver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m;
    int k;
    cin>>n>>m>>k;
    char a;
    int x,y;
    conver['+']=0;
    conver['-']=1;
    bool plusfirst=true,minusfirst=true;
    for(int i=0;i<k;i++){
        cin>>a>>x>>y;
        same[x].insert({conver[a],y%2});
        same2[y].insert({conver[a],x%2});
        if(a=='+'){
            if((x+y)%2==0)minusfirst=false;
            else plusfirst=false;
        }
        else{
            if((x+y)%2==0)plusfirst=false;
            else minusfirst=false;
        }
    }
    bool work=true;
    int cnt=0;
    for(auto cur:same){
        if(sz(cur.second)==1||(sz(cur.second)==2&&cur.second.begin()->first!=cur.second.rbegin()->first&&cur.second.begin()->second!=cur.second.rbegin()->second)){
            cnt++;
        }
        else work=false;
    }
    ll ans=0;
    if(work)ans=fp(2,n-cnt);
    work=true;
    cnt=0;
    for(auto cur:same2){
        if(sz(cur.second)==1||(sz(cur.second)==2&&cur.second.begin()->first!=cur.second.rbegin()->first&&cur.second.begin()->second!=cur.second.rbegin()->second)){
            cnt++;
        }
        else work=false;
    }
    if(work)ans=(ans+fp(2,m-cnt))%mod;
    if(plusfirst)ans-=1;
    if(minusfirst)ans-=1;
    ans=(ans+mod)%mod;
    printf("%lli\n",ans);
    return 0;
}