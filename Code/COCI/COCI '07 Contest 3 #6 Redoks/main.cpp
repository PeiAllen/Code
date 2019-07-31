#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int n,m;
int arr[250001];
struct node{
	int le,ri,data;
	int am[10]={};
	struct node* left;
	struct node* right;
	int lazy;
	node(){
		le=0;
		ri=0;
		data=0;
		left=NULL;
		right=NULL;
		lazy=false;
	}
	void pushup(){
		data=left->data+right->data;
		for(int i=0;i<=9;i++)am[i]=left->am[i]+right->am[i];
	}
	void mt(int l, int r){
		le=l;
		ri=r;
		if(le!=ri){
			left= new node();
			right= new node();
			int mid=(le+ri)/2;
			left->mt(l,mid);
			right->mt(mid+1,r);
			pushup();
		}
		else{
			am[arr[le]]=1;
			data=arr[le];
		}
	}
	void resolvelazy(){
		data=0;
		for(int i=0;i<=9;i++){
			data+=am[i]*((i+lazy)%10);
		}
		int last[10]={};
		for(int i=0;i<=9;i++)last[i]=am[i];
		for(int i=0;i<=9;i++){
			am[(i+lazy)%10]=last[i];
		}
		if(left){
			left->lazy+=lazy;
			right->lazy+=lazy;
		}
		lazy=0;
	}
	void rangeupdate(int l, int r){
		if(lazy)resolvelazy();
		if(le>r||ri<l||l>r)return;
		if(le>=l&&ri<=r){
			lazy=1;
			resolvelazy();
			return;
		}
		left->rangeupdate(l,r);
		right->rangeupdate(l,r);
		pushup();
	}
	int query(int l, int r){
		if(lazy)resolvelazy();
		if(le>r||ri<l||l>r)return 0;
		if(le>=l&&ri<=r){
			return data;
		}
		return left->query(l,r)+right->query(l,r);
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	char in;
	for(int i=1;i<=n;i++){
		cin>>in;
		arr[i]=in-'0';
	}
	node rt;
	rt.mt(1,n);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		printf("%d\n",rt.query(a,b));
		rt.rangeupdate(a,b);
	}
	return 0;
}