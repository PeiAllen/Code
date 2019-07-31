#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct qu{
	int type,x,y,v,ind;
};
int bit[(int)2e5+1];
int n;
int ans[(int)2e5+1];
void update(int loc, int am){
	for(;loc<=n;loc+=loc&-loc)bit[loc]+=am;
}
lli query(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
	return sum;
}
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
	vector<int> am;
	for(qu a:queries){//input queries and test
		if(!a.type){
			am.push_back(query(a.y)-query(a.x-1));
		}
		else if(a.y<=mid){
			update(a.x,a.v);
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
	for(int i=0;i<queries.size();i++){//does each query go left or right
		if(!queries[i].type){
			if(am[i]>=queries[i].v){
				le.push_back(queries[i]);
				leftcont=true;
			}
			else {
				rightcont=true;
				ri.push_back({queries[i].type, queries[i].x, queries[i].y, queries[i].v - am[i], queries[i].ind});
			}
		}
		else{
			if(queries[i].y<=mid){
				le.push_back(queries[i]);
				update(queries[i].x,-queries[i].v);
			}
			else ri.push_back(queries[i]);
		}
	}
	if(leftcont)cdq(left,mid,le);
	if(rightcont)cdq(mid+1,right,ri);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<qu> queries;
    int in;
    int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		queries.push_back({1,i,arr[i],1,0});
	}
	int m;
	cin>>m;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>in;
		if(in==1){
			cin>>x>>v;
			queries.push_back({1,x,arr[x],-1,0});
			arr[x]=v;
			queries.push_back({1,x,arr[x],1,0});
		}
		else{
			cin>>x>>y>>v;
			queries.push_back({0,x,y,v,i});
		}
	}
	cdq(1,1e9,queries);
	for(int i=0;i<m;i++){
		if(ans[i])printf("%d\n",ans[i]);
	}
	return 0;
}