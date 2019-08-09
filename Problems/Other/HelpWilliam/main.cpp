#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

template<typename T>
struct node{
	T val,gg; int sz; ll prior;
	node *l,*r;
	node(T v){
		val = gg = v, sz = 1;
		prior = randlong(1,1e18);
		l = r = 0;
	}
};

template<typename T>
struct ImplicitSMTreap{
	node<T> *rt;

	inline int gsz(node<T> *&n){return n?n->sz:0;}
	inline T ggcd(node<T> *&n){return n?n->gg:0;}
	inline void upd_sz(node<T> *&n){if(n)n->sz=gsz(n->l)+gsz(n->r)+1;}
	inline void upd_gcd(node<T> *&n){if(n)n->gg=__gcd(__gcd(ggcd(n->l),ggcd(n->r)),n->val);}
	inline void upd(node<T> *&n){upd_sz(n);upd_gcd(n);}

	void split(node<T> *n, node<T> *&l, node<T> *&r, int key, int add = 0){
		if(!n) return void(l = r = 0);
		int cur_key = add+gsz(n->l);
		if(key <= cur_key) split(n->l,l,n->l,key,add), r = n;
		else split(n->r,n->r,r,key,add+1+gsz(n->l)), l = n;
		upd(n);
	}
	void merge(node<T> *&n, node<T> *l, node<T> *r){
		if(!l || !r) n = l?l:r;
		else if(l->prior > r->prior) merge(l->r,l->r,r), n = l;
		else merge(r->l,l,r->l), n = r;
		upd(n);
	}
	void insert(node<T> *v, int pos){
		node<T> *t1,*t2;
		split(rt,t1,t2,pos-1);
		merge(t1,t1,v);
		merge(rt,t1,t2);
		upd(rt);
	}
	void erase(node<T> *&n, T v){
		if(!n) return;
		if(n->val == v) merge(n,n->l,n->r);
		else erase(v<n->val?n->l:n->r,v);
		upd(n);
	}
	T kth(node<T> *&n, int idx){
		if(gsz(n->l)+1 == idx) return n->val;
		else if(gsz(n->l) >= idx) return kth(n->l,idx);
		return kth(n->r,idx-gsz(n->l)-1);
	}
	T range_query(int l, int r){
		node<T> *t1,*t2,*t3;
		split(rt,t1,t2,l-1);
		split(t2,t2,t3,r-l+1);
		T ans = ggcd(t2);
		merge(rt,t1,t2);
		merge(rt,rt,t3);
		return ans;
	}
	void print(){
		for(int i=1; i<=gsz(rt); i++)
			printf("%lld ",kth(rt,i));
		printf("\n");
	}
};

struct snode{
	int l,r;
	ImplicitSMTreap<ll> s;
	snode *lft,*rgt;
	snode(int l, int r){
		this->l = l;
		this->r = r;
	}
	void update(int row, int col, ll val, int ins){
		if(l == r){
			if(ins) s.insert(new node<ll>(val),col);
			else s.erase(s.rt,val);
			return;
		}
		int mid = (l+r)/2;
		if(row <= mid){
			if(!lft) lft = new snode(l,mid);
			lft->update(row,col,val,ins);
		}else{
			if(!rgt) rgt = new snode(mid+1,r);
			rgt->update(row,col,val,ins);
		}
	}
	ll query(int rl, int rr, int cl, int cr){
		if(l == rl && r == rr) return s.range_query(cl,cr);
		int mid = (l+r)/2;
		if(rr <= mid){
			if(!lft) return 0;
			return lft->query(rl,rr,cl,cr);
		}else if(l > mid){
			if(!rgt) return 0;
			return rgt->query(rl,rr,cl,cr);
		}else{
			ll f = !lft?0:lft->query(rl,mid,cl,cr);
			ll s = !rgt?0:rgt->query(mid+1,rr,cl,cr);
			return __gcd(f,s);
		}
	}
};

map<pii,ll> m;
snode *seg;

void init(int R, int C){
	seg = new snode(1,R);
}

void update(int P, int Q, ll K){
	P++, Q++;
	if(m.count(mp(P,Q))){
		ll s = m[mp(P,Q)];
		seg->update(P,Q,s,0);
	}
	seg->update(P,Q,K,1);
	m[mp(P,Q)] = K;
}

ll calculate(int r1, int c1, int r2, int c2){
	r1++, c1++, r2++, c2++;
	return seg->query(r1,r2,c1,c2);
}

int main(){
	init(2,3);
	update(0,0,20);
	update(0,2,15);
	update(1,1,12);
	printf("%lld\n",calculate(0,0,0,2));
	printf("%lld\n",calculate(0,0,1,1));
	update(0,1,6);
	update(1,1,14);
	printf("%lld\n",calculate(0,0,0,2));
	printf("%lld\n",calculate(0,0,1,1));
}