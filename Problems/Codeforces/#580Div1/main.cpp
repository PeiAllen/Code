#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef pair<lli, lli> pll;
vector<pll> matrix[61];
lli oth[61][61];
bool gone[61];
bool made[61][61];
lli cnt[61][61];
lli ans=LLONG_MAX;
lli bits[61];
void dfs(lli loc, lli parent, lli last,lli dist,bool mut){
	if(gone[loc]){
		if(dist==3&&ans!=3){
			for(int i=0;i<=60;i++){
				if(gone[i])printf("%d %d\n",i,bits[i]);
			}
		}
		ans=min(ans,dist);
		return;
	}
	if(dist-1>=ans)return;
	gone[loc]=true;
	if(bits[loc]>1) {
		for (pll x:matrix[loc]) {
			if(x.first!=parent) {
				if (((x.second != last || cnt[loc][x.first] >= 2) )) {
					dfs(x.first, loc, x.second==last?oth[loc][x.first]:x.second, dist + 1, x.first == parent);
				}
			}
		}
	}
	gone[loc]=false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;
	lli in;
	for(lli i=0;i<n;i++){
		cin>>in;
		vector<lli> te;
		for(lli j=0;j<61;j++){
			if(in&((lli)1<<j)){
				bits[j]+=1;
				te.push_back(j);
			}
		}
		for(lli x:te){
			printf("%d ",x);
			for(lli y:te){
				if(x!=y){
					if(!made[x][y]) {
						made[x][y] = true;
						matrix[x].push_back({y, i});
					}
					else{
						oth[x][y]=i;
					}
					cnt[x][y]+=1;
				}
			}
		}
		printf("\n");
	}
	for(lli i=0;i<61;i++){
		if(bits[i]>=3){
			printf("3\n");
			return 0;
		}
	}
	for(lli i=0;i<61;i++){
		memset(gone,0,sizeof(gone));
		dfs(i,-1,-1,0,false);
	}
	assert(ans>=2);
	if(ans==LLONG_MAX)printf("-1\n");
	else printf("%lli\n",ans);
	return 0;
}