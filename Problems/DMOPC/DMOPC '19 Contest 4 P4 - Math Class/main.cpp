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
long double prec=1e-11;
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
		radi[i].insert({{sqrt(pow(ax-x,2)+pow(ay-y,2)),1},sqrt(pow(ax-x,2)+pow(ay-y,2))});
		rep(j,0,i){
			long double te=sqrt(pow(coords[j].first-x,2)+pow(coords[j].second-y,2));
			for(auto a:radi[j]){
				pair<pair<long double,int>,long double> cur={{(a.first.first<te&&a.second>te?(long double)0:min(abs(te-a.first.first),abs(te-a.second))),a.first.second+1},te+a.second};
				auto pt=radi[i].upper_bound(cur);
				if(pt!=radi[i].begin()){
					pt--;
					if(pt->first.second<=cur.first.second){
						cur.first.first=(pt->second>=cur.first.first?pt->second+prec:cur.first.first);
						pt++;
						if(cur.first.first>cur.second)continue;
					}
					else{
						pair<pair<long double,int>,long double> np=*pt;
						np.second=(cur.first.first<=np.second?cur.first.first-prec:np.second);
						pt++;
						radi[i].erase(prev(pt,1));
						if(np.first.first<=np.second)radi[i].insert(np);
					}
				}
				bool insert=true;
				while(pt!=radi[i].end()){
					if(pt->first.first>cur.second)break;
					if(pt->second>=cur.second){
						if(pt->first.second<=cur.first.second){
							cur.second=pt->first.first-prec;
							if(cur.second<cur.first.first){
								insert=false;
							}
						}
						else{
							pair<pair<long double,int>,long double> np=*pt;
							np.first.first=cur.second+prec;
							pt++;
							radi[i].erase(prev(pt,1));
							if(np.first.first<=np.second)radi[i].insert(np);
						}
						break;
					}
					else{
						if(pt->first.second<cur.first.second){
							if(pt->first.first-prec>=cur.first.first)radi[i].insert(pair<pair<long double,int>,long double>{{cur.first.first,cur.first.second},pt->first.first-prec});
							cur.first.first=pt->second+prec;
							pt++;
							if(cur.second<cur.first.first){
								insert=false;
								break;
							}
						}
						else{
							pt++;
							radi[i].erase(prev(pt,1));
						}
					}
				}
				if(insert)radi[i].insert(cur);
			}
		}
		long double len=sqrt(pow(bx-x,2)+pow(by-y,2));
		auto pt=radi[i].upper_bound({{len,n+1},len});
		if(pt!=radi[i].begin()){
			pt--;
			if(pt->second>=len)ans=min(ans,pt->first.second);
		}
	}
	assert(ans<=n||ans==INT_MAX);
	if(ans==INT_MAX)prl(-1);
	else prl(ans);
	return 0;
}