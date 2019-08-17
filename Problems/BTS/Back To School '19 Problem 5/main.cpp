#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int diameter[MAXN];
int par[MAXN];
int updia[MAXN];
int upinc[MAXN];
pair<int,int> maxchlen[MAXN][3];
pair<int,int> maxchdia[MAXN][2];
void dfs(int loc, int parent){
	par[loc]=parent;
	diameter[loc]=1;
	int oneside=0;
	vector<pii> ch;
	vector<pii> chdia;
	for(int x:matrix[loc]){
		if(x!=parent) {
			dfs(x, loc);
			diameter[loc] = max(diameter[loc], max(oneside+1+ + maxchlen[x][0].first+1, diameter[x]));
			oneside=max(oneside,maxchlen[x][0].first+1);
			ch.push_back({maxchlen[x][0].first+1,x});
			chdia.push_back({diameter[x],x});
		}
	}
	sort(ch.begin(),ch.end());
	for(int i=0;i<min(3,(int)ch.size());i++){
		maxchlen[loc][i]=ch[(int)ch.size()-i-1];
	}
	sort(chdia.begin(),chdia.end());
	for(int i=0;i<min(2,(int)chdia.size());i++){
		maxchdia[loc][i]=chdia[(int)chdia.size()-i-1];
	}
}
void dfs2(int loc, int parent){
	int chmax;
	if(maxchlen[parent][0].second!=loc&&maxchlen[parent][1].second!=loc){
		chmax=maxchlen[parent][0].first+maxchlen[parent][1].first;
	}
	else if(maxchlen[parent][0].second==loc){
		chmax=maxchlen[parent][2].first+maxchlen[parent][1].first;
	}
	else{
		chmax=maxchlen[parent][2].first+maxchlen[parent][0].first;
	}
	int maxincludeabove=max(upinc[parent]+(maxchlen[parent][0].second==loc?maxchlen[parent][1].first:maxchlen[parent][0].first),chmax+(parent?1:0));
	updia[loc]=max(updia[parent],max(maxincludeabove,(maxchdia[parent][0].second==loc?maxchdia[parent][1].first:maxchdia[parent][0].first)));
	upinc[loc]=max(upinc[parent],(parent?1:0)+(maxchlen[parent][0].second==loc?maxchlen[parent][1].first:maxchlen[parent][0].first))+1;
	for(int x:matrix[loc]){if(x!=parent) {
			dfs2(x, loc);
	}}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	dfs(1,0);
	dfs2(1,0);
	map<int,vector<int>> cache;
	while(q--){
		cin>>a>>b;
		if(cache.count(a)){
			if(cache[a].size()<b)printf("-1\n");
			else printf("%d\n",cache[a][cache[a].size()-b]);
			continue;
		}
		vector<int> siz;
		for(int x:matrix[a]){
			if(x!=par[a]){
				siz.push_back(diameter[x]);
			}
		}
		if(a!=1)siz.push_back(updia[a]);
		sort(siz.begin(),siz.end());
		cache[a]=(siz);
		if(siz.size()<b)printf("-1\n");
		else printf("%d\n",siz[siz.size()-b]);
	}
	return 0;
}
/*
8 1
3 1
8 2
6 1
5 3
2 3
5 4
3 7
6 1
 */