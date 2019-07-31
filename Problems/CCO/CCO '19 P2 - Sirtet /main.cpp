#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int x,y;
	pa(int a=0, int b=0):x(a),y(b){}
};
struct path{
	int dest,dist;
	path(int a=0,int b=0):dest(a),dist(b){}
	bool operator<(const path &rhs)const{
		return rhs.dist<dist;
	}
};
vector<string> arr;
vector<vector<int>> partof;
vector< vector<path> > matrix;
int which=1;
int n,m;
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
void floodfill(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='#'&&partof[i][j]==-1){
				queue<pa> q;
				q.push(pa(i,j));
				partof[i][j]=which;
				while(!q.empty()){
					pa cur=q.front();
					q.pop();
					for(int i=0;i<4;i++){
						pa te=pa(cur.x+xc[i],cur.y+yc[i]);
						if(te.x>=0&&te.x<n&&te.y>=0&&te.y<m&&partof[te.x][te.y]==-1&&arr[te.x][te.y]=='#'){
							partof[te.x][te.y]=which;
							q.push(te);
						}
					}
				}
				which++;
			}
		}
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    string in;
    partof.resize(n);
    vector<vector<char>> ans;
    ans.resize(n);
    for(int i=0;i<n;i++){
    	cin>>in;
    	arr.push_back(in);
    	partof[i].resize(m,-1);
    	ans[i].resize(m,'.');
    }
    floodfill();
	matrix.resize(which);
    for(int i=0;i<m;i++){
    	int last=0;
    	int dist=0;
		for(int j=n-1;j>=0;j--){
			if(arr[j][i]=='#'){
				if(partof[j][i]!=last){
					matrix[last].push_back(path(partof[j][i],dist));
				}
				dist=-1;
				last=partof[j][i];
			}
			dist+=1;
		}
    }
    vector<int> dist;
    dist.resize(which,INT_MAX);
    priority_queue<path> q;
    q.push({0,0});
    dist[0]=0;
    while(!q.empty()){
    	path cur=q.top();
    	q.pop();
    	for(path x:matrix[cur.dest]){
    		if(dist[x.dest]>cur.dist+x.dist){
    			dist[x.dest]=cur.dist+x.dist;
    			q.push({x.dest,cur.dist+x.dist});
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(arr[i][j]=='#'){
    			ans[i+dist[partof[i][j]]][j]='#';
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		printf("%c",ans[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}