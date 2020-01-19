#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=2e5+1;
vector<int,pll> matrix[MAXN];
lli st[MAXN];
pll dist[MAXN];
struct comp {
    bool operator()(pair<int, pll> lhs, pair<int, pll> rhs) {
        return (double)lhs.second.first/(double)lhs.second.second>(double)rhs.second.first/(double)rhs.second.second;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,1,n+1){
        sc(st[i]);
        rep(j,1,i){
            if(st[i]>=st[j]){
                lli a=st[i]-st[j];
                lli b=i-j;
                lli g=__gcd(a,b);
                matrix[i].push_back({j,{a/g,b/g}});
                matrix[j].push_back({i,{a/g,b/g}});
            }
        }
    }
    rep(i,1,n+1){
        dist[i]={0,1};
        priority_queue<pair<int,pll>,vector<pair<int,pll>>,comp()> q;
        q.push({i,{0,1}});
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            if(!comp(cur.second,dist[cur.first])){
                for(auto x:matrix[cur.first]){
                    if(!comp(cur))
                }
            }
        }
    }
    return 0;
}