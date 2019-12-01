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
const int MAXN=3e5+3;
vector<lli> arr2;
int maxblocksize;

struct node {
	vector<lli> arr;
	lli lazy,sum;
	int prefix;

	node(int a = 0) {
		prefix = a;
		lazy = INT_MIN;
		sum = 0;
	}

	bool operator<(const int& rhs) {
		return prefix<rhs;
	}
};
vector<node> sqr;

void resolve(int ind) {
	if (sqr[ind].lazy != INT_MIN)sqr[ind].arr.assign(sqr[ind].arr.size(), sqr[ind].lazy);
	sqr[ind].lazy = INT_MIN;
}


void recalc(int ind) {
	resolve(ind);
	sqr[ind].sum = sqr[ind].arr[0];
	for (int i = 1; i < sqr[ind].arr.size(); i++) {
		sqr[ind].sum += sqr[ind].arr[i];
	}
	lli sum = 0;
	for (int i = sqr[ind].arr.size() - 1; i >= 0; i--) {
		sum += sqr[ind].arr[i];
	}
}

void pre(int ind) {
	for (int i = ind + 1; i < sqr.size(); i++) {
		sqr[i].prefix = sqr[i - 1].prefix + sqr[i - 1].arr.size();
	}
}

void insert(lli a, int loc) {
	if (sqr.size() == 0) {
		sqr.push_back(node());
	}
	int ind = (lower_bound(sqr.begin(), sqr.end(), loc + 1) - sqr.begin()) - 1;
	resolve(ind);
	loc -= sqr[ind].prefix;
	sqr[ind].arr.insert(sqr[ind].arr.begin() + loc, a);
	if (sqr[ind].arr.size() == maxblocksize * 2) {
		sqr.insert(sqr.begin() + ind + 1, node());
		for (int i = sqr[ind].arr.size() - 1; i >= maxblocksize; i--)sqr[ind + 1].arr.push_back(sqr[ind].arr[i]);
		sqr[ind].arr.resize(maxblocksize);
		recalc(ind + 1);
	}
	recalc(ind);
	pre(ind);
}

void rangeupdate(lli a, int l, int r) {
	if (sqr.size() == 0) {
		return;
	}
	int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
	int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
	l -= 1;
	r -= 1;
	if (le == ri) {
		resolve(le);
		for (int i = l - sqr[le].prefix; i <= r - sqr[le].prefix; i++) {
			sqr[le].arr[i] = a;
		}
		recalc(le);
	} else {
		if (ri > le + 1) {
			for (int i = le + 1; i < ri; i++) {
				sqr[i].lazy = a;
				sqr[i].sum = a * sqr[i].arr.size();
			}
		}
		if (l == sqr[le].prefix) {
			sqr[le].lazy = a;
			sqr[le].sum = a * sqr[le].arr.size();
		} else {
			resolve(le);
			for (int i = l - sqr[le].prefix; i < sqr[le].arr.size(); i++) {
				sqr[le].arr[i] = a;
			}
			recalc(le);
		}
		if (r == sqr[ri].prefix + sqr[ri].arr.size()) {
			sqr[ri].lazy = a;
			sqr[ri].sum = a * sqr[ri].arr.size();
		} else {
			resolve(le);
			for (int i = 0; i <= r - sqr[ri].prefix; i++) {
				sqr[ri].arr[i] = a;
			}
			recalc(ri);
		}
	}
}

int lowerbound(lli num){
	for(auto x:sqr){
		if(x.arr.back()+x.lazy>=num){
			rep(i,0,sz(x.arr)){
				if(x.arr[i]+x.lazy>=num)return i+x.prefix;
			}
		}
	}
}
lli getsum(int l, int r) {
	if(r<l)return 0;
	if (sqr.size() == 0) {
		return 0;
	}
	int le = (lower_bound(sqr.begin(), sqr.end(), l) - sqr.begin()) - 1;
	int ri = (lower_bound(sqr.begin(), sqr.end(), r) - sqr.begin()) - 1;
	l -= 1;
	r -= 1;
	lli count = 0;
	if (le == ri) {
		resolve(le);
		for (int i = l - sqr[le].prefix; i <= r - sqr[le].prefix; i++) {
			count += sqr[le].arr[i];
		}
	} else {
		for (int i = le + 1; i < ri; i++) {
			count += sqr[i].sum;
		}
		if (l == sqr[le].prefix) {
			count += sqr[le].sum;
		} else {
			resolve(le);
			for (int i = l - sqr[le].prefix; i < sqr[le].arr.size(); i++) {
				count += sqr[le].arr[i];
			}
		}
		if (r == sqr[ri].prefix + sqr[ri].arr.size()) {
			count += sqr[ri].sum;
		} else {
			resolve(ri);
			for (int i = 0; i <= r - sqr[ri].prefix; i++) {
				count += sqr[ri].arr[i];
			}
		}
	}
	return count;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,q;
	sc(n,q);
	maxblocksize = ceil(sqrt((double) (500000)));
		lli in;
		int am=n;
		rep(i,0,n){
			sc(in);
			arr2.push_back(in);
		}
		sort(arr2.begin(),arr2.end());
		rep(i,0,n){
			insert(arr2[i], i);
		}
		lli num=0;
		while(q--){
			sc(in,num);
			if(in==1){
				insert(num, lowerbound(num));
				am+=1;
			}
			else if(in==2){
				rangeupdate(num, 0+1, am);
			}
			else if(in==3){
				lli ans=0;
				resolve(0);
				recalc(0);
				lli cur=sqr[0].arr[0]/num*num;
				if(sqr[0].arr[0]<0)cur-=num;
				lli half=num/2;
				resolve(sz(sqr)-1);
				recalc(sz(sqr)-1);
				while(cur<=sqr.back().arr.back()){
					lli lo=lowerbound(cur);
					lli mi=lowerbound(cur+half+1);
					lli hi=lowerbound(cur+num);
					ans+=getsum(lo+1,mi)-(mi-lo)*cur;
					ans+=(hi-mi)*(cur+num)-getsum(mi+1,hi);
					cur+=num;
				}
				prl(ans);
			}
		}

	return 0;
}
/*
3 1
1 2 3
3 2
 */