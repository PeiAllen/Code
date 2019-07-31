#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int MAXN=50001;
int brightness[MAXN];
vector<int> matrix[MAXN];
vector<int> eulertour;
int eulerstart[MAXN];
int lca[MAXN][17];
int n;
int depth[MAXN];
int block=317;
struct query{
	int le,ri,ind;
	query(int a=0, int b=0, int c=0):le(a),ri(b),ind(c){}
	bool operator<(const query& rhs)const{
		if(eulerstart[le]/block==eulerstart[rhs.le]/block){
			return eulerstart[ri]<eulerstart[rhs.ri];
		}
		return eulerstart[le]/block<eulerstart[rhs.le]/block;
	}
};
void dfs(int loc, int parent, int dep){
	depth[loc]=dep;
	eulerstart[loc]=eulertour.size();
	lca[loc][0]=parent;
	eulertour.push_back(loc);
	for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
	eulertour.push_back(loc);
}
void makelca(){
	for(int i=1;i<=16;i++){
		for(int j=1;j<=n;j++){
			if(lca[j][i-1]!=-1)lca[j][i]=lca[lca[j][i-1]][i-1];
			else lca[j][i]=-1;
		}
	}
}
int querylca(int a, int b){
	if(depth[a]!=depth[b]){
		if(depth[a]<depth[b])swap(a,b);
		int diff=depth[a]-depth[b];
		for(int i=0;i<=16;i++){
			if(diff&(1<<i))a=lca[a][i];
		}
	}
	if(a==b)return a;
	for(int i=16;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}
bool inset[MAXN];
multiset<int> bright;
multiset<int> diffs;
void flip(int loc){
	if(inset[eulertour[loc]]){
		auto it=bright.lower_bound(brightness[eulertour[loc]]);
		auto og=it;
		bool work=true;
		if(og!=bright.begin()) {
			it--;
			diffs.erase(diffs.find((*og)-(*it)));
		}
		else work=false;
		it=og;
		it++;
		if(it!=bright.end()) {
			diffs.erase(diffs.find((*it)-(*og)));
		}
		else work=false;
		bright.erase(og);
		if(work){
			auto te=it;
			te--;
			diffs.insert((*it)-(*te));
		}
	}
	else{
		bright.insert(brightness[eulertour[loc]]);
		auto it=bright.lower_bound(brightness[eulertour[loc]]);
		auto og=it;
		bool work=true;
		if(og!=bright.begin()) {
			it--;
			diffs.insert((*og)-(*it));
		}
		else work=false;
		it=og;
		it++;
		if(it!=bright.end()) {
			diffs.insert((*it)-(*og));
		}
		else work=false;
		if(work){
			auto te=og;
			te--;
			diffs.erase(diffs.find((*it)-(*te)));
		}
	}
	inset[eulertour[loc]]=!inset[eulertour[loc]];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>brightness[i];
	}
	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfs(1,-1,0);
	makelca();
	query queries[q];
	int ans[q];
	for(int i=0;i<q;i++){
		cin>>a>>b;
		if(eulerstart[a]>eulerstart[b])swap(a,b);
		queries[i]=query(a,b,i);
	}
	sort(queries,queries+q);
	int le=-1;
	int ri=-1;
	int last=0;
	for(int i=0;i<q;i++){
		query cur=queries[i];
		if(eulerstart[last]/block!=eulerstart[cur.le]/block){
			memset(inset,false,sizeof(inset));
			bright.clear();
			diffs.clear();
			le=-1;
			ri=-1;
		}
		while(le<eulerstart[cur.le]){
			flip(++le);
		}
		while(ri<eulerstart[cur.ri]){
			flip(++ri);
		}
		while(le>eulerstart[cur.le]){
			flip(le--);
		}
		int te=querylca(cur.le,cur.ri);
		if(te!=cur.ri)flip(eulerstart[te]);
		ans[cur.ind]=*diffs.begin();
		if(te!=cur.ri)flip(eulerstart[te]);
		last=cur.le;
	}
	for(int i=0;i<q;i++)printf("%d\n",ans[i]);
	return 0;
}
/*
7 3
1 2 4 8 16 32 64
1 2
1 3
1 4
4 5
5 6
5 7
1 7
6 5
3 6
 */