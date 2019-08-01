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
long long ret=0;
struct innernode{
	long long data;
	struct innernode *left;
	struct innernode *right;
	innernode(){
		left=NULL;
		right=NULL;
		data=0;
	}
	void makeleft(){
		left=new innernode();
	}
	void makeright(){
		right=new innernode();
	}
	struct innernode* gcdiny(int loc, long long a, int le, int ri){
		int mid=le+(ri-le)/2;
		if(le==ri){
			data=a;
			if(data==0){
				delete(this);
				ret=0;
				return NULL;
			}
		}
		else if(loc<=mid){
			long long temp;
			if(a==0&&left==NULL){
				temp=0;
			}
			else{
				if(left==NULL){
					makeleft();
				}
				left=left->gcdiny(loc,a,le,mid);
				temp=ret;
			}
			data=gcd(temp,right==NULL?0:right->data);
		}
		else{
			long long temp;
			if(a==0&&right==NULL){
				temp=0;
			}
			else{
				if(right==NULL){
					makeright();
				}
				right=right->gcdiny(loc,a,mid+1,ri);
				temp=ret;
			}
			data=gcd(temp,left==NULL?0:left->data);
		}
		if(left==NULL&&right==NULL&&le!=ri){
			delete(this);
			ret=0;
			return NULL;
		}
		ret=data;
		return this;
	}
	long long gcday(int l,int r, int le, int ri){
		int mid=le+(ri-le)/2;
		if(l==le&&r==ri){
			return data;
		}
		if(l<=mid&&r<=mid){
			return left==NULL?0:left->gcday(l,r,le,mid);
		}
		if(l>mid&&r>mid){
			return right==NULL?0:right->gcday(l,r,mid+1,ri);
		}
		return gcd(left==NULL?0:left->gcday(l,mid,le,mid),right==NULL?0:right->gcday(mid+1,r,mid+1,ri));
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
	struct node* gcdinx(int x,int y, long long a, int le, int ri){
		int mid=le+(ri-le)/2;
		if(le==ri){
			ret=a;
			if(ret==0&&seg==NULL){
				delete(this);
				return NULL;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,a,1,cool);
			if(seg==NULL){
				delete(this);
				ret=0;
				return NULL;
			}
		}
		else if(x<=mid){
			if(a==0&&left==NULL){
				ret=gcd(0,right==NULL?0:right->seg->gcday(y,y,1,cool));
			}
			else{
				if(left==NULL){
					makeleft();
				}
				left=left->gcdinx(x,y,a,le,mid);
				ret=gcd(ret,right==NULL?0:right->seg->gcday(y,y,1,cool));
			}
			if(ret==0&&seg==NULL){
				delete(this);
				return NULL;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,ret,1,cool);
		}
		else{
			if(a==0&&right==NULL){
				ret=gcd(0,left==NULL?0:left->seg->gcday(y,y,1,cool));
			}
			else{
				if(right==NULL){
					makeright();
				}
				right=right->gcdinx(x,y,a,mid+1,ri);
				ret=gcd(ret,left==NULL?0:left->seg->gcday(y,y,1,cool));
			}
			if(ret==0&&seg==NULL){
				delete(this);
				return NULL;
			}
			if(seg==NULL){
				makeseg();
			}
			seg=seg->gcdiny(y,ret,1,cool);
		}
		if(left==NULL&&right==NULL&&le!=ri){
			delete(this);
			ret=0;
			return NULL;
		}
		return this;
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
	reee=R;
	cool=C;
}
void update(int P, int Q, long long K){
	if(!game){
		game=new node();
	}
	game=game->gcdinx(P+1,Q+1,K,1,reee);
}
long long calculate(int P, int Q, int U, int V){
	if(!game){
		game=new node();
	}
	return game->gcdax(P+1,Q+1,U+1,V+1,1,reee);
}
int main(){
	init(2, 3);
	update(0, 0, 0);
	update(0, 0, 20);
	update(1, 1, 12);
	printf("%d\n",calculate(0, 0, 0, 2));
	printf("%d\n",calculate(0, 0, 1, 1));
	update(0, 1, 6);
	update(1, 1, 14);
	printf("%d\n",calculate(0, 0, 0, 2));
	printf("%d\n",calculate(0, 0, 1, 1));
}