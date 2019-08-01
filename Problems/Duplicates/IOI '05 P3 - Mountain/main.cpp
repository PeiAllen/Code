#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
	int prefixsum,prefixmax,le,ri,lazy;
	struct node* left;
	struct node* right;
	int mid(){
		return (le+ri)/2;
	}
	node(){
		lazy=0;
		prefixsum=0;
		le=0;
		ri=0;
	}
	void makeleft(){
		left= new node();
		left->prefixsum=prefixsum/(ri-le+1)*(mid()-le+1);
		left->le=le;
		left->ri=mid();
	}
	void makeright(){
		right= new node();
		right->prefixsum=prefixsum/(ri-le+1)*(ri-mid());
		right->le=mid()+1;
		right->ri=ri;
	}
	void resolvelazy(){
		prefixsum
		if(left)left->lazy=lazy;
		if(right)righjt
	}
	void rangein(int l, int r, int a){


	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

    return 0;
}