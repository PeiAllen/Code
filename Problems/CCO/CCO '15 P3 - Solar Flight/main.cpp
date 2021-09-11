#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e3+1;
pair<pll,ll> plane[MAXN];
struct Frac{
    ll x,y;
    Frac(ll a, ll b){
        x=a,y=b;
        if(y<0)x*=-1,y*=-1;
        int gc=__gcd(abs(x),abs(y));
        x/=gc,y/=gc;
    }
    bool operator<(const Frac & a)const {
        return __int128(x)*__int128(a.y)<__int128(y)*__int128(a.x);
    }
};
vector<pair<Frac,pll>> ranges[MAXN];
struct RMQ{
    ll sparse[11][MAXN];
    void make(int a){
        for(int i=0;i<sz(ranges[a]);i++)sparse[0][i]=max(ranges[a][i].second.first,ranges[a][i].second.second);
        for(int i=1;i<11;i++){
            for(int j=0;j<=sz(ranges[a])-(1<<i);j++){
                sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
            }
        }
    }
    ll query(int l, int r){
        if(r<l)return 0;
        int k=log2(r-l+1);
        return max(sparse[k][l],sparse[k][r-(1<<k)+1]);
    }
}getmax[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll d,k;
    int n,q;
    cin>>d>>k>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>plane[i].first.first>>plane[i].first.second>>plane[i].second;
    }
    for(int i=1;i<=n;i++){
        map<Frac,pll> updates;
        updates[Frac(0,1)]={0,0};
        for(int j=1;j<=n;j++){
            if(i!=j){
                if((plane[i].first.first>plane[j].first.first)==(plane[i].first.second>plane[j].first.second)){
                    if(plane[j].first.first>plane[i].first.first)updates[Frac(0,1)].first+=plane[j].second,updates[Frac(0,1)].second+=plane[j].second;
                }
                else{
                    Frac inter=Frac((plane[j].first.first-plane[i].first.first)*d,plane[i].first.second-plane[i].first.first-plane[j].first.second+plane[j].first.first);
                    if(plane[j].first.first>plane[i].first.first){
                        updates[Frac(0,1)].first+=plane[j].second,updates[Frac(0,1)].second+=plane[j].second;
                        updates[inter].first-=plane[j].second,updates[inter].second-=plane[j].second;
                    }
                    else updates[inter].second+=plane[j].second;
                }
            }
        }
        ll val=0;
        for(auto x:updates){
            ranges[i].push_back({x.first,{val+x.second.first,val+x.second.second}});
            val+=x.second.second;
        }
        getmax[i].make(i);
    }
    int a;
    ll b;
    while(q--){
        cin>>a>>b;
        Frac l(b,1),r(b+k,1);
        int le=upper_bound(ranges[a].begin(),ranges[a].end(),pair<Frac,pll>{l,{LLONG_MAX,LLONG_MAX}})-ranges[a].begin();
        int ri=lower_bound(ranges[a].begin(),ranges[a].end(),pair<Frac,pll>{r,{0,0}})-ranges[a].begin();
        ll ma=max(getmax[a].query(le,ri-1),ranges[a][le-1].second.second);
        if(!(ranges[a][le-1].first<l))ma=max(ma,ranges[a][le-1].second.first);
        if(ri<sz(ranges[a])&&!(r<ranges[a][ri].first))ma=max(ma,ranges[a][ri].second.first);
        printf("%lli\n",ma);
    }
    return 0;
}