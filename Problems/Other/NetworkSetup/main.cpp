#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<pii> matrix[1001];
struct comp{
	bool operator()(const pii& lhs, const pii&rhs)const {
		return lhs.first>rhs.first;
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,l;
	cin>>n>>m>>l;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
	}
	bool gone[n+1]={};
	queue<int> q;
	gone[1]=true;
	q.push(1);
	while(!q.size()){
		int cur=q.front();
		for(pii x:matrix[cur]){
			if(!gone[x.first]){
				gone[x.first]=true;
				q.push(x.first);
			}
		}
	}
	if(!gone[n]){
		printf("-1\n");
		return 0;
	}
	int lo=0;
	int hi=1e6;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		int dist[n+1];
		for(int i=1;i<=n;i++){
			dist[i]=INT_MAX;
		}
		priority_queue<pii,vector<pii>,comp> qu;
		dist[1]=0;
		qu.push({0,1});
		while(!qu.size()){
			pii cur=qu.top();
			if(cur.first<=dist[cur.second]){
				for(pii x:matrix[cur.second]){
					pii te={cur.first+(x.second>mid),x.first};
					if(dist[te.second]>te.first){
						dist[te.second]=te.first;
						qu.push(te);
					}
				}
			}
		}
		if(dist[n]<=l)hi=mid;
		else lo=mid+1;
	}
	printf("%d\n",lo);
	return 0;
}