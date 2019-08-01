#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int dest,dist;
	pa(int a=0, int b=0):dest(a),dist(b){}
	bool operator<(const pa& rhs)const{
		return rhs.dist<dist;
	}
};
struct edge{
	int a,b,dist,cost;
	edge(int x=0,int y=0, int c=0, int d=0):a(x),b(y),dist(c),cost(d){}
	bool operator<(const edge &rhs) const{
		return dist<rhs.dist;
	}
};
struct compartor{
	bool operator()(const int& lhs,edge& rhs)const{
		return lhs<rhs.dist;
	}
};
vector<pa> matrix[100001];
edge edges[100001];
int dista[100001];
int distb[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int x,y,c,d;
	for(int i=0;i<m;i++){
		cin>>x>>y>>c>>d;
		edges[i]=edge(x,y,c,d);
		matrix[x].push_back(pa(y,c));
	}
	for(int i=1;i<=n;i++){
		dista[i]=1e9+1;
		distb[i]=1e9+1;
	}
	priority_queue<pa> qu;
	qu.push(pa(a,0));
	dista[a]=0;
	while(!qu.empty()){
		pa cur=qu.top();
		qu.pop();
		for(pa ne:matrix[cur.dest]){
			if(dista[ne.dest]>cur.dist+ne.dist){
				dista[ne.dest]=cur.dist+ne.dist;
				qu.push(pa(ne.dest,cur.dist+ne.dist));
			}
		}
	}
	for(int i=1;i<=n;i++)matrix[i].clear();
	for(int i=0;i<m;i++){
		matrix[edges[i].b].push_back(pa(edges[i].a,edges[i].dist));
	}
	qu.push(pa(b,0));
	distb[b]=0;
	while(!qu.empty()){
		pa cur=qu.top();
		qu.pop();
		for(pa ne:matrix[cur.dest]){
			if(distb[ne.dest]>cur.dist+ne.dist){
				distb[ne.dest]=cur.dist+ne.dist;
				qu.push(pa(ne.dest,cur.dist+ne.dist));
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		edges[i].dist=dista[edges[i].a]+distb[edges[i].b]+edges[i].dist;
	}
	sort(edges,edges+m);
	for(int i=1;i<m;i++){
		edges[i].cost+=edges[i-1].cost;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>d;
		int loc=(upper_bound(edges,edges+m,d,compartor())-edges)-1;
		if(loc>=0) {
			printf("%d\n",edges[loc].cost);
		}
		else{
			printf("%d\n",0);
		}
	}
    return 0;
}