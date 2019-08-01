#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,q;
struct pa{
	int m,b;
	pa(int x=0, int y=0):m(x),b(y){}
};
struct node{
	int m,b,lazym,lazyb;
	struct node* left;
	struct node* right;
	node(){
		m=0;
		b=0;
		lazym=0;
		lazyb=0;
		left=NULL;
		right=NULL;
	}
	void makeleft(){
		left= new node();
		left->m=m;
		left->b=b;
	}
	void makeright(){
		right= new node();
		right->m=m;
		right->b=b;
	}
	void resolvelazy(int le, int ri){
		m+=lazym;
		b+=lazyb;
		if(le!=ri){
			if(left) {
				left->lazyb += lazyb;
				left->lazym += lazym;
			}
			if(right) {
				right->lazyb += lazyb;
				right->lazym += lazym;
			}
		}
		lazym=0;
		lazyb=0;
	}
	bool rangeupdate(int l, int r,int mc, int bc, int le, int ri, int mdown,int bdown){
		if(lazym||lazyb)resolvelazy(le,ri);
		if(le>=l&&ri<=r){
			lazym=mc;
			lazyb=bc;
			resolvelazy(le,ri);
			if(((m==0&&b==0)||(m==mdown&&b==bdown))&&!left&&!right)return false;
			return true;
		}
		if((l<=(le+ri)/2)) {
			if (!left)makeleft();
			if (left){
				bool te=left->rangeupdate(l, r, mc, bc, le, (le+ri)/2,m,b);
				if(!te){
					delete(left);
					left=NULL;
				}
			}
		}
		if((r>(le+ri)/2)) {
			if (!right)makeright();
			if (right){
				bool te=right->rangeupdate(l, r, mc, bc,(le+ri)/2+1,ri,m,b);
				if(!te){
					delete(right);
					right=NULL;
				}
			}
		}
		if(((m==0&&b==0)||(m==mdown&&b==bdown))&&!left&&!right)return false;
		return true;
	}
	pa query(int loc, int le,int ri){
		if(lazym||lazyb)resolvelazy(le,ri);
		if(loc<=(le+ri)/2){
			if(left)return left->query(loc,le,(le+ri)/2);
			else return pa(m,b);
		}
		if(right)return right->query(loc,(le+ri)/2+1,ri);
		else return pa(m,b);
	}
};
node* bit[300001];
void update(int loc, int l, int r,int m, int b){
	for(;loc<=n;loc+=loc&-loc){
		if(!bit[loc])bit[loc]= new node();
		bool te=bit[loc]->rangeupdate(l,r,m,b,1,n,-100,-100);
		if(!te){
			delete(bit[loc]);
			bit[loc]=NULL;
		}
	}
}
pa query(int x,int y){
	pa ans;
	for(;x>0;x-=x&-x){
		if(bit[x]){
			pa te = bit[x]->query(y, 1, n);
			ans.m += te.m;
			ans.b += te.b;
		}
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	string a;
	cin>>a;
	set<int> zeros;
	zeros.insert(0);
	zeros.insert(n+1);
	for(int i=1;i<=n;i++){
		zeros.insert(i);
	}
	for(int i=1;i<=n;i++){
		if(a[i-1]=='1'){
			auto it=zeros.find(i);
			int left=*prev(it,1)+1;
			int right=*next(it,1)-1;
			//(Le+1,x)->(x,ri-1)
			update(left,i,right,1,0);
			update(i+1,i,right,-1,0);
			zeros.erase(i);
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>a;
		if(a=="query"){
			cin>>x>>y;
			pa te=query(x,y-1);
			printf("%d\n",te.m*i+te.b);
		}
		else{
			cin>>x;
			bool alr=true;
			if(!zeros.count(x)){
				alr=false;
				zeros.insert(x);
			}
			auto it=zeros.find(x);
			int left=*prev(it,1)+1;
			int right=*next(it,1)-1;
			//(Le,x)->(x,ri)
			if(alr){
				update(left,x,right,1,-i);
				update(x+1,x,right,-1,i);
				zeros.erase(x);
			}
			else{
				update(left,x,right,-1,i);
				update(x+1,x,right,1,-i);
			}
		}
	}
	return 0;
}
/*
want all coords
left=2
right=6
i=4
(x,y)such that
left+1<=x<=i
i<=x<=right-1
(3,4),(3,5),(4,4),(4,5)

left+1,i	left+1,right-1
i,i	        i,right-1
 */