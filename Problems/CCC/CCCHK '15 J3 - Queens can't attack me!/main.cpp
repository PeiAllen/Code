#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	bool getto[101][101]={};
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		for(int x=a,y=b;x<=n;x++){
			getto[x][y]=true;
		}
		for(int x=a,y=b;x>0;x--){
			getto[x][y]=true;
		}
		for(int x=a,y=b;y<=n;y++){
			getto[x][y]=true;
		}
		for(int x=a,y=b;y>0;y--){
			getto[x][y]=true;
		}
		for(int x=a,y=b;x<=n&&y<=n;x++,y++){
			getto[x][y]=true;
		}
		for(int x=a,y=b;x>0&&y>0;x--,y--){
			getto[x][y]=true;
		}
		for(int x=a,y=b;x<=n&&y>0;x++,y--){
			getto[x][y]=true;
		}
		for(int x=a,y=b;x>0&&y<=n;x--,y++){
			getto[x][y]=true;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!getto[i][j])cnt++;
	printf("%d\n",cnt);
	return 0;
}