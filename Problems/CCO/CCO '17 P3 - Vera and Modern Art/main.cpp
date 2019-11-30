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
lli maxbit=59;
const int MAXC=1e6;
lli bit[MAXC];
int c;
void update(int loc, lli am){
	for(;loc<=c;loc+=loc&-loc)bit[loc]+=am;
}
lli start(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
	return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    sc(n,q);
    vector<lli> ycoords;
    priority_queue<pair<pair<lli,int>,pair<pll,lli>>,vector<pair<pair<lli,int>,pair<pll,lli>>>,greater<pair<pair<lli,int>,pair<pll,lli>>>> qu;
    lli x,y,v;
    rep(i,0,n){
		sc(x,y,v);
		lli newx=0,newy=0;
		lli am=0;
		while(x){
			if(x&(lli)1)newx+=((lli)1<<(maxbit-am));
			am++;
			x>>=(lli)1;
		}
	    am=0;
	    while(y){
		    if(y&(lli)1)newy+=((lli)1<<(maxbit-am));
		    am++;
		    y>>=(lli)1;
	    }
	    qu.push({{newx-(newx&-newx)+1,0},{{newy-(newy&-newy)+1,newy+(newy&-newy)},v}});
	    qu.push({{newx+(newx&-newx),1},{{newy-(newy&-newy)+1,newy+(newy&-newy)},-v}});
	    ycoords.push_back(newy-(newy&-newy)+1);
	    ycoords.push_back(newy+(newy&-newy));
    }
    lli ans[q];
    rep(i,0,q){
	    sc(x,y);
	    lli newx=0,newy=0;
	    lli am=0;
	    while(x){
		    if(x&(lli)1)newx+=((lli)1<<(maxbit-am));
		    am++;
		    x>>=(lli)1;
	    }
	    am=0;
	    while(y){
		    if(y&(lli)1)newy+=((lli)1<<(maxbit-am));
		    am++;
		    y>>=(lli)1;
	    }
	    qu.push({{newx,2},{{newy,-1},i}});
	    ycoords.push_back(newy);
    }
    sort(ycoords.begin(),ycoords.end());
    ycoords.erase(unique(ycoords.begin(),ycoords.end()),ycoords.end());
    c=sz(ycoords);
    while(sz(qu)){
    	auto cur=qu.top();
    	qu.pop();
    	if(cur.first.second==2){
    		ans[cur.second.second]=start((lower_bound(ycoords.begin(),ycoords.end(),cur.second.first.first)-ycoords.begin())+1);
    	}
    	else{
    		update((lower_bound(ycoords.begin(),ycoords.end(),cur.second.first.first)-ycoords.begin())+1,cur.second.second);
		    update((lower_bound(ycoords.begin(),ycoords.end(),cur.second.first.second)-ycoords.begin())+1,-cur.second.second);
    	}
    }
    rep(i,0,q)prl(ans[i]);
    return 0;
}