#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
struct dsu{
    pii t[MN];
    void reset(int n){
        for(int i=0;i<=n;i++)t[i]={i,1};
    }
    int find(int a){
        if(t[a].first==a)return a;
        return t[a].first=find(t[a].first);
    }
    bool uni(int a, int b){
        int ap=find(a),bp=find(b);
        if(ap==bp)return false;
        if(t[ap].second<t[bp].second)swap(ap,bp);
        t[ap].second+=t[bp].second;
        t[bp].first=ap;
        return true;
    }
}ranges[__lg(MN)+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b,c,d;
    for(int i=0;i<=__lg(n);i++)ranges[i].reset(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        for(int j=__lg(n);j>=0;j--){
            if(a+(1<<j)-1<=b){
                ranges[j].uni(a,c);
                a+=(1<<j);
                c+=(1<<j);
            }
        }
    }
    for(int i=__lg(n)-1;i>=0;i--){
        for(int j=1;j+(1<<(i+1))-1<=n;j++){
            ranges[i].uni(j,ranges[i+1].find(j));
            ranges[i].uni(j+(1<<i),ranges[i+1].find(j)+(1<<i));
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(ranges[0].find(i)==i)cnt++;
    }
    printf("%lli\n",fp(10,cnt-1)*ll(9)%mod);
    return 0;
}