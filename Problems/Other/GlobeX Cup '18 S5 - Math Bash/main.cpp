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
const int MAXN=801;
lli bit[MAXN][MAXN];
int n;
void update(int x,int y){
	for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=n;j+=j&-j)bit[i][j]+=1;
}
lli query(int x, int y){
	lli sum=0;
	for(int i=x;i>0;i-=i&-i)for(int j=y;j>0;j-=j&-j)sum+=bit[i][j];
	return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n);
    priority_queue<pair<lli,pair<int,pii>>,vector<pair<lli,pair<int,pii>>>,greater<pair<lli,pair<int,pii>>>> q;
    lli in;
    rep(i,1,n+1)rep(j,1,n+1){
    	sc(in);
    	q.push({in,{0,{i,j}}});
    }
    lli sum=0;
    while(sz(q)){
    	auto cur=q.top();
    	q.pop();
    	if(!cur.second.first){
    		lli te=(cur.second.second.first-1)*(cur.second.second.second-1)-query(cur.second.second.first-1,cur.second.second.second-1);
    		sum+=te;
    		q.push({te+cur.first,{1,cur.second.second}});
    	}
    	else{
    		update(cur.second.second.first,cur.second.second.second);
    	}
    }
    prl(sum);
    return 0;
}