#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
struct point{
    ll x,y;
    point(ll a, ll b){
        x=a,y=b;
    }
    point operator+(point a) const{
        return point(x+a.x,y+a.y);
    }
    point operator-()const{
        return point(-x,-y);
    }
    point operator-(point a)const{
        return point(x-a.x,y-a.y);
    }
};
ll dot(point a, point b){
    return a.x*b.x+a.y*b.y;
}
ll cross(point a, point b){
    return a.x*b.y-a.y*b.x;
}
ll orient(point a, point b, point c){
    return cross(b-a,c-a);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    return 0;
}