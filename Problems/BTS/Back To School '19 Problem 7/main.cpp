#include <bits/stdc++.h>
//#include "slow.cpp"
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli n,x,y;
lli mod=998244353;
lli memo[2][30000];
lli fastpow(lli a, lli b){
	int wh=2;
	if(a==x)wh=0;
	else if(a==y)wh=1;
	if(wh!=2&&memo[wh][b]!=0)return memo[wh][b];
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=ans*a%mod;
		}
		a=a*a%mod;
	}
	if(wh!=2)memo[wh][b]=ans;
	return ans;
}
struct comp{
	bool operator()(const pll& a, const pll& b)const {
		lli xm=min(a.first,b.first);
		lli tm=min(a.second,b.second);
		pair<double,double> fi;
		pair<double,double> se;
		if(a.first==xm){
			fi={y,a.second-tm};
		}
		else{
			fi={x,a.first-xm};
		}
		if(b.first==xm){
			se={y,b.second-tm};
		}
		else{
			se={x,b.first-xm};
		}
		return fi.second*log(fi.first)<se.second*log(se.first);
	}
};

lli modmut(lli a, lli b){
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
	while(t--){
		cin>>n>>x>>y;
		memset(memo,0,sizeof(memo));
		//slow(n,x,y);
		map<pll,lli,comp> store;
		store[{1,1}]=1;
		lli prod=x*y%mod;
		vector<pair<pll,lli>> storage;
		storage.push_back({{1,0},1});
		storage.push_back({{0,1},1});
		while(n){
			auto a=*store.begin();
			store.erase(store.begin());
			lli touse=min(n,a.second);
			//printf("%lli %lli\n",fastpow(x,a.first.first)*fastpow(y,a.first.second)%mod,a.second);
			//printf("%lli %lli %lli %d %d\n",n,a.second,fastpow(x,a.first.first)*fastpow(y,a.first.second)%mod,a.first.first,a.first.second);
			prod=prod*fastpow(fastpow(x,a.first.first)*fastpow(y,a.first.second)%mod,touse)%mod;
			n-=touse;
			if(n) {
				for (auto b:storage) {
					pll te={a.first.first+b.first.first,a.first.second+b.first.second};
					store[te] =min(n,store[te]+modmut(b.second,a.second));
				}
				if(a.second>1){
					pll te={a.first.first*2,a.first.second*2};
					store[te]=min(n,store[te]+(modmut(a.second,a.second-1)*499122177%mod));
				}
			}
			storage.push_back({a.first,a.second});
		}
		printf("%lli\n",prod);
	}
	return 0;
}