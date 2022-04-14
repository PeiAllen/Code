#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

const long double PI=acos(-1);

template <typename T>
struct point{
    T x,y;
    point(T a, T b){
        x=a,y=b;
    }
    point(complex<T> a){
        x=a.real(),y=a.imag();
    }
    complex<T> complex(){
        return {x,y};
    }
    point operator+(const point &a) const{
        return point(x+a.x,y+a.y);
    }
    point operator-()const{
        return point(-x,-y);
    }
    point operator-(const point &a)const{
        return this+(-a);
    }
    point operator*(const T &a)const{
        return point(x*a,y*a);
    }
    point operator/(const T &a)const{
        return point(x/a,y/a);
    }
};

template<typename T>
T sq(const point<T> &a){
    return a.x*a.x+a.y*a.y;
}

template<typename T>
long double abs(const point<T> &a){
    return sqrtl(sq(a));
}

template <typename T>
point<T> perp(const point<T> &a){
    return point<T>(-a.y,a.x);
}

template<typename T>
point<T> scale(const point<T> &a, const T &f){
    return a*f;
}

template<typename T>
point<T> scalewrtp(const point<T> &a, const T &f, const point<T> &p){
    return p+scale(a-p,f);
}

template<typename T>
point<T> rot(const point<T> &a, const long double &rt){
    return point<T>(a.complex()*polar<T>(1.0,rt));
}

template<typename T>
point<T> rotwrtp(const point<T> &a, const long double &rt, const point<T> &p){
    return p+rot(a-p,rt);
}

template<typename T>
T dot(const point<T> &a, const point<T> &b){
    return a.x*b.x+a.y*b.y;
}

template<typename T>
T cross(const point<T> &a, const point<T> &b){
    return a.x*b.y-a.y*b.x;
}

template<typename T>
long double ang(const point<T> &a, const point<T> &b){
    return arccos(max(T(-1),min(T(1),dot(a,b)/abs(a)/abs(b))));
}

template<typename T>
T orient(const point<T> &a, const point<T> &b,const point<T> &c){
    return cross(b-a,c-a);
}

template<typename T>
long double ang(const point<T> &a, const point<T> &b,const point<T> &c){
    return ang(a-b,c-b);
}

template<typename T>
long double oang(const point<T> &a, const point<T> &b,const point<T> &c){
    if(orient(a,b,c)<=0)return ang(a-b,c-b);
    return 2*PI-ang(a-b,c-b);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}