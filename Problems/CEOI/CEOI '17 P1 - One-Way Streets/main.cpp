#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
vector<pii> matrix[MAXN];
int ind[MAXN];
int canto[MAXN];
pii minneed[MAXN];
vector<int> gotos[MAXN];
vector<int> dest[MAXN];
int cur=1;
int dir[MAXN];
void tarjan(int a, int from){
	ind[a]=cur++;
	minneed[a]={INT_MAX,-1};
	for(int x:gotos[a]){
		minneed[a].first=min(minneed[a].first,ind)
	}
	for(auto x:matrix[a]){
		if(x.second!=from){
			if(!ind[x.first]){
				tarjan(x.first,x.second);
			}

			if(canto[x.first]>ind[a]){
				if(minneed[x.first].first<=ind[a]){
					dir[x.second]=minneed[x.first].second;
				}
			}
		}
	}
	if(canto[a])
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,p;
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		matrix[a].push_back({b,i});
		matrix[b].push_back({a,i});
	}
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		gotos[a].push_back(b);
		dest[b].push_back(a);
	}
	return 0;
}