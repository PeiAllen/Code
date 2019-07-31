#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli m;
lli fp(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
	}
	return ans;
}
struct node{
	lli data,am;
	int le,ri;
	struct node* left;
	struct node* right;
	node(lli a=1, lli b=0):data(a),am(b){}
	void mt(int l, int r){
		le=l;
		ri=r;
		if(l!=r){
			int mid=(le+ri)/2;
			left= new node();
			right= new node();
			left->mt(l,mid);
			right->mt(mid+1,r);
		}
	}
	void prodin(int loc, lli in){
		if(le==ri){
			am+=in;
			data=fp(le,am);
			return;
		}
		if(loc<=(le+ri)/2)left->prodin(loc,in);
		else right->prodin(loc,in);
		data=(left->data*right->data)%m;
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin >> n >> m;
	node root;
	root.mt(1, n);
	for (int i = 0; i <= n; i++) {
		printf("%lli\n", root.data);
		//*(n-k+1)/k
		int tosqr = n - i;
		map<int, int> facts;
		for (int j = 2; j <= sqrt(tosqr); j++) {
			while (tosqr % j == 0) {
				facts[j] += 1;
				tosqr /= j;
			}
		}
		if(tosqr!=1)facts[tosqr]+=1;
		for (auto x:facts) {
			root.prodin(x.first, x.second);
		}
		tosqr = i + 1;
		facts.clear();
		for (int j = 2; j <= sqrt(tosqr); j++) {
			while (tosqr % j == 0) {
				facts[j] += 1;
				tosqr /= j;
			}
		}
		if(tosqr!=1)facts[tosqr]+=1;
		for (auto x:facts) {
			root.prodin(x.first, -x.second);
		}
	}
	return 0;
}
