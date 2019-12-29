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
set<pair<pair<long double,int>,long double>> radi[501];
pair<long double,long double> coords[501];
long double prec=1e-7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    long double ax,ay,bx,by;
    sc(ax,ay,bx,by);
    if(ax==bx&&ay==by){
    	prl(0);
    	return 0;
    }
	long double x,y;
    int ans=INT_MAX;
    rep(i,0,n){
		sc(x,y);
		coords[i]={x,y};
		radi[i].insert({{pow(ax-x,2)+pow(ay-y,2),0},pow(ax-x,2)+pow(ay-y,2)});
		long double te=sqrt(pow(coords[i-1].first-x,2)+pow(coords[i-1].second-y,2));
		if(i)for(auto a:radi[i-1]){
		    pair<pair<long double,int>,long double> cur={{(a.first.first<te&&a.second>te?(long double)0:min(abs(te-a.first.first),abs(te-a.second))),a.first.second+1},te+a.second};
		    auto pt=radi[i].upper_bound(cur);
		    if(pt!=radi[i].begin()){
		        pt--;
		        if(pt->first.second<=cur.first.second){
                    cur.first.first=(pt->second>=cur.first.first?pt->second+prec:cur.first.first);
                    if(cur.first.first>cur.second)continue;
		        }
		        else{
                    pair<pair<long double,int>,long double> np=*pt;
                    np.second=(cur.first.first<=np.second?cur.first.first-prec:np.second);
                    pt++;
                    radi[i].erase(prev(pt,1));
                    radi[i].insert(np);
		        }
		    }
		    while(pt!=radi[i].end()){
		        if(pt->first.first>cur.second)break;
		        if(pt)
		    }
		}
		lli len=sqrt(pow(bx-x,2)+pow(by-y,2));
		auto pt=radi[i].upper_bound({{len,n+1},len});
		if(pt!=radi[i].begin()){
			pt--;
			if(pt->second>=len)ans=min(ans,pt->first.second);
		}
    }
    prl(-1);
    return 0;
}