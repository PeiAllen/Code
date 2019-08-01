#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,q;
struct pa{
	int m,b;
	pa(int x=0, int y=0):m(x),b(y){}
	void combine(pa a){
		m+=a.m;
		b+=a.b;
	}
	pa inver(){
		return pa(-m,-b);
	}
};
struct node{
	pa data,lazy;
	int lazyloc;
	struct node* left;
	struct node* right;
	node(){
		data=pa();
		lazy=pa();
		lazyloc=-1;
		left=NULL;
		right=NULL;
	}
	void resolvelazy(int le,int ri){
		data.combine(lazy);
		if(le==ri) return;
		if(lazyloc<=(le+ri)/2){
			if(!left)left=new node();
			if(left->lazyloc!=-1)left->resolvelazy(le,(le+ri)/2);
			left->lazy=lazy;
			left->lazyloc=lazyloc;
			lazy=pa();
			lazyloc=-1;
			return;
		}
		if(!right)right=new node();
		if(right->lazyloc!=-1)right->resolvelazy((le+ri)/2+1,ri);
		right->lazy=lazy;
		right->lazyloc=lazyloc;
		lazy=pa();
		lazyloc=-1;
	}
	void update(int loc, pa am, int le, int ri){
		if(lazyloc!=-1)resolvelazy(le,ri);
		lazy=am;
		lazyloc=loc;
	}
	pa query(int loc, int le, int ri){
		if(lazyloc!=-1)resolvelazy(le,ri);
		if(ri<=loc)return data;
		if(loc<=(le+ri)/2){
			if(left)return left->query(loc,le,(le+ri)/2);
			return pa();
		}
		pa leftdata=pa();
		if(left)leftdata.combine({left->data.m+left->lazy.m,left->data.b+left->lazy.b};
		if(right)leftdata.combine(right->query(loc,(le+ri)/2+1,ri));
		return leftdata;
	}
};
node* bit[300001];
void update(int loc, int l, int r,pa am){
	for(;loc<=n;loc+=loc&-loc){
		if(!bit[loc])bit[loc]= new node();
		bit[loc]->update(l,am,1,n);
		if(r+1<=n)bit[loc]->update(r+1,am.inver(),1,n);
	}
}
pa query(int x,int y){
	pa ans;
	for(;x>0;x-=x&-x){
		if(bit[x]){
			ans.combine(bit[x]->query(y, 1, n));
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
			update(left,i,right,{1,0});
			update(i+1,i,right,{-1,0});
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
				update(left,x,right,{1,-i});
				update(x+1,x,right,{-1,i});
				zeros.erase(x);
			}
			else{
				update(left,x,right,{-1,i});
				update(x+1,x,right,{1,-i});
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