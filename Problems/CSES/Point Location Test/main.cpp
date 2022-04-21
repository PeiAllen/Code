#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
struct point{
    ll x,y;
    point(ll a=0, ll b=0){
        x=a,y=b;
    }
    point operator+(const point &a)const{
        return point(x+a.x,y+a.y);
    }
    point operator-()const{
        return point(-x,-y);
    }
    point operator-(const point &a)const {
        return (*this) + (-a);
    }
};
ll cross(const point &a, const point &b){
    return (a.x*b.y)-(a.y*b.x);
}
ll orient(const point &a, const point &b, const point &c){
    return cross(b-a,c-a);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        ll res=orient(point(a,b),point(c,d),point(e,f));
        if(res==0)printf("TOUCH\n");
        else if(res>0)printf("LEFT\n");
        else printf("RIGHT\n");
    }
    return 0;
}