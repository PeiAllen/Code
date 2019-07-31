#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
	lli prefixsum,maxprefixsum;
	int lazy,left,right;
	node(){
		prefixsum=0;
		maxprefixsum=0;
		left=0;
		right=0;
		lazy=INT_MAX;
	}
};
vector<node> store;
lli getrange(int le, int ri){
	return (ri-le+1);
}
lli mid(int le, int ri){
	return (le+ri)/2;
}
void resolvelazy(int le, int ri, int loc){
	store[loc].prefixsum=getrange(le,ri)*(lli)store[loc].lazy;
	store[loc].maxprefixsum=max((lli)0,store[loc].prefixsum);
	if(getrange(le,ri)>1) {
		if (!store[loc].left){
			store[loc].left=store.size();
			store.push_back(node());
		}
		if (!store[loc].right){
			store[loc].right=store.size();
			store.push_back(node());
		}
		store[store[loc].left].lazy=store[loc].lazy;
		store[store[loc].right].lazy=store[loc].lazy;
	}
	store[loc].lazy=INT_MAX;
}
void update(int l,int r,int am,int le, int ri, int loc){
	if(store[loc].lazy!=INT_MAX)resolvelazy(le,ri,loc);
	if(le>r||ri<l)return;
	if(le>=l&&ri<=r){
		store[loc].lazy=am;
		resolvelazy(le,ri,loc);
		return;
	}
	if(!store[loc].left){
		store[loc].left=store.size();
		store.push_back(node());
	}
	if(!store[loc].right){
		store[loc].right=store.size();
		store.push_back(node());
	}
	update(l,r,am,le,mid(le,ri),store[loc].left);
	update(l,r,am,mid(le,ri)+1,ri,store[loc].right);
	store[loc].prefixsum=store[store[loc].left].prefixsum+store[store[loc].right].prefixsum;
	store[loc].maxprefixsum=max(store[store[loc].left].maxprefixsum,store[store[loc].left].prefixsum+store[store[loc].right].maxprefixsum);
}
int query(lli h,int le, int ri, int loc){
	if(store[loc].lazy!=INT_MAX)resolvelazy(le,ri,loc);
	if(le==ri)return le;
	lli lepre;
	if(store[loc].left){
		if(store[store[loc].left].lazy!=INT_MAX)resolvelazy(le,mid(le,ri),store[loc].left);
		lepre=store[store[loc].left].prefixsum;
	}
	else lepre=0;
	lli leprema;
	if(store[loc].left){
		leprema=store[store[loc].left].maxprefixsum;
	}
	else leprema=0;
	if(leprema>h)return query(h,le,mid(le,ri),store[loc].left);
	else{
		if(store[loc].right)return query(h-lepre,mid(le,ri)+1,ri,store[loc].right);
		else return ri;
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	store.reserve(7000000);
	store.push_back(node());
	char a;
	cin>>a;
	int b,c;
	lli d;
	while(a!='E'){
		if(a=='Q'){
			cin>>b;
			int te=query(b,1,n+1,0);
			if(te==n+1&&store[0].maxprefixsum<=b)te+=1;
			printf("%d\n",te-2);
		}
		else{
			cin>>b>>c>>d;
			update(b+1,c+1,d,1,n+1,0);
		}
		cin>>a;
	}
	return 0;
}