#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct line{
    ll m,b;
    line(ll a=0, ll c=0){m=a,b=c;}

};
struct func{
    line f;
    priority_queue<pll> p;
    func(line a=line(),priority_queue<pll> b=priority_queue<pll>()){f=a,p=move(b);}
    void transform(){

    }
    ll at(ll x){

    }
    void add(const func& a){
        f+=a.f;

    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}