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
vector<int> cango[1000];
string a,b;
//bool reach[1001][6];
lli inv[1001];
lli hashs[2][1001];
lli mod=1e9+9;
lli mut=31;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
lli fix(lli a){
	if(a<0)a+=mod;
	return a%mod;
}
void hh(){
	lli cur=1;
	for(int i=0;i<sz(a);i++){
		hashs[0][i+1]=(hashs[0][i]+(cur*(a[i]-'a')%mod))%mod;
		hashs[1][i+1]=(hashs[1][i]+(cur*(b[i]-'a')%mod))%mod;
		cur=cur*mut%mod;
	}
}
lli substr(int loc, lli s, lli l){
	return fix(hashs[loc][s+l]-hashs[loc][s])*inv[s]%mod;
}
lli substr(int loc, lli s){
	return fix(hashs[loc][sz(a)]-hashs[loc][s])*inv[s]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	sc(a,b);
	if(a==b){
		prl("aliens");
		return 0;
	}
	lli cur=1;
	rep(i,0,1001){
		inv[i]=fastpow(cur,mod-2);
		cur=cur*mut%mod;
	}
	hh();
	string ate=a,bte=b;
	sort(ate.begin(),ate.end());
	sort(bte.begin(),bte.end());
	if(ate!=bte){
		prl("no aliens");
		return 0;
	}
	set<lli> th;
	rep(i,0,sz(a))rep(j,i,sz(a)){
		th.insert(substr(1,i,j-i+1));
	}
	rep(i,0,sz(a))rep(j,i,sz(a)) {
		if(th.count(substr(0,i,j-i+1))){
			cango[i].push_back(j+1);
		}
	}
	queue<pair<int,vector<int>>> q;
	q.push({0,{0}});
	//reach[0][0]=true;
	while(sz(q)){
		auto cur=q.front();
		q.pop();
		if(sz(cur.second)<=4){
			for(int x:cango[cur.first]){
				//if(!reach[x][sz(cur.second)+1]){
				//	reach[x][sz(cur.second)+1]=true;
					if(x==sz(a)){
						if(sz(cur.second)==2){
							//assert(0);
							if((substr(0,cur.second[1])+(substr(0,0,cur.second[1])*fastpow(mut,cur.second[1])%mod))%mod!=hashs[1][sz(b)])continue;
						}
						else if(sz(cur.second)==3){
							if((substr(0,0,cur.second[1])+(substr(0,cur.second[2])*fastpow(mut,cur.second[1])%mod)+(substr(0,cur.second[1],cur.second[2]-cur.second[1])*fastpow(mut,cur.second[1]+sz(a)-cur.second[2])%mod))%mod!=hashs[1][sz(b)]&&(substr(0,cur.second[1],cur.second[2]-cur.second[1])+(substr(0,0,cur.second[1])*fastpow(mut,cur.second[2]-cur.second[1])%mod)+(substr(0,cur.second[2])*fastpow(mut,cur.second[2]-cur.second[1]+cur.second[1])%mod))%mod!=hashs[1][sz(b)])continue;
						}
						else{
							if((substr(0,0,cur.second[1])+(substr(0,cur.second[2],cur.second[3]-cur.second[2])*fastpow(mut,cur.second[1])%mod)+(substr(0,cur.second[1],cur.second[2]-cur.second[1])*fastpow(mut,cur.second[1]+cur.second[3]-cur.second[2])%mod)+(substr(0,cur.second[3])*fastpow(mut,cur.second[1]+cur.second[3]-cur.second[2]+cur.second[2]-cur.second[1])%mod))%mod!=hashs[1][sz(b)])continue;
						}
						prl("aliens");
						return 0;
					}
					cur.second.push_back(x);
					q.push({x,cur.second});
					cur.second.pop_back();
				//}
			}
		}
	}
	prl("no aliens");
	return 0;
}