#include <bits/stdc++.h>
using namespace std;
random_device rd;
struct node{
	int data,amount;
	unsigned int priority;
	struct node* child[2];
	node(int a=INT_MAX, unsigned int b=rd(), int c=1){
		data=a;
		priority=b;
		amount=c;
		child[0]=NULL;
		child[1]=NULL;
	}
	void recalc(){
		amount=1+((child[0]?child[0]->amount:0)+(child[1]?child[1]->amount:0));
	}
	void split(int a,node* & left, node* & right){
		int ch=(a>=data);
		if(child[ch]) {
			child[ch]->split(a, ch?child[ch]:left,ch?right:child[ch]);//everything larger becomes right child ot viceversa
			((!ch)?right:left) = this;
			((!ch)?right:left)->recalc();
			return;
		}
		(ch?child[ch]:left)=NULL;
		(ch?right:child[ch])=NULL;
		((!ch)?right:left) = this;
		((!ch)?right:left)->recalc();
	}
	void merge(node* & ret,node* chi[]){
		if(!chi[0]||!chi[1]){
			ret=(chi[0]?chi[0]:chi[1]);
			return;
		}
		int ch=(chi[0]->priority<chi[1]->priority);
		node* temp[2]={ch?chi[!ch]:chi[ch]->child[!ch],ch?chi[ch]->child[!ch]:chi[!ch]};// combine upnode's opposite tree with opposite tree
		merge(chi[ch]->child[!ch],temp);
		ret=chi[ch];
		chi[ch]->recalc();
	}
	void insert(int a, unsigned int r, node *& ret){
		if(data==INT_MAX){
			data=a;
			priority=r;
			amount=1;
			return;
		}
		int ch=(a>=data);
		if(!child[ch]){
			child[ch]=new node(a,r);
			recalc();
			return;
		}
		if(priority<r) {
			node *te = new node(a,r);
			split(a, te->child[0], te->child[1]);
			ret=te;
			te->recalc();
			return;
		}
		child[ch]->insert(a,r,child[ch]);
		recalc();
	}
	void remove(int a, node* & ret,bool root){
		if(a==data){
			if(!child[0]&&!child[1]&&root){
				data=INT_MAX;
				priority=0;
				amount=0;
				return;
			}
			merge(ret,child);
			ret->recalc();
		}
		if(child[(a>=data)]) {
			child[(a >= data)]->remove(a, child[(a >= data)],false);
			recalc();
		}
	}

	void print(){
		if(child[0])child[0]->print();
		printf("%d ",data,amount);
		if(child[1])child[1]->print();
	}
	int lefa(){
		return (child[0]?child[0]->amount:0);
	}
	int find(int a, int smaller) {
		int lefty = child[0] == NULL ? 0 : child[0]->amount;
		if (data == a) {
			if (child[0] != NULL) {
				int temp = child[0]->find(a, smaller);
				if (temp != -1)return temp;
			}
			return lefty + smaller + 1;
		}
		int ch=data<=a;
		if (child[ch] == NULL)return -1;
		return child[ch]->find(a, smaller+(ch?lefty+1:0));
	}
	int at(int a) {
		int lefty = child[0] == NULL ? 0 : child[0]->amount;
		if (a == lefty + 1)  return data;
		int ch=a > lefty;
		if (child[ch] == NULL) return -1;
		return child[ch]->at(a-(ch?lefty+1:0));
	}
};
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* root = new node();
	int n, m;
	cin >> n>>m;
	int in;
	for (int i = 0; i < n; i++) {
		cin>>in;
		root->insert(in,rd(),root);
	}
	int last = 0;
	char c;
	for (int i = 0; i < m; i++) {
		cin>>c;
		cin>>in;
		in ^= last;
		if (c == 'I') {
			root->insert(in,rd(),root);
		} else if (c == 'R') {
			root->remove(in,root,true);
		} else if (c == 'S') {
			last = root->at(in);
			printf("%d\n", last);
		} else {
			last = root->find(in,0);
			printf("%d\n", last);
		}
	}
	root->print();
	return 0;
}