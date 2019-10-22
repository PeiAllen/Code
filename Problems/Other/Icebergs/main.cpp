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
const int MAXN=2005;
int arr[MAXN][MAXN];
int dist[MAXN][MAXN];
int xr[4]={1,-1,0,0};
int yr[4]={0,0,1,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c,l,w;
    sc(r,c,l,w);
    char in;
    rep(i,1,r+1)rep(j,1,c+1){
    	dist[i][j]=-1;
    	sc(in);
    	if(in=='#'){
    		arr[max(1,i-l+1)][max(1,j-w+1)]+=1;
		    arr[max(1,i-l+1)][j+1]-=1;
		    arr[i+1][max(1,j-w+1)]-=1;
		    arr[i+1][j+1]+=1;
	    }
    }
    rep(i,1,r+1){
    	rep(j,1,c+1){
    		arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
    	}
    }
    queue<pair<int,pii>> q;
    if(!arr[1][1]) {
	    dist[1][1] = 0;
	    q.push({0, {1, 1}});
    }
    while(sz(q)){
    	auto cur=q.front();
    	q.pop();
    	rep(i,0,4){
    		pii ne={cur.second.first+xr[i],cur.second.second+yr[i]};
    		if(ne.first>0&&ne.first<=r&&ne.second>0&&ne.second<=c){
    			if(!arr[ne.first][ne.second]&&dist[ne.first][ne.second]==-1){
    				dist[ne.first][ne.second]=cur.first+1;
    				q.push({cur.first+1,ne});
    			}
    		}
    	}
    }
    int best=INT_MAX;
    rep(i,0,l){
    	rep(j,0,w){
    		if(dist[r-i][c-j]!=-1)best=min(best,dist[r-i][c-j]);
    	}
    }
    if(best==INT_MAX)prl(-1);
    else prl(best);
    return 0;
}