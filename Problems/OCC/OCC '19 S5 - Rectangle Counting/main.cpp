#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
struct rec{
	lli a,b,c,d;
	bool st;
	rec(){
		a=0;
		b=0;
		c=0;
		d=0;
	}
};
struct corner{
	lli a,b,c;
	bool top;
	bool operator<(const corner& rhs) const{
		if(a==rhs.a){
			if(!rhs.top)return 0;
			else if(!top) return 1;
			return b<rhs.b;
		}
		return a<rhs.a;
	}
};
lli bit[(int)1e6+1];
void update(int loc, lli am){for(;loc<=1e6;loc+=loc&-loc)bit[loc]+=am;}
lli sum(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}
	return sum;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;
	rec rect[n];
	vector<corner> ls;
	for(int i=0;i<n;i++){
		cin>>rect[i].a>>rect[i].b>>rect[i].c>>rect[i].d;
		ls.push_back({rect[i].a,rect[i].b,rect[i].d,true});
		ls.push_back({rect[i].c,rect[i].d,rect[i].b,false});
	}
	sort(ls.begin(),ls.end());
	lli ans=n*(n-1)/2;
	lli cnt=0;
	for(int i=0;i<2*n;i++){
		if(ls[i].top){
			ans-=cnt+sum(ls[i].b)+sum(1e6)-sum(ls[i].c-1);
			update(ls[i].c,1);
		}
		else{
			update(ls[i].b,-1);
			cnt+=1;
		}
	}
	printf("%lli\n",ans);
	return 0;
}