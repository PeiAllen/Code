#include <bits/stdc++.h>
using namespace std;
#define pb(a) push_back(a);
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
int val[MAXN];
vector<int> matrix[MAXN];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		matrix[a].pb(b);
		matrix[b].pb(a);
	}
	while(q--){
		cin>>a>>b;
		int dist[n+1];
		for(int i=1;i<=n;i++)dist[i]=INT_MAX;
		priority_queue<pii,vector<pii>,greater<pii>> q;
		dist[a]=0;
		q.push({0,a});
		while(q.size()){
			pii cur=q.top();
			q.pop();
			if(cur.second==b){
				printf("%d\n",cur.first);
				break;
			}
			if(cur.first<=dist[cur.second]){
				for(int x:matrix[cur.second]){
					pii te={max(val[x],cur.first),x};
					if(te.first<dist[te.second]){
						dist[te.second]=te.first;
						q.push(te);
					}
				}
			}
		}
		if(dist[b]==INT_MAX)printf("-1\n");
	}
	return 0;
}