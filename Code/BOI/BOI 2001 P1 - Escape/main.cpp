#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct soldier{
	double x,y;
	soldier(double a=0, double b=0):x(a),y(b){}
};
struct pa{
	lli dest,depth;
	pa(lli a=0, lli b=0):dest(a),depth(b){}
};
struct path{
	lli dest, flow;
	path(lli a=0, lli b=0):dest(a),flow(b){}
};
set<pair<lli,lli>> samedepth;
lli capacities[530][530];
lli parent[530];
lli l,w,n;
lli MAXN=1e8;
lli tryflow(lli s, lli t){
	memset(parent,-1, sizeof(parent));
	parent[s]=-2;
	queue<path> q;
	q.push(path(s,MAXN));
	while(!q.empty()){
		path cur=q.front();
		q.pop();
		for(lli x=0;x<=(n+1)*2;x++){
			if(parent[x]==-1&&capacities[cur.dest][x]){
				parent[x]=cur.dest;
				path next=path(x,min(cur.flow,capacities[cur.dest][x]));
				if(next.dest==t)return next.flow;
				q.push(next);
			}
		}
	}
	return 0;
}
lli maxflow(lli s,lli t){
	lli ans=0;
	while(tryflow(s,t)){//try to add flow
		ans+=1;
		//assert(addedflow>0);
		lli cur=t;
		while(cur!=s){//reduce capacities
			lli from=parent[cur];
			if(samedepth.count({min(from/2,cur/2),max(from/2,cur/2)})){
				capacities[cur][from]-=1;
				samedepth.erase({min(from/2,cur/2),max(from/2,cur/2)});
			}
			capacities[from][cur]-=1;
			capacities[cur][from]+=1;
			cur=from;
		}
//		for(auto x:ded){
//			assert(capacities[x.first][x.second]==0);
//		}
	}
	return ans;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>l>>w>>n;
	soldier pollis[n+2];
	for(lli i=1;i<=n;i++){
		cin>>pollis[i].x>>pollis[i].y;
		for(lli j=1;j<i;j++){
			if(pow(pollis[i].x-pollis[j].x,2)+pow(pollis[i].y-pollis[j].y,2)<=40000){
				if(pollis[i].y<pollis[j].y){//what if same depth
					capacities[i*2+1][j*2]=MAXN;
				}
				else if(pollis[i].y>pollis[j].y){
					capacities[j*2+1][i*2]=MAXN;
				}
				else{
					samedepth.insert({i,j});
					capacities[i*2+1][j*2]=MAXN;
					capacities[j*2+1][i*2]=MAXN;
				}
			}
		}
		capacities[i*2][i*2+1]=1;
		if(pollis[i].y<=100){
			capacities[0][i*2]=MAXN;
		}
		if(pollis[i].y>=w-100){
			capacities[i*2+1][(n+1)*2]=MAXN;
		}
	}
//	queue<pa> bfs;
//	lli depth[n+2];
//	memset(depth,-1,sizeof(depth));
//	bfs.push(pa(0,0));
//	depth[0]=0;
//	while(!bfs.empty()){
//		pa cur=bfs.front();
//		bfs.pop();
//		for(lli x:matrix[cur.dest]){
//			if(depth[x]==-1){
//				depth[x]=cur.depth+1;
//				bfs.push(pa(x,depth[x]));
//			}
//		}
//	}
	printf("%lli\n",maxflow(0,(n+1)*2));
	return 0;
}