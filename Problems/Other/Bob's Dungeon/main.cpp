#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll MN=2e5+1;
struct line{
    ll m,b;
    line(ll a=0,ll c=0){
        m=a,b=c;
    }
};
struct func{
    line f;
    priority_queue<ll> p;
    ll offset;
    func(line a=line(), priority_queue<ll> b={}){
        f=a;
        p=move(b);
    }
    void translate(ll a){
        offset+=a;
        f.b-=f.m*a;
    }
    void pop(){
        f.m-=1,f.b+=(p.top()+offset);
        p.pop();
    }
};
ll cost[MN];
ll pay[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>pay[i];
    for(int i=1;i<=n;i++)cin>>cost[i];
    int s,t;
    ll u;
    while(m--){
        cin>>s>>t>>u;
        func a;
        for(int i=s;i<=t;i++){
            while(a.f.m>cost[i])a.pop();
            a.add(func(line(cost[i],0),{}));
            if(i!=t)a.translate(pay[i]);
        }

    }
    return 0;
}