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
vector<pii> matrix[MAXN];
int ind[MAXN];
int low[MAXN];
int partof[MAXN];
int edgecnt[MAXN];
bool onst[MAXN];
stack<int> st;
int id=1;
int gid=1;
void tarj(int loc, int from){
    ind[loc]=id++;
    low[loc]=ind[loc];
    st.push(loc);
    onst[loc]=true;
    for(auto x:matrix[loc]){
        if(x.second!=from){
            if(!ind[x.first]){
                tarj(x.first,x.second);
                low[loc]=min(low[loc],low[x.first]);
            }
            else if(onst[x.first])low[loc]=min(low[loc],ind[x.first]);
        }
    }
    if(low[loc]==ind[loc]){
        while(1){
            int cur=st.top();
            st.pop();
            partof[cur]=gid;
            onst[cur]=false;
            if(cur==loc)break;
        }
        gid++;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,r;
    sc(n,r);
    int a,b;
    rep(i,0,r){
        sc(a,b);
        matrix[a].push_back({b,i});
        matrix[b].push_back({a,i});
    }
    tarj(1,-1);
    rep(i,1,n+1){
        for(auto x:matrix[i]){
            if(partof[i]!=partof[x.first]){
                edgecnt[partof[x.first]]++;
            }
        }
    }
    int cnt=0;
    rep(i,1,gid){
        if(edgecnt[i]==1)cnt++;
    }
    prl((cnt+1)/2);
    return 0;
}