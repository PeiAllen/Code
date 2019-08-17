#include <bits/stdc++.h>
//#include "slow.cpp"
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli n,x,y;
lli mod=998244353;
lli eulermod=998244352;
double logx,logy;
const int maxpow=600;
lli stoream[maxpow][maxpow];
lli fastpow(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	return ans;
}
struct comp{
	bool operator()(const pll& a, const pll& b)const {
		lli xm=min(a.first,b.first);
		lli tm=min(a.second,b.second);
		pair<double,double> fi;
		pair<double,double> se;
		if(a.first==xm){
			fi={logy,a.second-tm};
		}
		else{
			fi={logx,a.first-xm};
		}
		if(b.first==xm){
			se={logy,b.second-tm};
		}
		else{
			se={logx,b.first-xm};
		}
		return fi.second*fi.first>se.second*se.first;
	}
};
lli minmut(lli a, lli b){
	lli ans=0;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=min(n,ans+a);
		a=min(a+a,n);
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	map<pair<lli,pll>,lli> ans;
	while(t--){
		cin>>n>>x>>y;
		if(ans.count({n,{x,y}}))printf("%lli\n",ans[{n,{x,y}}]);
		logx=log(x);
		logy=log(y);
		memset(stoream,0, sizeof(stoream));
	//	slow(n,x,y);
		priority_queue<pll,vector<pll>,comp> store;
		store.push({1,1});
		stoream[1][1]=1;
		lli xpow=1;
		lli ypow=1;
		vector<pair<pll,lli>> storage;
		storage.push_back({{1,0},1});
		storage.push_back({{0,1},1});
		while(n){
			pll a=store.top();
			store.pop();
			lli team=stoream[a.first][a.second];
			lli touse=min(n,team);
			xpow=(xpow+(a.first*touse%eulermod))%eulermod;
			ypow=(ypow+(a.second*touse%eulermod))%eulermod;
			n-=touse;
			if(n) {
				bool done=false;
				for (auto b:storage) {
					lli tea=a.first+b.first.first;
					lli teb=a.second+b.first.second;
					if(stoream[tea][teb]==0)store.push({tea,teb});
					stoream[tea][teb] =min(n,stoream[tea][teb]+minmut(b.second,team));
					if(stoream[tea][teb]==n){
						done=true;
						break;
					}
				}
				if(team>1&&!done){
					lli tea=a.first*2;
					lli teb=a.second*2;
					lli oth=team-1;
					lli othoth=team;
					if(othoth%2==0)othoth/=2;
					else oth/=2;
					if(stoream[tea][teb]==0)store.push({tea,teb});
					stoream[tea][teb]=min(n,stoream[tea][teb]+(minmut(othoth,oth)));
				}
			}
			storage.push_back({a,team});
		}
		lli prod=fastpow(x,xpow)*fastpow(y,ypow)%mod;
		ans[{n,{x,y}}]=prod;
		printf("%lli\n",prod);
	}
	return 0;
}