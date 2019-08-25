#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<pii> matrix[1001];
int m,n,l;
bool gone[1001];
int memo[1001];
vector<int> uses;
int dfs(int loc){
	vector<int> te=uses;
	sort(te.begin(),te.end(),greater<int>());
	int cur=(te.size()?te[min((int)te.size()-1,l)]:0);
	if(memo[loc]!=-1){
		if(memo[loc]<=cur){
			return INT_MAX;
		}
	}
	memo[loc]=cur;
	if(loc==n){
		vector<int> te=uses;
		sort(te.begin(),te.end(),greater<int>());
		if(te.size()<=l)return 0;
		else return te[l];
	}
	if(uses.size()>n)return INT_MAX;
	gone[loc]=true;
	int ans=INT_MAX;
	for(pii x:matrix[loc]){
		if(!gone[x.first]){
			uses.push_back(x.second);
			ans=min(ans,dfs(x.first));
			uses.pop_back();
		}
	}
	gone[loc]=false;
	return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>l;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
	}
	int dist[1001];
	for(int i=1;i<=n;i++){
		dist[i]=INT_MAX;
		memo[i]={-1};
	}
	queue<int> q;
	dist[1]=0;
	q.push(1);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(pii x:matrix[cur]){
			if(dist[cur]+1<dist[x.first]){
				dist[x.first]=dist[cur]+1;
				q.push(x.first);
			}
		}
	}
	if(dist[n]<=l){
		printf("0\n");
		return 0;
	}
	if(dist[n]==INT_MAX){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",dfs(1));
	return 0;
}