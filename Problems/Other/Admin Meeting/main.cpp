#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<pii> matrix[1001];
vector<pii> revmatrix[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m,t;
	cin>>n>>m>>t;
	int a,b,w;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		matrix[a].push_back({b,w});
		revmatrix[b].push_back({a,w});
	}
	priority_queue<pii> q;
	int dist[n+1];
	int revdist[n+1];
	for(int i=0;i<=n;i++){
		dist[i]=INT_MAX;
		revdist[i]=INT_MAX;
	}
	dist[t]=0;
	q.push({0,t});
	while(!q.empty()){
		pii cur=q.top();
		q.pop();
		if(dist[cur.second]>=cur.first){
			for(pii x:matrix[cur.second]){
				pii te={x.second+cur.first,x.first};
				if(dist[te.second]>te.first){
					dist[te.second]=te.first;
					q.push(te);
				}
			}
		}
	}
	revdist[t]=0;
	q.push({0,t});
	while(!q.empty()){
		pii cur=q.top();
		q.pop();
		if(revdist[cur.second]>=cur.first){
			for(pii x:revmatrix[cur.second]){
				pii te={x.second+cur.first,x.first};
				if(revdist[te.second]>te.first){
					revdist[te.second]=te.first;
					q.push(te);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dist[i]+revdist[i]);
	}
	printf("%d\n",ans);
    return 0;
}