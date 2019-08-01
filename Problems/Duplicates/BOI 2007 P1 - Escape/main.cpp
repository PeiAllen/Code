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
vector<lli> matrix[530];
vector<lli> flowmatrix[530];
lli capacities[530][530];
lli parent[530];
lli MAXN=1e8;
lli tryflow(lli s, lli t){
	memset(parent,-1, sizeof(parent));
	parent[s]=-2;
	queue<path> q;
	q.push(path(s,MAXN));
	while(!q.empty()){
		path cur=q.front();
		q.pop();
		for(lli x:flowmatrix[cur.dest]){
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
	lli addedflow;
	while(addedflow=tryflow(s,t)){//try to add flow
		ans+=addedflow;
		lli cur=t;
		while(cur!=s){//reduce capacities
			lli from=parent[cur];
			capacities[from][cur]-=addedflow;
			capacities[cur][from]+=addedflow;
			cur=from;
		}
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli l,w,n;
    cin>>l>>w>>n;
	soldier pollis[n+2];
    for(lli i=1;i<=n;i++){
		cin>>pollis[i].x>>pollis[i].y;
		for(lli j=1;j<i;j++){
			if(sqrt(pow(pollis[i].x-pollis[j].x,2)+pow(pollis[i].y-pollis[j].y,2))<=200){
				matrix[i].push_back(j);
				matrix[j].push_back(i);
			}
		}
		if(pollis[i].y<=100){
			matrix[0].push_back(i);
			matrix[i].push_back(0);
		}
		if(pollis[i].y>=w-100){
			matrix[n+1].push_back(i);
			matrix[i].push_back(n+1);
		}
    }
    queue<pa> bfs;
    lli depth[n+2];
    memset(depth,-1,sizeof(depth));
    bfs.push(pa(0,0));
    depth[0]=0;
    while(!bfs.empty()){
    	pa cur=bfs.front();
    	bfs.pop();
    	for(lli x:matrix[cur.dest]){
    		if(depth[x]==-1){
    			depth[x]=cur.depth+1;
    			bfs.push(pa(x,depth[x]));
    		}
    	}
    }
    for(lli i=1;i<=n;i++){
    	for(lli x:matrix[i]){
    		if(depth[i]<=depth[x]){//what if same depth
    			if(depth[i]==depth[x]){

    			}
    			flowmatrix[i*2+1].push_back(x*2);
    			capacities[i*2+1][x*2]=MAXN;
			    flowmatrix[x*2].push_back(i*2+1);
			    capacities[x*2][i*2+1]=0;
    		}
    	}
    	flowmatrix[i*2].push_back(i*2+1);
    	capacities[i*2][i*2+1]=1;
	    flowmatrix[i*2+1].push_back(i*2);
	    capacities[i*2+1][i*2]=0;
    }
    for(lli x:matrix[0]){
	    flowmatrix[0].push_back(x*2);
	    capacities[0][x*2]=MAXN;
	    flowmatrix[x*2].push_back(0);
	    capacities[x*2][0]=0;
    }
    printf("%lli\n",maxflow(0,(n+1)*2));
    return 0;
}