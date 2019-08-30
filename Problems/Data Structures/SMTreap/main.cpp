#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
random_device rd;
struct node {
	int data, size;
	struct node *child[2];
	unsigned int priority;
	node(int a) {
		size = 1;
		data = a;
		child[0] = NULL;
		child[1] = NULL;
		priority = rd();
	}
	int gtsz(int a) { return (child[a] ? child[a]->size : 0); }
	void recalc() { size = gtsz(0) + gtsz(1) + 1; }
	void split(int key, node *&left, node *&right) {//inclusive left
		if (data <= key) {
			if (child[1])child[1]->split(key, child[1], right), left = this;
			else right = NULL, left = this;
		} else {
			if (child[0])child[0]->split(key, left, child[0]), right = this;
			else left = NULL, right = this;
		}
		recalc();
	}
	void merge(node* & toset, node* left, node * right) {
		if (!left || !right)toset = (left ? left : right);
		else if (left->priority > right->priority)merge(left->child[1], left->child[1], right), toset = left;
		else merge(right->child[0], left, right->child[0]), toset = right;
		toset->recalc();
	}
	void erase(int a, node* & toset){
		if(data==a){
			merge(toset,child[0],child[1]);
			free(this);
		}
		int ch=(data<a);
		if(child[ch])erase(a,child[ch]);
	}
	int at(int a){
		if(gtsz(0)+1==a)return data;
		if(gtsz(0)+1>a)return child[0]->at(a);
		return (child[1]?child[1]->at(a-gtsz(0)-1):INT_MAX);
	}
	int getind(int a){
		if(data==a){
			int te=(child[0]?child[0]->getind(a):INT_MIN);
			return (te<1?gtsz(0)+1:te);
		}
		if(a<data)return child[0]->getind(a);
		return (child[1]?child[1]->getind(a)+gtsz(0)+1:INT_MIN);
	}
	void print(){
		if(child[0])child[0]->print();
		printf("%d ",data);
		if(child[1])child[1]->print();
	}
};
struct SMTreap {
	node* rt;
	SMTreap(){
		rt=NULL;
	}
	void insert(int a){
		if(!rt)rt= new node(a);
		else{
			node* te= new node(a);
			rt->split(a,te->child[0],te->child[1]);
			rt=te;
		}
	}
	void erase(int a){if(rt)rt->erase(a,rt);}
	int operator[](int a){return (rt&&a>0?rt->at(a):INT_MAX);}
	int getind(int a){
		int te=(rt?rt->getind(a):INT_MIN);
		return (te<1?-1:te);
	}
	void print(){if(rt)rt->print();}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a;
	SMTreap root;
	for(int i=0;i<n;i++){
		cin>>a;
		root.insert(a);
	}
	char in;
	int last=0;
	while(m--){
		cin>>in>>a;
		a^=last;
		if(in=='I')root.insert(a);
		else if(in=='R')root.erase(a);
		else if(in=='S')printf("%d\n",last=root[a]);
		else printf("%d\n",last=root.getind(a));
	}
	root.print();
	return 0;
}