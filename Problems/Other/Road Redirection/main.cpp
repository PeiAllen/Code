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
const int MAXN=2e5+1;
int n,q;
vector<int> matrix[MAXN];
vector<pii> roads;
int cur[MAXN];
int depth[MAXN];
int ecur=1;
pii eind[MAXN];
int upam;
int bit[MAXN];
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
void dfs(int loc, int parent, int dep){
    depth[loc]=dep;
    eind[loc].first=ecur++;
    for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
    eind[loc].second=ecur-1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,q);
    int a,b;
    rep(i,1,n){
        sc(a,b);
        matrix[a].push_back(b);
        matrix[b].push_back(a);
        roads.push_back({a,b});
    }
    dfs(1,0,0);
    rep(i,0,n-1){
        cur[i]=depth[roads[i].second]<depth[roads[i].first];
        if(depth[roads[i].second]<depth[roads[i].first]){
            upam++;
        }
        else{
            update(eind[roads[i].second].first,1);
            update(eind[roads[i].second].second+1,-1);
        }
        if(depth[roads[i].second]<depth[roads[i].first])swap(roads[i].second,roads[i].first);
    }
    while(q--){
        sc(a,b);
        if(a==1){
            int te=query(eind[b].first);
            prl(upam-(depth[b]-te)+te);
        }
        else{
            b-=1;
            if(cur[b]){
                upam--;
                update(eind[roads[b].second].first,1);
                update(eind[roads[b].second].second+1,-1);
            }
            else{
                upam++;
                update(eind[roads[b].second].first,-1);
                update(eind[roads[b].second].second+1,1);
            }
            cur[b]=!cur[b];
        }
    }
    return 0;
}