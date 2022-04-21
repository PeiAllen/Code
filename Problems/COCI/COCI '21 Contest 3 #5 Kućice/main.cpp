#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1001;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
struct point{
    ll x,y;
    point(ll a=0, ll b=0){
        x=a,y=b;
    }
    point operator-()const{
        return point(-x,-y);
    }
    point operator+(const point &a) const{
        return point(x+a.x,y+a.y);
    }
    point operator*(const ll a)const{
        return point(x*a,y*a);
    }
    point operator-(const point &a)const{
        return (*this)+(-a);
    }
};
ll dot(const point &a, const point &b){
    return a.x*b.x+a.y*b.y;
}
ll cross(const point &a, const point &b){
    return a.x*b.y-a.y*b.x;
}
ll orient(const point &a, const point &b, const point &c){
    return cross(b-a,c-a);
}
bool bothalf(const point &a){
    if(a.y==0)return a.x<0;
    return a.y<0;
}
bool sameplane(const point &a, const point &b){
    if(cross(a,b)==0){
        return bothalf(a)==bothalf(b)&&abs(a.x)<abs(b.x);
    }
    return cross(a,b)>0;
}
point arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        vector<point> te;
        for(int j=1;j<=n;j++)if(j!=i)te.push_back(arr[i]);
        sort(te.begin(),te.end(),[&](const auto &lhs, const auto& rhs){
            return pll{half(lhs),0}<pll{half(rhs),cross(lhs,rhs)};
        });
        ans=(ans+fp(2,n-1))%mod;
        ll tot=fp(2,n-1);
        int r=0;
        auto nex=[&](int a){
            return (a+1)%sz(te);
        };
        for(int j=0;j<sz(te);j++){
            if(nex(r)==j)r=nex(r);
            while(nex(r)!=j&&sameplane(te[j],te[nex(r)]))r=nex(r);
            tot=(tot-((r+sz(te)-j)%sz(te)+1)+mod)%mod;
        }
        ans=(ans+tot)%mod;
    }
    printf("%lli\n",ans);
    return 0;
}