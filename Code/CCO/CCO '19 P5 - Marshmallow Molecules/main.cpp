#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct pa{
	int a,b;
	pa(int x=0, int y=0):a(x),b(y){}
	bool operator<(const pa & rhs)const{
		if(b==rhs.b)return a<rhs.a;
		return b<rhs.b;
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	set<int> smaller[n+2];
	set<int> larger[n+2];
	vector<pa> in;
	int a,b;
	bool done[n+1];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		in.push_back({a,b});
		done[a]=true;
	}
	for(int i=1;i<=n;i++){
		if(!done[i])in.push_back({i,n+1});
	}
	sort(in.begin(),in.end());
	lli ans=m;
	for(pa cur:in){
		printf("%d %d %d\ncontains:",cur.a,cur.b,smaller[cur.a].size());
		while(smaller[cur.a].size()){
			printf("%d ",*smaller[cur.a].begin());
			lli te=smaller[cur.a].size();
			for(int y:larger[*smaller[cur.a].begin()])if(y<cur.a)smaller[cur.a].insert(y);
			ans+=smaller[cur.a].size()-te;
			smaller[cur.a].erase(smaller[cur.a].begin());
		}
		printf("\n");
		larger[cur.a].insert(cur.b);
		smaller[cur.b].insert(cur.a);
	}
	printf("%lli\n",ans);
	return 0;
}