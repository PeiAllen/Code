#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
struct innernode{
	int data,le,ri;
	struct innernode* left;
	struct innernode* right;
	innernode(){
		data=0;
		le=0;
		ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){
		return (le+ri)/2;
	}
	void mt(int l, int r){
		le=l;
		ri=r;
		if(le!=ri){
			left= new innernode();
			right= new innernode();
			left->mt(l,mid());
			right->mt(mid()+1,r);
		}
	}
	void update(int loc, int am){
		if(le==ri){
			data+=am;
			return;
		}
		if(loc<=mid())left->update(loc,am);
		else right->update(loc,am);
		data=left->data+right->data;
	}
	int query(int l, int r){
		if(le>r||ri<l)return 0;
		if(le>=l&&ri<=r)return data;
		return left->query(l,r)+right->query(l,r);
	}
};
struct node{
	int le,ri;
	struct innernode* data;
	struct node* left;
	struct node* right;
	node(){
		data=NULL;
		le=0;
		ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){
		return (le+ri)/2;
	}
	void mt(int l, int r){
		le=l;
		ri=r;
		data= new innernode();
		data->mt(1,n);
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
		}
	}
	void update(int x,int y, int am){
		data->update(y,am);
		if(le==ri)return;
		if(x<=mid())left->update(x,y,am);
		else right->update(x,y,am);
	}
	int query(int xl,int xr,int yl, int yr){
		if(le>xr||ri<xl)return 0;
		if(le>=xl&&ri<=xr)return data->query(yl,yr);
		return left->query(xl,xr,yl,yr)+right->query(xl,xr,yl,yr);
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}