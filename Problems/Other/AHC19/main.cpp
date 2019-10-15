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
pair<lli,int> bt(pair<lli,int> a,pair<lli,int> b){
	if(a.first>b.first)return a;
	if(b.first>a.first)return b;
	if(b.second<a.second)return b;
	return a;
}
struct node{
	pair<lli,int> data;
	int le, ri;
	struct node* left;
	struct node* right;
	node(){
		data={0,0},le=0,ri=0;
		left=NULL;
		right=NULL;
	}
	node(lli t){
		data={t,0},le=0,ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void push(){
		data=bt(left->data,right->data);
	}
	void mt(int l, int r, lli t){
		le=l,ri=r;
		if(le!=ri){
			left= new node(t);
			right= new node(t);
			left->mt(le,mid(),t);
			right->mt(mid()+1,ri,t);
			push();
		}
	}
	void update(int loc, pair<lli,int> ne){
		if(le==ri){
			data=bt(data,ne);
			return;
		}
		if(loc<=mid())left->update(loc,ne);
		else right->update(loc,ne);
		push();
	}
	pair<lli,int> query(int l, int r){
		if(ri<l||le>r)return {LLONG_MIN,LLONG_MAX};
		if(le>=l&&ri<=r){
			return data;
		}
		return bt(left->query(l,r),right->query(l,r));
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	set<lli> com;
	lli arr[n+1];
	rep(i,1,n+1){
		sc(arr[i]);
		com.insert(arr[i]);
	}
	vector<lli> comparray;
	for(lli x:com){
		comparray.push_back(x);
	}
	lli ans=0;
	int loc1=0,loc2=0;
	int from[n+1][2];
	node addtree;
	addtree.data.first=-1e15;
	addtree.mt(1,sz(comparray),-1e15);
	node subtree;
	subtree.mt(1,sz(comparray),0);
	rep(i,1,n+1){
		int le=(lower_bound(comparray.begin(),comparray.end(),arr[i]-m)-comparray.begin())+1;
		int ri=(upper_bound(comparray.begin(),comparray.end(),arr[i]+m)-comparray.begin());
		pair<lli,int> bst=subtree.query(le,ri);
		from[i][0]=bst.second;
		lli te=bst.first+arr[i];
		if(bst.first+arr[i]>ans){
			ans=bst.first+arr[i];
			loc1=i;
			loc2=0;
		}
		bst=addtree.query(le,ri);
		from[i][1]=bst.second;
		if(bst.first-arr[i]>ans){
			ans=bst.first-arr[i];
			loc1=i;
			loc2=1;
		}
		int loc=(lower_bound(comparray.begin(),comparray.end(),arr[i])-comparray.begin())+1;
		addtree.update(loc,{te,i});
		subtree.update(loc,{bst.first-arr[i],i});
	}
	prl(ans);
	stack<int> st;
	while(loc1!=0){
		st.push(loc1);
		loc1=from[loc1][loc2];
		loc2=(loc2+1)%2;
	}
	while(st.size()){
		pr(st.top(),"");
		st.pop();
	}
    return 0;
}