#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
vector<pii> matrix[MAXN];
int ind[MAXN];
int canto[MAXN];
bool bridge[MAXN];
bool gone[MAXN];
int dir[MAXN];
pii minneed[MAXN];
pii maxneed[MAXN];
pii edge[MAXN];
vector<int> gotos[MAXN];
vector<int> dest[MAXN];
int lastin[MAXN];
int cur=1;
void tarjan(int a, int from){
	ind[a]=cur++;
	canto[a]=ind[a];
	for(auto x:matrix[a]){
		if(x.second!=from){
			if(!ind[x.first]){
				tarjan(x.first,x.second);
				canto[a]=min(canto[a],canto[x.first]);
			}
			else canto[a]=min(canto[a],ind[x.first]);
		}
	}
	if(canto[a]>=ind[a])bridge[from]=true;
	lastin[a]=cur-1;
}
void tarjan2cnt(int a, int from){
	minneed[a]={INT_MAX,-1};
	maxneed[a]={0,-1};
	for(int x:gotos[a]){
		if(ind[x]<minneed[a].first){
			minneed[a]={ind[x],2};
		}
		if(ind[x]>maxneed[a].first){
			maxneed[a]={ind[x],2};
		}
	}
	for(int x:dest[a]){
		if(ind[x]<minneed[a].first){
			minneed[a]={ind[x],1};
		}
		if(ind[x]>maxneed[a].first){
			maxneed[a]={ind[x],1};
		}
	}
	gone[a]=true;
	for(auto x:matrix[a]){
		if(x.second!=from){
			if(!gone[x.first]){
				tarjan2cnt(x.first,x.second);
				if(minneed[x.first].first<minneed[a].first){
					minneed[a]={minneed[x.first]};
				}
				if(maxneed[x.first].first>maxneed[a].first){
					maxneed[a]={maxneed[x.first]};
				}
			}
		}
	}
	if(bridge[from]) {
		if (minneed[a].first<ind[a]){
			if(edge[from].second==a)dir[from]=minneed[a].second;
			else dir[from]=(minneed[a].second==1?2:1);
		}
		if (maxneed[a].first>lastin[a]){
			if(edge[from].second==a)dir[from]=maxneed[a].second;
			else dir[from]=(maxneed[a].second==1?2:1);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,p;
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		edge[i]={a,b};
		matrix[a].push_back({b,i});
		matrix[b].push_back({a,i});
	}
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		gotos[a].push_back(b);
		dest[b].push_back(a);
	}
	for(int i=1;i<=n;i++) {
		if(!ind[i])tarjan(i, 0);
	}
	for(int i=1;i<=n;i++) {
		if(!gone[i])tarjan2cnt(i, 0);
	}
	for(int i=1;i<=m;i++){
		if(!dir[i])printf("B");
		else if(dir[i]==1)printf("R");
		else printf("L");
	}
	return 0;
}