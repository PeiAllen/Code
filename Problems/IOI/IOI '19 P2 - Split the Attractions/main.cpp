#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=100000;
int ind[MAXN];
int low[MAXN];
int curind=1;
int subtreesize[MAXN];
vector<int> matrix[MAXN];
vector<int> dfsmatrix[MAXN];
pii need[3];
int purpletree;
vector<pii> redtrees;
int which[MAXN];
int needed;
bool bad=false;
void dfstarjan(int loc, int parent){
	ind[loc]=curind;
	low[loc]=curind++;
	if(parent!=-1) {
		dfsmatrix[loc].push_back(parent);
		dfsmatrix[parent].push_back(loc);
	}
	for(int x:matrix[loc]){
		if(!ind[x]){
			dfstarjan(x,loc);
			low[loc]=min(low[loc],low[x]);
		}
		else if(x!=parent)low[loc]=min(low[loc],ind[x]);
	}
}
void findsizes(int loc, int parent, int above){
	if(low[loc]<above&&ind[loc]!=above){
		redtrees.push_back({loc,parent});
		return;
	}
	purpletree+=1;
	for(int x:dfsmatrix[loc]){
		if(x!=parent)findsizes(x,loc,above);
	}
}
void dfspurple(int loc, int parent, int toset, int above){
	if(low[loc]<above&&ind[loc]!=above)return;
	if(needed){
		which[loc]=toset;
		needed--;
		if(needed)for(int x:dfsmatrix[loc])if(x!=parent)dfspurple(x,loc,toset,above);
	}
}
void setred(int loc, int parent, int toset){
	if(needed){
		which[loc]=toset;
		needed--;
		if(needed)for(int x:dfsmatrix[loc])if(x!=parent)setred(x,loc,toset);
	}
}
void dfsred(int loc, int parent, int toset, int above){
	if(low[loc]<above&&ind[loc]!=above){
		setred(loc,parent,toset);
		return;
	}
	if(needed)for(int x:dfsmatrix[loc])if(x!=parent)dfsred(x,loc,toset,above);
}
void gendfs(int loc, int parent, int toset){
	if(which[loc])return;
	if(needed) {
		which[loc] = toset;
		needed--;
		if(needed)for (int x:dfsmatrix[loc])if (x != parent)gendfs(x, loc, toset);
	}
}
bool dfs(int loc, int parent){
	subtreesize[loc]=1;
	for(int x:dfsmatrix[loc]){
		if(x!=parent){
			bool done=dfs(x,loc);
			if(done)return done;
			else subtreesize[loc]+=subtreesize[x];
		}
	}
	if(subtreesize[loc]>=need[0].first){
		findsizes(loc,parent,ind[loc]);
		if(purpletree>need[1].first+need[2].first){
			bad=true;
			return true;
		}
		if(purpletree>=need[1].first){
			needed=need[1].first;
			dfspurple(loc,parent,need[1].second,ind[loc]);
			needed=need[0].first;
			gendfs(0,-1,need[0].second);
			return true;
		}
		if(purpletree>=need[0].first){
			needed=need[0].first;
			dfspurple(loc,parent,need[0].second,ind[loc]);
			needed=need[1].first;
			gendfs(0,-1,need[1].second);
			return true;
		}
		needed=need[0].first;
		dfspurple(loc,parent,need[0].second,ind[loc]);
		dfsred(loc,parent,need[0].second,ind[loc]);
		needed=need[1].first;
		gendfs(0,-1,need[1].second);
		return true;
	}
	return false;
}
vector<int> find_split(int n, int a, int b, int c, vector<int>p, vector<int>q) {
	need[0]={a,1};
	need[1]={b,2};
	need[2]={c,3};
	sort(need,need+3);
	for(int i=0;i<p.size();i++){
		matrix[p[i]].push_back(q[i]);
		matrix[q[i]].push_back(p[i]);
	}
	dfstarjan(0,-1);
	dfs(0,-1);
	vector<int> ans;
	for(int i=0;i<n;i++)ans.push_back(which[i]);
	if(bad)return ans;
	for(int i=0;i<n;i++){
		if(!ans[i])ans[i]=need[2].second;
	}
	return ans;
}

//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//	vector<int> p={0, 0, 0, 0, 0};
//	vector<int> q={1, 2, 3, 4, 5};
//	vector<int> ans=find_split(6, 2, 2, 2,p,q);
//	for(int x:ans)printf("%d ",x);
//    return 0;
//}