#include <bits/stdc++.h>
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
const int MAXN=1e5+1;
int n,q;
pii dis[MAXN];
int find(int a){
    if(dis[a].first==a)return a;
    return dis[a].first=find(dis[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(dis[ap].second<dis[bp].second)swap(ap,bp);
    dis[ap].second+=dis[bp].second;
    dis[bp].first=ap;
}
vector<pair<pair<lli,int>,pii>> edges;
int ans[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,q);
    int a,b;
    lli c;
    dis[n]={n,1};
    rep(i,1,n){
        dis[i]={i,1};
        sc(a,b,c);
        edges.push_back({{-c,0},{a,b}});
    }
    rep(i,0,q){
        sc(c,a);
        edges.push_back({{-c,1},{a,i}});
    }
    sort(edges.begin(),edges.end());
    for(auto x:edges){
        if(x.first.second==1){
            ans[x.second.second]=dis[find(x.second.first)].second-1;
        }
        else{
            uni(x.second.first,x.second.second);
        }
    }
    rep(i,0,q)prl(ans[i]);
    return 0;
}