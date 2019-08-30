#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
int val[MAXN];
vector<int> matrix[MAXN];
int n,m,q;
int lca[MAXN][18];
int depth[MAXN];
int maxlca[MAXN][18];
void dfslca(int loc, int parent, int dep){
	lca[loc][0]=parent;
	maxlca[loc][0]=val[parent];
	depth[loc]=dep;
	for(int x:matrix[loc]){
		if(x!=parent){
			dfslca(x,loc,dep+1);
		}
	}
}
void makelca(){
	for(int i=1;i<18;i++){
		for(int j=1;j<=n;j++){
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
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfslca(1,0,0);
	makelca();
	while(q--){
		cin>>a>>b;
		printf("%d\n",max(querylca(a,b),val[b]));
	}
	return 0;
}