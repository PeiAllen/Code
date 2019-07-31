#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
	lli prefixsum,maxprefixsum,lazy;
	struct node* left;
	struct node* right;
	int le,ri;
	node(){
		prefixsum=0;
		maxprefixsum=0;
		left=NULL;
		right=NULL;
		le=0;
		ri=0;
		lazy=LLONG_MAX;
	}
	lli getrange(){
		return (ri-le+1);
	}
	void makeleft(){
		left=new node();
		left->le=le;
		left->ri=(le+ri)/2;
		left->prefixsum=(right?prefixsum-right->prefixsum:prefixsum/getrange()*left->getrange());
		left->maxprefixsum=max((lli)0,left->prefixsum);
	}
	void makeright(){
		right=new node();
		right->le=le;
		right->ri=ri;
		left->prefixsum=(right?prefixsum-right->prefixsum:prefixsum/getrange()*left->getrange());
		left->maxprefixsum=max((lli)0,left->prefixsum);
	}
	void resolvelazy(){
		prefixsum=getrange()*lazy;
		maxprefixsum=max((lli)0,prefixsum);
		if(left)left->lazy=lazy;
		if(right)right->lazy=lazy;
		lazy=LLONG_MAX;
	}
	void update(int l,int r,lli am){
		if(lazy!=LLONG_MAX)resolvelazy();
		if(l>=ri||r<=le)return;
		if(le>=l&&ri<=r){

		}
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	return 0;
}