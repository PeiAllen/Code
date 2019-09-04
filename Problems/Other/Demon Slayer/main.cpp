#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int arr[(1<<n)];
	vector<map<int,int>> layers[n+1];
	map<int,int> curlay[n+1];
	map<int,int> best[n+1];
	int in;
	layers[0].resize((1<<n));
	for(int i=0;i<(1<<n);i++){
		cin>>in;
		arr[i]=in;
		layers[0][i][in]=1;
		for(auto x:layers[0][i])curlay[0][x.first]+=1;
	}
	for(auto x:curlay[0]){
		best[0][x.second]+=1;
	}
	for(int i=1;i<=n;i++){
		layers[i].resize((1<<(n-i)));
		for(int j=0;j<(1<<(n-i));j++){
			for(auto x:layers[i-1][j*2])layers[i][j][x.first]+=x.second;
			for(auto x:layers[i-1][j*2+1])layers[i][j][x.first]+=x.second;
			for(auto x:layers[i][j])curlay[i][x.first]+=1;
		}
		for(auto x:curlay[i]){
			best[i][x.second]+=1;
		}
	}
	for(int i=0;i<=n;i++){
		if(prev(best[i].end(),1)->first==(1<<(n-i))){
			printf("%d\n",i);
			break;
		}
	}
	int a,b;
	while(q--){
		cin>>a>>b;
		int old=arr[a];
		arr[a]=b;
		for(int i=0;i<=n;i++){
			layers[i][a][old]-=1;
			if(layers[i][a][old]==0){
				best[i][curlay[i][old]]-=1;
				if(!best[i][curlay[i][old]])best[i].erase(curlay[i][old]);
				curlay[i][old]-=1;
				if(curlay[i][old])best[i][curlay[i][old]]+=1;
				else curlay[i].erase(old);
				layers[i][a].erase(old);
			}
			layers[i][a][b]+=1;
			if(layers[i][a][b]==1){
				if(curlay[i].count(b)){
					best[i][curlay[i][b]]-=1;
					if(!best[i][curlay[i][b]])best[i].erase(curlay[i][b]);
				}
				curlay[i][b]+=1;
				best[i][curlay[i][b]]+=1;
			}
			a/=2;
		}
		for(int i=0;i<=n;i++){
			if(prev(best[i].end(),1)->first==(1<<(n-i))){
				printf("%d\n",i);
				break;
			}
		}
	}
    return 0;
}