#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

template<typename T>
struct point{
    T x,y;
    point(T a=0, T b=0){
        x=a,y=b;
    }
    point<T> operator+(const point<T> &a)const{
        return point<T>(x+a.x,y+a.y);
    }
    point<T> operator-()const{
        return point<T>(-x,-y);
    }
    point<T> operator-(const point<T> &a)const{
        return *this+(-a);
    }
};

template<typename T>
T cross(const point<T> &a, const point<T> &b){
    return a.x*b.y-a.y*b.x;
}

template<typename T>
vector<point<T>> sum(vector<point<T>> a, vector<point<T>> b){

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    return 0;
}