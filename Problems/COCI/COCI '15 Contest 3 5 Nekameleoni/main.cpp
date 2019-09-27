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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=100001;
int n,m,k;
int arr[MAXN];
struct node{
	vector<pii> pre,suf;
	int le,ri,ans;
	struct node* left;
	struct node* right;
	node(){
		le=0,ri=0,ans=INT_MAX;
		left=NULL,right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void merge(){
		ans=min(left->ans,right->ans);
		int r=(int)right->suf.size()-1;
		bitset<51> used;
		bitset<51> noice;
		for(pii x:right->suf)noice[x.second]=true;
		for(pii x:left->suf){
			used[x.second]=true;
			noice[x.second]=true;
			while(r>=0&&used[right->pre[r].second])r--;
			if(noice.count()==k) {
				int rl = (r >= 0 ? right->pre[r].first : left->ri);
				ans = min(ans, rl - x.first + 1);
			}
		}
		used.reset();
		pre.clear();
		suf.clear();
		for(pii x:left->pre){
			used[x.second]=true;
			pre.push_back(x);
		}
		for(pii x:right->pre){
			if(!used[x.second]){
				used[x.second]=true;
				pre.push_back(x);
			}
		}
		used.reset();
		for(pii x:right->suf){
			used[x.second]=true;
			suf.push_back(x);
		}
		for(pii x:left->suf){
			if(!used[x.second]){
				used[x.second]=true;
				suf.push_back(x);
			}
		}
		if(pre.size()==k)ans=min(ans,pre.back().first-le+1);
		if(suf.size()==k)ans=min(ans,ri-suf.back().first+1);
	}
	void mt(int l, int r){
		le=l,ri=r;
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
			merge();
		}
		else{
			pre.push_back({le,arr[le]});
			suf.push_back({le,arr[le]});
			if(pre.size()==k)ans=1;
		}
	}
	void update(int loc){
		if(le>loc||ri<loc)return;
		if(le==ri){
			pre.clear();
			suf.clear();
			pre.push_back({le,arr[le]});
			suf.push_back({le,arr[le]});
			return;
		}
		left->update(loc);
		right->update(loc);
		merge();
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,k,m);
	rep(i,1,n+1)sc(arr[i]);
	int a,b,c;
	node segtree;
	segtree.mt(1,n);
	while(m--){
		sc(a);
		if(a==1){
			sc(b,c);
			arr[b]=c;
			segtree.update(b);
		}
		else prl(segtree.ans==INT_MAX?-1:segtree.ans);
	}
    return 0;
}