#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int partof[50][50];
struct tri{
	int x,y,dist;
	tri(int a=0, int b=0, int c=0):x(a),y(b),dist(c){}
};
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
bool gone[50][50];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string arr[n];
	int is=1;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='X'&&!partof[i][j]){
				queue<tri> q;
				q.push(tri(i,j));
				partof[i][j]=is;
				while(!q.empty()){
					tri cur=q.front();q.pop();
					for(int i=0;i<4;i++){
						tri te={cur.x+xc[i],cur.y+yc[i]};
						if(te.x>=0&&te.x<n&&te.y>=0&&te.y<m&&arr[te.x][te.y]=='X'&&!partof[te.x][te.y]){
							q.push(te);
							partof[te.x][te.y]=is;
						}
					}
				}
				is++;
			}
		}
	}
	int ans=100000;
	int atob=100000;
	int atoc=100000;
	int btoc=100000;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='.'){
				int to[4]={100000,100000,100000,100000};
				memset(gone,false,sizeof(gone));
				queue<tri> q;
				q.push(tri(i,j,0));
				gone[i][j]=true;
				while(!q.empty()){
					tri cur=q.front();q.pop();
					if(arr[cur.x][cur.y]=='X'){
						to[partof[cur.x][cur.y]]=min(to[partof[cur.x][cur.y]],cur.dist-1);
					}
					for(int i=0;i<4;i++){
						tri te={cur.x+xc[i],cur.y+yc[i],cur.dist+1};
						if(te.x>=0&&te.x<n&&te.y>=0&&te.y<m&&!gone[te.x][te.y]){
							q.push(te);
							gone[te.x][te.y]=true;
						}
					}
				}
				ans=min(ans,to[1]+to[2]+to[3]+1);
				atob=min(atob,to[1]+to[2]+1);
				atoc=min(atoc,to[1]+to[3]+1);
				btoc=min(btoc,to[3]+to[2]+1);
			}
		}
	}
	printf("%d\n",min(ans,min(atoc+btoc,min(atob+atoc,atob+btoc))));
	return 0;
}