#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
lli cnt[MAXN];
void dfs(int loc, int parent){

}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, v;
	cin >> n >> v;
	int a,b;
	for(int i=1;i<=n;i++)cin>>cnt[i];
	for(int i=1;i<n;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}

	return 0;
}