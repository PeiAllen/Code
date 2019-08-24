#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
vector<int> matrix[100001];
bool can[100001];
void dfs(int loc){
	for(int x:matrix[loc]){
		if(!can[x]){
			can[x]=true;
			dfs(x);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		matrix[b].push_back(a);
	}
	dfs(1);
	if(matrix[1].empty())can[1]=true;
	for(int i=1;i<=n;i++)printf("%d",can[i]);
	return 0;
}