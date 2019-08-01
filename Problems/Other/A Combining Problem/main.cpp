#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
	int data,le,ri,lazy;
	struct node* left;
	struct node* right;
	node(){
		data=0;
		le=0;
		ri=0;
		lazy=0;
		left=NULL;
		right=NULL;
	}
	void mt(int l,int r){
		le=l;
		ri=r;
		data=ri-le+1;
		if(le!=ri){
			left= new node();
			right = new node();
			left->mt(le,(le+ri)/2);
			right->mt((le+ri)/2+1,ri);
		}
	}
	void update(int l, int r){

	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;

    return 0;
}