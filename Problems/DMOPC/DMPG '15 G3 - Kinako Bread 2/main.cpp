#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=200001;
vector<int> matrix[MAXN];
int which[MAXN];
int subtreesize[MAXN];
bool cent[MAXN];
int can[2][2];
int dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(int x:matrix[loc])if(x!=parent&&!cent[x])subtreesize[loc]+=dfssize(x,loc);
	return subtreesize[loc];
}
int decompsubtree(int loc, int parent, int size){
	for(int x:matrix[loc]){
		if(x!=parent&&!cent[x]&&subtreesize[x]>size)return decompsubtree(x,loc,size);
	}
	return loc;
}
lli ans=0;
lli n;
map<pair<int,int>,lli> paths;
map<pair<int,int>,lli> tepaths;
void dfs(int loc, int parent, pair<int,int> path){
	if(which[loc])path.second+=1;
	else path.first+=1;
	tepaths[path]+=1;
	for(int x:matrix[loc]){
		if(x!=parent&&!cent[x])dfs(x,loc,path);
	}
}
bool fufill(pair<int,int> a) {
	return (a.first >= can[0][0] && a.first <= can[0][1] && a.second >= can[1][0] && a.second <= can[1][1]);
}
lli bit[200002];
void update(int loc, lli am){
	for(;loc<=n;loc+=loc&-loc){
		bit[loc]+=am;
	}
}
lli query(int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}
	return sum;
}
void decompfulltree(int loc){
	int next=decompsubtree(loc,-1,dfssize(loc,-1)/2);
	cent[next]=true;
	paths.clear();
	pair<int,int> cur={0,0};
	if(which[next])cur.second+=1;
	else cur.first+=1;
	if(fufill(cur))ans+=1;
	paths[cur]=1;
	for(int x:matrix[next]){
		if(!cent[x]){
			dfs(x,next,{0,0});
			auto le=paths.end();
			auto ri=paths.end();
			vector<int> clear;
			for(auto te:tepaths){
				while(le!=paths.begin()&&prev(le,1)->first.first+te.first.first>=can[0][0]){
					le.operator--();
					update(le->first.second+1,le->second);
					clear.push_back(le->first.second+1);
				}
				while(ri!=paths.begin()&&prev(ri,1)->first.first+te.first.first>can[0][1]){
					ri.operator--();
					update(ri->first.second+1, -ri->second);
				}
				ans+=(query(can[1][1]-te.first.second+1)-query(can[1][0]-te.first.second))*te.second;
			}
			for(int x:clear){
				update(x,-(query(x)-query(x-1)));
			}
			for(auto te:tepaths){
				pair<int,int> real={te.first.first+cur.first,te.first.second+cur.second};
				paths[real]+=te.second;
			}
			tepaths.clear();
		}
	}
	for(int x:matrix[next]){
		if(!cent[x]){
			decompfulltree(x);
		}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>n>>can[0][0]>>can[0][1]>>can[1][0]>>can[1][1];
	string a;
	cin>>a;
	for(int i=1;i<=n;i++){
		which[i]=(a[i-1]=='K'?0:1);
	}
	int b,c;
	for(int i=1;i<n;i++){
		cin>>b>>c;
		matrix[b].push_back(c);
		matrix[c].push_back(b);
	}
	decompfulltree(1);
	printf("%lli\n",ans);
	return 0;
}