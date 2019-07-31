#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,q;
struct pa{
	int m,b;
	pa(int x=0, int y=0):m(x),b(y){}
};
struct node{
	int m,b,le,ri,lazym,lazyb;
	struct node* left;
	struct node* right;
	node(){
		m=0;
		b=0;
		le=0;
		ri=0;
		lazym=0;
		lazyb=0;
		left=NULL;
		right=NULL;
	}
	void makeleft(){
		left= new node();
		left->le=le;
		left->ri=(le+ri)/2;
		left->m=m;
		left->b=b;
	}
	void makeright(){
		right= new node();
		right->le=(le+ri)/2+1;
		right->ri=ri;
		right->m=m;
		right->b=b;
	}
	void resolvelazy(){
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
	void rangeupdate(int l, int r,int m, int b){
		if(lazym||lazyb)resolvelazy();
		if(le>=l&&ri<=r){
			lazym=m;
			lazyb=b;
			resolvelazy();
			return;
		}
		if((l<=(le+ri)/2)) {
			if (!left)makeleft();
			if (left)left->rangeupdate(l, r, m, b);
		}
		if((r>(le+ri)/2)) {
			if (!right)makeright();
			if (right)right->rangeupdate(l, r, m, b);
		}
	}
	pa query(int loc){
		if(lazym||lazyb)resolvelazy();
		if(loc<=(le+ri)/2){
			if(left)return left->query(loc);
			else return pa(m,b);
		}
		if(right)return right->query(loc);
		else return pa(m,b);
	}
};
node bit[300001];
void update(int loc, int l, int r,int m, int b){
	for(;loc<=n;loc+=loc&-loc){
		bit[loc].rangeupdate(l,r,m,b);
	}
}
pa query(int x,int y){
	pa ans;
	for(;x>0;x-=x&-x){
		pa te=bit[x].query(y);
		ans.m+=te.m;
		ans.b+=te.b;
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
	bool arr[n+1];
	for(int i=1;i<=n;i++){
		bit[i].le=1;
		bit[i].ri=n;
		if(a[i-1]=='0')zeros.insert(i);
		arr[i]=a[i-1]=='1';
	}
	update(1,1,n,1,-0+1);
	for(int i=1;i<=n;i++){
		if(a[i-1]=='0'){
			int left,right;
			auto it=zeros.lower_bound(i);
			if(it==zeros.begin())left=1;
			else {
				it--;
				left = *it;
				left+=1;
			}
			it=zeros.upper_bound(i);
			if(it==zeros.end())right=n;
			else{
				right=*it;
				right-=1;
			}//(Le,x)->(x,ri)
			update(left,i,right,-1,0-1);
			update(i+1,i,right,1,-0+1);
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
	//	printf("%dho\n",i);
		cin>>a;
		if(a=="query"){
			cin>>x>>y;
			pa te=query(x,y-1);
			printf("%d\n",te.m*(i-1)+te.b);
		}
		else{
			cin>>x;
			if(!arr[x])zeros.erase(x);
			arr[x]=!arr[x];
			int left,right;
			auto it=zeros.lower_bound(i);
			if(it==zeros.begin())left=1;
			else {
				it--;
				left = *it;
				left+=1;
				it++;
			}
			if(it==zeros.end())right=n;
			else{
				it++;
				right=*it;
				right-=1;
			}//(Le,x)->(x,ri)
			if(arr[x]){
				update(left,x,right,1,-i+1);
				update(x+1,x,right,-1,i-1);
			}
			else{
				update(left,x,right,-1,i-1);
				update(x+1,x,right,1,-i+1);
				zeros.insert(x);
			}
		}
	}
    return 0;
}