#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if (b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}
int reee,cool;


struct innernode {
	int index;
	long long data;
	long long gc;
	struct innernode* child[2];
	unsigned int priority;

	innernode(long long a = LLONG_MAX, int b = -1) {
		data=a, index=b, gc=a,priority=rand(), child[1] = NULL, child[0] = NULL;
	}

	void calc() {
		gc = gcd(gcd((child[0] ? child[0]->gc : 0),(child[1] ? child[1]->gc : 0)),data);
	}
	struct innernode* rotate(int a) {
		auto temp = child[a];
		child[a] = child[a]->child[!a];
		temp->child[!a] = this;
		calc();
		temp->calc();
		return temp;
	}

	struct innernode* insert(long long a,int ind, bool root = true) {
		if (root && data == LLONG_MAX) {
			data = a;
			index = ind;
			gc=data;
			priority=rand();
			return this;
		}
		if(index==ind){
			data=a;
			calc();
			return this;
		}
		int ch = (index <= ind);
		if (!child[ch]) {
			child[ch] = new innernode(a,ind);
			calc();
			if (child[ch]->priority > priority) {
				return rotate(ch);
			}
			return this;
		}
		child[ch]=child[ch]->insert(a,ind, false);
		calc();
		if (child[ch]->priority > priority) {
			return rotate(ch);
		}
		return this;
	}
	struct innernode* del(int a, bool root=true){
		if(index==a){
			if(!child[0]||!child[1]){
				int ch=(child[1]!=NULL);
				if(root&&!child[ch]){
					data=LLONG_MAX;
					gc=LLONG_MAX;
					index=0;
					return this;
				}
				free(this);
				return child[ch];
			}
			int ch=child[1]->priority>child[0]->priority;
			auto temp=rotate(ch);
			temp->child[!ch]=del(a,false);
			temp->calc();
			return temp;
		}
		int ch=(index <= a);
		if(child[ch]){
			child[ch]=child[ch]->del(a,false);
			calc();
		}
		return this;
	}
	struct innernode* gcdiny(int ind,long long data){
		if(data==0){
			return del(ind);
		}
		return insert(data,ind);
	}
	void inorder(){
		if(child[0])child[0]->inorder();
		if(data!=LLONG_MAX)printf("%d ",data);
		if(child[1])child[1]->inorder();
	}
	long long gcday(int l, int r, int left, int right){
		if(left>right||left>r||right<l){
			return 0;
		}
		if(left>l&&right<r){
			return gc;
		}
		return gcd(gcd(child[0]?child[0]->gcday(l,r,left,index-1):0,child[1]?child[1]->gcday(l,r,index+1,right):0),(index>=l&&index<=r)?data:0);
	}

};
struct node{
	struct innernode *seg;
	struct node *left;
	struct node *right;
	node(){
		left=NULL;
		right=NULL;
		seg=NULL;
	}
	void makeseg(){
		seg= new innernode();
	}
	void makeleft(){
		left=new node();
	}
	void makeright(){
		right=new node();
	}
	long long gcdinx(int x,int y, long long a, int le, int ri){
		int mid=le+(ri-le)/2;
		long long ret;
		if(le==ri){
			ret=a;
			if(ret==0&&seg==NULL){
				return 0;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,a);
		}
		else if(x<=mid){
			if(a==0&&left==NULL){
				ret=gcd(0,right==NULL||right->seg==NULL?0:right->seg->gcday(y,y,1,cool));
			}
			else{
				if(left==NULL){
					makeleft();
				}
				ret=gcd(left->gcdinx(x,y,a,le,mid),right==NULL||right->seg==NULL?0:right->seg->gcday(y,y,1,cool));
			}
			if(ret==0&&seg==NULL){
				return 0;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,ret);
		}
		else{
			if(a==0&&right==NULL){
				ret=gcd(0,left==NULL||left->seg==NULL?0:left->seg->gcday(y,y,1,cool));
			}
			else{
				if(right==NULL){
					makeright();
				}
				ret=gcd(right->gcdinx(x,y,a,mid+1,ri),left==NULL||left->seg==NULL?0:left->seg->gcday(y,y,1,cool));
			}
			if(ret==0&&seg==NULL){
				return 0;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,ret);
		}
		return ret;
	}
	long long gcdax(int l,int ly, int r,int ry, int le, int ri){
		int mid=le+(ri-le)/2;
		if(l==le&&r==ri){
			return seg==NULL?0:seg->gcday(ly,ry,1,cool);
		}
		if(l<=mid&&r<=mid){
			return left==NULL?0:left->gcdax(l,ly,r,ry,le,mid);
		}
		if(l>mid&&r>mid){
			return right==NULL?0:right->gcdax(l,ly,r,ry,mid+1,ri);
		}
		return gcd(left==NULL?0:left->gcdax(l,ly,mid,ry,le,mid),right==NULL?0:right->gcdax(mid+1,ly,r,ry,mid+1,ri));
	}
};
struct node* game;
void init(int R, int C){
	srand(time(0));
	reee=R;
	cool=C;
}
void update(int P, int Q, long long K){
	if(!game){
		game=new node();
	}
	game->gcdinx(P+1,Q+1,K,1,reee);
}
long long calculate(int P, int Q, int U, int V){
	if(!game){
		game=new node();
	}
	return game->gcdax(P+1,Q+1,U+1,V+1,1,reee);
}
int main() {
	for (int i = 0; i < 1000; i++) {
		game=NULL;
	init(2, 3);
	update(0, 0, 20);
	update(0, 2, 15);
	update(0, 2, 7);
	update(0, 2, 15);
	update(1, 1, 12);
	printf("%lli\n", calculate(0, 0, 0, 2));
	printf("%lli\n", calculate(0, 0, 1, 1));
	update(0, 1, 6);
	update(1, 1, 14);
	printf("%lli\n", calculate(0, 0, 0, 2));
	printf("%lli\n", calculate(0, 0, 1, 1));
}
}