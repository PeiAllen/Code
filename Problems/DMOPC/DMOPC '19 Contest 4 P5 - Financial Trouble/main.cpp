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
const int MAXN=3e5+1;
lli arr[MAXN];
int lastsm[MAXN];
int deq[MAXN];
int ld=MAXN;
lli sparse[MAXN][19];
int n,q;
void ms(){
	rep(i,1,19){
		for(int j=1;j<n+2-(1<<i);j++){
			sparse[j][i]=min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
		}
	}
}
lli mi(int l, int r){
	int k=log2(r-l+1);
	return min(sparse[l][k],sparse[r-(1<<k)+1][k]);
}
struct node{
	vector<pair<int,lli>> leftp;
	int le,ri;
	struct node* left, *right;
	node(){
		leftp={};
		le=0,ri=0;
		left=NULL,right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r;
		if(l!=r){
			left=new node(),right=new node();
			left->mt(l,mid()),right->mt(mid()+1,r);
			int a=0,b=0;
			while(!(a==sz(left->leftp)&&b==sz(right->leftp))){
				if((a==sz(left->leftp)?pair<int,lli>{INT_MAX,INT_MAX}:left->leftp[a])<(b==sz(right->leftp)?pair<int,lli>{INT_MAX,INT_MAX}:right->leftp[b]))leftp.push_back(left->leftp[a++]);
				else leftp.push_back(right->leftp[b++]);
			}
		}
		else leftp={{lastsm[l],arr[l]}};
	}
	int query(int l, int r,lli a){
		if(l>ri||r<le)return 0;
		if(le>=l&&ri<=r){
			int rb=(lower_bound(leftp.begin(),leftp.end(),pair<int,lli>{l,LLONG_MIN})-leftp.begin())-1;
			int lb=0;
			lli last=LLONG_MIN;
			if(rb<lb)return 0;
			while(lb!=rb){
				int mid=(lb+rb)/2+1;
				if(leftp[mid].second+a<0)lb=mid;
				else rb=mid-1;
			}
			return lb+(leftp[lb].second+a<0?1:0);
		}
		return left->query(l,r,a)+right->query(l,r,a);
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,arr[0],q);
	rep(i,1,n+1){
		sc(arr[i]);
		arr[i]+=arr[i-1];
		sparse[i][0]=arr[i];
	}
	ms();
	for(int i=n;i>=1;i--){
		while(ld<MAXN&&arr[deq[ld]]>=arr[i])lastsm[deq[ld++]]=i;
		deq[--ld]=i;
	}
	while(ld<MAXN){
		lastsm[deq[ld++]]=-1;
	}
	node tree;
	tree.mt(1,n);
	int a,b;
	while(q--){
		sc(a,b);
		prl(arr[0]+arr[b]-arr[a-1]+max((lli)0,-(mi(a,b)-arr[a-1]+arr[0])),tree.query(a,b,-arr[a-1]+arr[0]));
	}
    return 0;
}
/*
5 100 5
4 -105 3 -3 3
1 4
1 5
2 3
1 2
3 5
 */