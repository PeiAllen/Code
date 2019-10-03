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
const int MAXM=3e4+1;
const int MAXN=1e6+1;
pair<pii,int> arr[MAXN];
struct node{
	int data,lazy,le,ri;
	struct node* left;
	struct node* right;
	node(){
		data=0,lazy=0,le=0,ri=0;
		left=NULL,right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r;
		data=0;
		lazy=0;
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
		}
	}
	void re(){
		data=0;
		lazy=0;
		if(le!=ri){
			left->re(),right->re();
		}
	}
	void resolvelazy(){
		data=max(data,lazy);
		if(left) {
			left->lazy = max(left->lazy,lazy);
			right->lazy = max(right->lazy,lazy);
		}
		lazy=0;
	}
	void range(int l, int r, int cur){
		if(lazy)resolvelazy();
		if(ri<l||le>r)return;
		if(le>=l&&ri<=r){
			lazy=cur;
			resolvelazy();
			return;
		}
		left->range(l,r,cur),right->range(l,r,cur);
		data=min(left->data,right->data);
	}
	int query(int l, int r){
		if(lazy)resolvelazy();
		if(ri<l||le>r)return INT_MAX;
		if(le>=l&&ri<=r){
			return data;
		}
		return min(left->query(l,r),right->query(l,r));
	}
	void die(){
		if(left){
			left->die();
			right->die();
		}
		free(this);
	}
};
int n,m;
node* tree;
bool work(int mid){
	vector<pair<pii,int>> queries;
	rep(i,1,mid+1)queries.push_back(arr[i]);
	sort(queries.begin(),queries.end(),[&] (const pair<pii,int> &a, const pair<pii,int> &b) {
		return a.second > b.second;
	});
	tree->re();
	map<int,pii> ranges;
	for(auto x:queries){
		if(ranges.count(x.second)){
			ranges[x.second].first=max(ranges[x.second].first,x.first.first);
			ranges[x.second].second=min(ranges[x.second].second,x.first.second);
			if(ranges[x.second].first>ranges[x.second].second){
				return false;
			}
		}
		else{
			ranges[x.second]=x.first;
		}
		if(tree->query(ranges[x.second].first,ranges[x.second].second)>x.second){
			return false;
		}
		tree->range(x.first.first,x.first.second,x.second);
	}
	return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m);
    rep(i,1,m+1){
    	sc(arr[i].first.first,arr[i].first.second,arr[i].second);
    }
    tree= new node();
    tree->mt(1,n);
    int lo=1;
    int hi=m;
    while(lo!=hi){
    	int mid=(lo+hi)/2;
    	if(work(mid)){
    		lo=mid+1;
    	}
    	else hi=mid;
    }
    if(lo==m&&work(lo)){
    	prl(0);
    }
    else prl(lo);
    return 0;
}