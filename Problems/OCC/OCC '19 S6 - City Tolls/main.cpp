#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
int val[MAXN];
vector<pii> matrix[MAXN];
vector<pii> mst[MAXN];
pii disjoint[MAXN];
int n,m,q;
int find(int a){
	if(disjoint[a].first==a)return a;
	return find(disjoint[a].first);
}
void uni(int a, int b){
	int ap=find(a),bp=find(b);
	if(disjoint[ap].second>disjoint[bp].second){
		disjoint[bp].first=ap;
		disjoint[ap].second+=disjoint[bp].second;
	}
	else{
		disjoint[ap].first=bp;
		disjoint[bp].second+=disjoint[ap].second;
	}
}
int lca[MAXN][18];
int depth[MAXN];
int maxlca[MAXN][18];
bool gone[MAXN];
void dfslca(int loc, int parent, int dep, int prev){
	lca[loc][0]=parent;
	gone[loc]=true;
	maxlca[loc][0]=prev;
	depth[loc]=dep;
	for(auto x:mst[loc]){
		if(x.first!=parent){
			dfslca(x.first,loc,dep+1,x.second);
		}
	}
}
void makelca(){
	for(int i=1;i<18;i++){
		for(int j=1;j<=m;j++){
			lca[j][i]=lca[lca[j][i-1]][i-1];
			maxlca[j][i]=max(maxlca[j][i-1],maxlca[lca[j][i-1]][i-1]);
		}
	}
}
int querylca(int a, int b){
	int ans=0;
	if(depth[a]!=depth[b]){
		if(depth[a]<depth[b])swap(a,b);
		int diff=depth[a]-depth[b];
		for(int i=0;i<18;i++){
			if(diff&(1<<i)){
				ans=max(ans,maxlca[a][i]);
				a=lca[a][i];
			}
		}
	}
	if(a==b)return ans;
	for(int i=17;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			ans=max(ans,max(maxlca[a][i],maxlca[b][i]));
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return max(ans,max(maxlca[a][0],maxlca[b][0]));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	int a,b;
	for(int i=1;i<=m;i++){
		disjoint[i]={i,1};
		cin>>a>>b;
		matrix[a].push_back({b,i});
		matrix[b].push_back({a,i});
	}
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> qu;
	for(int i=1;i<=n;i++){
		for(int j=0;j<matrix[i].size();j++){
			for(int k=j+1;k<matrix[i].size();k++){
				qu.push({val[i],{matrix[i][j].second,matrix[i][k].second}});
			}
		}
	}
	while(!qu.empty()){
		auto cur=qu.top();
		qu.pop();
		if(find(cur.second.first)!=find(cur.second.second)){
			mst[cur.second.first].push_back({cur.second.second,cur.first});
			mst[cur.second.second].push_back({cur.second.first,cur.first});
			uni(cur.second.first,cur.second.second);
		}
	}
	for(int i=1;i<=m;i++) {
		if(!gone[i])dfslca(i, 0, 0, 0);
	}
	makelca();
	while(q--){
		cin>>a>>b;
		int ans=INT_MAX;
		for(auto x:matrix[a]){
			for(auto y:matrix[b]){
				if(find(x.second)==find(y.second))ans=min(ans,querylca(x.second,y.second));
			}
		}
		if(ans==INT_MAX)printf("-1\n");
		else printf("%d\n",max(ans,val[b]));
	}
    return 0;
}