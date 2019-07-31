#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct qu{
	int type,x,y,ind;
	lli v;
};
int n;
lli ans[(int)2e5+1];
struct node{
	lli data,lazy;
	int le, ri;
	struct node* left;
	struct node* right;
	int mid(){
		return (le+ri)/2;
	}
	void mt(int l, int r){
		le=l;
		ri=r;
		if(le!=ri){
			left=new node();
			right= new node();
			left->mt(le,mid());
			right->mt(mid()+1,ri);
		}
	}
	void rl(){
		data+=(ri-le+1)*lazy;
		if(left){
			left->lazy+=lazy;
			right->lazy+=lazy;
		}
		lazy=0;
	}
	void rangeupdate(int l, int r, lli am){
		if(lazy)rl();
		if(le>r||ri<l)return;
		if(le>=l&&ri<=r){
			lazy=am;
			rl();
			return;
		}
		left->rangeupdate(l,r,am);
		right->rangeupdate(l,r,am);
		data=left->data+right->data;
	}
	lli query(int l, int r){
		if(lazy)rl();
		if(le>r||ri<l)return 0;
		if(le>=l&&ri<=r)return data;
		return left->query(l,r)+right->query(l,r);
	}
};
node sumt;
void cdq(int left, int right,vector<qu> queries){
	int mid=(left+right)/2;
	if(left==right){
		for(qu a:queries){
			if(!a.type){
				ans[a.ind]=left;
			}
		}
		return;
	}
	vector<lli> am;
	for(qu a:queries){
		if(!a.type){
			am.push_back(sumt.query(a.x,a.y));
		}
		else if(a.v>mid){
			sumt.rangeupdate(a.x,a.y,1);
			am.push_back(0);
		}
		else{
			am.push_back(0);
		}
	}
	vector<qu> le;
	vector<qu> ri;
	bool leftcont=false;
	bool rightcont=false;
	for(int i=0;i<queries.size();i++){
		if(!queries[i].type){
			if(am[i]>=queries[i].v){
				ri.push_back(queries[i]);
				rightcont=true;
			}
			else {
				leftcont=true;
				le.push_back({queries[i].type, queries[i].x, queries[i].y,  queries[i].ind,queries[i].v - am[i]});
			}
		}
		else{
			if(queries[i].v<=mid)le.push_back(queries[i]);
			else{
				ri.push_back(queries[i]);
				sumt.rangeupdate(queries[i].x,queries[i].y,-1);
			}
		}
	}
	if(leftcont)cdq(left,mid,le);
	if(rightcont)cdq(mid+1,right,ri);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    sumt.mt(1,n);
    vector<qu> queries;
    int in;
	int m;
	cin>>m;
	int x,y;
	lli v;
	for(int i=0;i<m;i++){
		cin>>in;
		if(in==1){
			cin>>x>>y>>v;
			queries.push_back({1,x,y,0,v});
		}
		else{
			cin>>x>>y>>v;
			queries.push_back({0,x,y,i,v});
		}
	}
	cdq(1,n,queries);
	for(int i=0;i<m;i++){
		if(ans[i])printf("%lli\n",ans[i]);
	}
	return 0;
}