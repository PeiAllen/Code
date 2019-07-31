#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int dest;
	lli dist;
	pa(int a=0, lli b=0):dest(a),dist(b){}
	bool operator<(const pa& rhs) const{
		return dist>rhs.dist;
	}
};
vector<pa> matrix[51];
lli dist[51];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	freopen("/Users/allen/CLionProjects/Graphs as a Service/in.txt","r",stdin);
	freopen("/Users/allen/CLionProjects/Graphs as a Service/out.txt","w",stdout);
	int t;
    cin>>t;
    for(int test=1;test<=t;test++){
    	int n,m;
    	cin>>n>>m;
    	int a,b;
    	lli c;
    	for(int i=1;i<=n;i++)matrix[i].clear();
    	for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			matrix[a].push_back(pa(b,c));
			matrix[b].push_back(pa(a,c));
    	}
    	bool work=true;
    	for(int i=1;i<=n&&work;i++){
    		for(int j=1;j<=n;j++){
    			dist[j]=LLONG_MAX;
    		}
    		priority_queue<pa> q;
    		q.push(pa(i,(lli)0));
    		while(!q.empty()){
    			pa cur=q.top();
    			q.pop();
    			for(pa x:matrix[cur.dest]){
    				if(x.dist+cur.dist<dist[x.dest]){
    					dist[x.dest]=x.dist+cur.dist;
    					q.push(pa(x.dest,x.dist+cur.dist));
    				}
    			}
    		}
    		for(pa x:matrix[i]){
    			if(dist[x.dest]!=x.dist){
					work=false;
    			}
    		}
    	}
    	if(work){
			printf("Case #%d: %d\n",test,m);
			for(int i=1;i<=n;i++){
				for(pa x:matrix[i]){
					if(x.dest>i){
						printf("%d %d %lli\n",i,x.dest,x.dist);
					}
				}
			}
    	}
    	else{
    		printf("Case #%d: Impossible\n",test);
    	}
    }
    return 0;
}