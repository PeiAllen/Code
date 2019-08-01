#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct tri{
	int a,b,ind;
	tri(int x=0,int y=0, int z=0):a(x),b(y),ind(z){}
};
struct back{
	int from,wh,t;
	back(int a=0, int b=0, int c=0):from(a),wh(b),t(c){}
};
vector<int> matrix[1001];
int which[1001];
bool use[1001];
back from[1001];
bool poss[1001];
int used
vector<int> fromwhich[1001][2];
tri cur;
int opp(int a){
	if(a==1)return 2;
	return 1;
}
bool dfs(int loc, int wh){
	which[loc]=wh;
	if(wh==2){
		fromwhich[cur.ind][1].push_back(loc);
		cur.b+=1;
	}
	else {
		fromwhich[cur.ind][0].push_back(loc);
		cur.a+=1;
	}
	for(int x:matrix[loc]){
		if(which[x]){
			if(which[x]==wh){
				printf("-1\n");
				return 0;
			}
		}
		else{
			if(!dfs(x,opp(wh)))return 0;
		}
	}
	return 1;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
		if(i==m-1)printf("%d %d\n",a,b);
	}
	///printf("%d\n",m);
	vector<tri> sizes;
	for(int i=1;i<=n;i++){
		if(!which[i]){
			int last=cur.ind;
			cur=tri();
			cur.ind=last+1;
			if(!dfs(i,1))return 0;
			sizes.push_back(cur);
		}
	}
	poss[0]=true;
	for(tri x:sizes){
		set<int> bad;
		for(int j=n/2;j>=x.a;j--){
			if(!poss[j]&&poss[j-x.a]){
				poss[j]=true;
				bad.insert(j);
				from[j]=back(j-x.a,x.ind,0);
			}
		}
		for(int j=n/2;j>=x.b;j--){
			if(!poss[j]&&poss[j-x.b]&&!bad.count(j-x.b)){
				poss[j]=true;
				from[j]=back(j-x.b,x.ind,1);
			}
		}
	}
	for(int i=n/2;i>=0;i--){
		if(poss[i]){
			int loc=i;
			while(loc!=0){
				for(int x:fromwhich[from[loc].wh][from[loc].t]){
					use[x]=true;
				}
				loc=from[loc].from;
			}
			if(use[1]) {
				for (int i = 1; i <= n; i++) {
					if (use[i])printf("1");
					else printf("2");
				}
			}
			else{
				for (int i = 1; i <= n; i++) {
					if (use[i])printf("2");
					else printf("1");
				}
			}
			return 0;
		}
	}
	return 0;
}