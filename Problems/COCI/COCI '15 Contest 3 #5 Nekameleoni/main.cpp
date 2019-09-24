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
struct node{
	vector<pii> pre,suf;
	int le,ri;
	struct node* left;
	struct node* right;
	node(){
		le=0,ri=0;
		left=NULL,right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r;
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
		}
		else{
			pre.push_back({le,arr[le]});
			suf.push_back({le,arr[le]});
		}
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,m;
    sc(n,k,m);

    return 0;
}