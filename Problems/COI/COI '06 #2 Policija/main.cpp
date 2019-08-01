#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int MAXN=100001;
vector<int> matrix[MAXN];
vector<int> matrix2[MAXN];
bool inst[MAXN];
int ind[MAXN];
int low[MAXN];
stack<int> st;
int cind=0;
int partof[MAXN];
int cur=0;
int lcat[MAXN][17];
int depth[MAXN];
void tarjan(int a, int parent){
	ind[a]=++cur;
	low[a]=cur;
	st.push(a);
	inst[a]=true;
	for(int x:matrix[a]){
		if(x!=parent) {
			if (!ind[x])tarjan(x,a);
			if (inst[x]) {
				low[a] = min(low[a], low[x]);
			}
		}
	}
	if(low[a]==ind[a]){
		while(1){
			int te=st.top();
			st.pop();
			partof[te]=cind;
			inst[te]=false;
			if(te==a)break;
		}
		cind++;
	}
}
void dfsparde(int a, int parent, int dep){
	lcat[a][0]=parent;
	depth[a]=dep;
	for(int x:matrix2[a]){
		if(x!=parent)dfsparde(x,a,dep+1);
	}
}
void makelca(){
	for(int i=1;i<17;i++){
		for(int j=0;j<cind;j++){
			if(lcat[j][i-1]!=-1) {
				lcat[j][i] = lcat[lcat[j][i-1]][i-1];
			}
			else{
				lcat[j][i]=-1;
			}
		}
	}
}
int querylca(int a, int b){
	if(depth[a]!=depth[b]){
		if(depth[a]>depth[b])swap(a,b);
		int diff=depth[b]-depth[a];
		for(int i=0;i<17;i++){
			if(diff&(1<<i)){
				b=lcat[b][i];
			}
		}
	}
	if(a==b)return a;
	for(int i=16;i>=0;i--){
		if(lcat[a][i]!=lcat[b][i]){
			a=lcat[a][i];
			b=lcat[b][i];
		}
	}
	return lcat[a][0];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,e;
	cin>>n>>e;
	int a,b;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	tarjan(1,-1);
	int q;
	cin>>q;
	for(int i=1;i<=n;i++){
		for(int x:matrix[i]){
			if(partof[x]!=partof[i]){
				matrix2[partof[x]].push_back(partof[i]);
			}
		}
	}
	dfsparde(0,-1,1);
	makelca();
	int c,d,in;
	for(;q>0;q--){
		cin>>in;
		if(in==1){
			cin>>a>>b>>c>>d;
			printf("%d %d %d %d\n",partof[a],partof[b],partof[c],partof[d]);
			if(partof[c]==partof[d]||partof[a]==partof[b]){
				printf("yes\n");
				continue;
			}
			c=partof[c];
			d=partof[d];
			a=partof[a];
			b=partof[b];
			if(depth[c]<depth[d])swap(c,d);
			int lca=querylca(a,b);//assert(lca!=-1);
			if(c==lca){
				printf("yes\n");
				continue;
			}
			int al=querylca(a,c);//assert(al!=-1);
			int bl=querylca(b,c);//assert(bl!=-1);
			if((al==c||bl==c)&&(al==lca||bl==lca)){
				printf("no\n");
			}
			else{
				printf("yes\n");
			}
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}