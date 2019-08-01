#include <bits/stdc++.h>
using namespace std;
struct cyc{
	int root, index,cycleindex,size;
	cyc(int a=0, int b=0, int c=0, int d=0):root(a),cycleindex(b),index(c),size(d){}
};
struct pa{
	int dest, dist;
	pa(int a=0, int b=0):dest(a),dist(b){}
};
struct tri{
	int dest, dist, inde;
	tri(int a=0, int b=0, int c=0):dest(a),dist(b),inde(c){}
};
const int MAXN=100001;
pa gone[MAXN];
vector<int> colour[MAXN];
cyc cycle[MAXN];
vector<int> matrix[MAXN];
vector<pa> tree[MAXN];
stack<int> st;
bool root[MAXN];
bool instack[MAXN];
int cycleindex=1;
int dist[MAXN];
vector<int> eulertour;
vector<int> starteulertour;
int firsteuler[MAXN];
int firststarteuler[MAXN];
tri qu[MAXN];
int le;
int ri;
int depth[MAXN];
int sparseeuler[3*MAXN][19];
int sparsestarteuler[MAXN][17];
void dfscycle(int loc, int parent){
	if(instack[loc]){
		int ind=1;
		stack<int> te;
		while(st.top()!=loc){
			int cur=st.top();
			st.pop();
			te.push(cur);
			cycle[cur]=cyc(loc,cycleindex,ind++);
		}
		cycleindex+=1;
		root[loc]=true;
		while(te.size()){
			st.push(te.top());
			cycle[te.top()].size=ind;
			te.pop();
		}
		return;
	}
	instack[loc]=true;
	st.push(loc);
	for(int x:matrix[loc]){
		if(x!=parent&&cycle[x].root!=loc){
			dfscycle(x,loc);
		}
	}
	if(instack[loc]) {
		instack[loc] = false;
		st.pop();
	}
}
void dfs(pa x, int parent, int dep){
	dist[x.dest]=x.dist;
	depth[x.dest]=dep;
	firsteuler[x.dest]=eulertour.size();
	firststarteuler[x.dest]=starteulertour.size();
	sparseeuler[eulertour.size()][0]=x.dest;
	sparsestarteuler[starteulertour.size()][0]=x.dest;
	eulertour.push_back(x.dest);
	starteulertour.push_back(x.dest);
	for(pa i:tree[x.dest]){
		if(i.dest!=parent){
			dfs(pa(i.dest,i.dist+x.dist),x.dest,dep+1);
			sparseeuler[eulertour.size()][0]=x.dest;
			eulertour.push_back(x.dest);
		}
	}
	if(!tree[x.dest].size()){
		sparseeuler[eulertour.size()][0]=x.dest;
		eulertour.push_back(x.dest);
	}
}
int compdepth(int a, int b){
	return depth[a]<depth[b]?a:b;
}
void makesparse(){
	for(int i=1;i<19;i++){
		for(int j=0;j<=(int)eulertour.size()-(1<<i);j++){
			sparseeuler[j][i]=compdepth(sparseeuler[j][i-1],sparseeuler[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<17;i++){
		for(int j=0;j<=(int)starteulertour.size()-(1<<i);j++){
			sparsestarteuler[j][i]=compdepth(sparsestarteuler[j][i-1],sparsestarteuler[j+(1<<(i-1))][i-1]);
		}
	}
}
int solvemore(int color){
	le=0;
	ri=-1;
	memset(gone,0,sizeof(gone));
	for(int x:colour[color]){
		gone[x]=x;
		qu[++ri]=tri(x,0,x);
	}
	int mi=INT_MAX;
	int dis=INT_MAX;
	while(ri>=le){
		tri cur=qu[le++];
		if(cur.dist>dis)return mi;
		for(int i:matrix[cur.dest]){
			if(!gone[i].dest){
				qu[++ri]=tri(i,cur.dist+1,cur.inde);
				gone[i]=pa(cur.inde,cur.dist+1);
			}
			else if(gone[i].dest!=cur.inde){
				dis=cur.dist;
				mi=min(mi,gone[i].dist+cur.dist+1);
			}
		}
	}
	return mi;
}
int eulerquery(int a, int b){
	a=firsteuler[a];
	b=firsteuler[b];
	if(a>b)swap(a,b);
	int siz=floor(log2(b-a+1));
	return compdepth(sparseeuler[a][siz],sparseeuler[b-(1<<siz)+1][siz]);
}
int starteulerquery(int a, int b){
	a=firststarteuler[a];
	b=firststarteuler[b]+1;
	if(a>b)swap(a,b);
	int siz=floor(log2(b-a+1));
	return compdepth(sparsestarteuler[a][siz],sparsestarteuler[b-(1<<siz)+1][siz]);
}
int finddist(int a, int b){
	int lca=eulerquery(a,b);
	if(root[lca]){
		if(a==lca){
			return dist[a]+dist[b]-2*dist[lca];
		}
		if(b==lca){
			return dist[a]+dist[b]-2*dist[lca];
		}
		int dir1=starteulerquery(a,lca);
		int dir2=starteulerquery(b,lca);
		if(cycle[dir1].cycleindex==cycle[dir2].cycleindex&&cycle[dir1].cycleindex){
			return min(dist[a]+dist[b]-2*dist[lca],dist[a]-dist[dir1]+dist[b]-dist[dir2]+abs(cycle[dir1].index-cycle[dir2].index));
		}
		return dist[a]+dist[b]-2*dist[lca];
	}
	return dist[a]+dist[b]-2*dist[lca];
}
int solveless(int color){
	int mi=INT_MAX;
	for(int i=0;i<colour[color].size();i++){
		for(int j=i+1;j<colour[color].size();j++){
			mi=min(mi,finddist(colour[color][i],colour[color][j]));
		}
	}
	return mi;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int in;
	for(int i=1;i<=n;i++){
		cin>>in;
		colour[in].push_back(i);
	}
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfscycle(1,-1);
	for(int i=1;i<=n;i++){
		bool rot=false;
		for(int x:matrix[i]){
			if(cycle[i].cycleindex!=cycle[x].cycleindex||!cycle[i].cycleindex){
				tree[i].push_back(pa(x,1));
			}
			if(cycle[i].root==x)rot=true;
		}
		if(!rot&&cycle[i].cycleindex){
			tree[i].push_back(pa(cycle[i].root,min(cycle[i].index,cycle[i].size-cycle[i].index)));
			tree[cycle[i].root].push_back(pa(i,min(cycle[i].index,cycle[i].size-cycle[i].index)));
		}
	}
	dfs(pa(1,0),-1,1);
	makesparse();
	int block=6;
	for(int i=1;i<n;i++){
		if(colour[i].size()<=1){
			printf("-1 ");
		}
		else if(colour[i].size()>block){
			printf("%d ",solvemore(i));
		}
		else{
			printf("%d ",solveless(i));
		}
	}
	if(colour[n].size()<=1){
		printf("-1\n");
	}
	else if(colour[n].size()>block){
		printf("%d\n",solvemore(n));
	}
	else{
		printf("%d\n",solveless(n));
	}
	return 0;
}