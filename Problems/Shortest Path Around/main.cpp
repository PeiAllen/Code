#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int x,y;
	pa(int a=-1, int b=-1):x(a),y(b){}
};
int xc[8]={-1,0,1,1,1,0,-1,-1};
int yc[8]={-1,-1,-1,0,1,1,1,0};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string bad;
	for(int test=0;test<5;test++){
		string arr[10];
		pa locs[2];
		for(int i=0;i<10;i++){
			cin>>arr[i];
			for(int j=0;j<10;j++){
				if(arr[i][j]=='X'){
					if(locs[0].x==-1){
						locs[0]={i,j};
					}
					else locs[1]={i,j};
				}
			}
		}
		int dist[10][10];
		memset(dist,0x3f3f3f3f,sizeof(dist));
		dist[locs[0].x][locs[0].y]=0;
		queue<pa> q;
		q.push(locs[0]);
		while(!q.empty()){
			pa cur=q.front();
			q.pop();
			if(cur.x==locs[1].x&&cur.y==locs[1].y)break;
			for(int i=0;i<8;i++){
				pa te={cur.x+xc[i],cur.y+yc[i]};
				if(te.x>=0&&te.x<10&&te.y>=0&&te.y<10){
					if(arr[te.x][te.y]!='#'){
						if(dist[te.x][te.y]>dist[cur.x][cur.y]+1){
							dist[te.x][te.y]=dist[cur.x][cur.y]+1;
							q.push(te);
						}
					}
				}
			}
		}
		printf("%d\n",dist[locs[1].x][locs[1].y]);
		cin>>bad;
	}
	return 0;
}