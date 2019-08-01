#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
template <typename T = lli>
struct edge{
    int dest;
    T dist;
    edge(int a, T b):dest(a),dist(b){}
    bool operator<(const edge& rhs)const{
        return dist>rhs.dist;
    }
};
const int MAXN=200001;
vector<edge<>> matrix[MAXN];
int subtreesize[MAXN];
bool cent[MAXN];
lli partof[MAXN];
int dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(auto x:matrix[loc])if(x.dest!=parent&&!cent[x.dest])subtreesize[loc]+=dfssize(x.dest,loc);
	return subtreesize[loc];
}
int decompsubtree(int loc, int parent, int size){
	for(auto x:matrix[loc]){
		if(x.dest!=parent&&!cent[x.dest]&&subtreesize[x.dest]>size)return decompsubtree(x.dest,loc,size);
	}
	return loc;
}
int n;
lli k;
map<lli,lli> patham;
map<lli,lli> tepatham;
lli totalans=0;
lli dfs(int loc, int parent, lli dist){
	tepatham[dist]+=1;
	lli te=(patham.count(k-dist)?patham[k-dist]:0);
	for(auto x:matrix[loc]){
		if(x.dest!=parent&&!cent[x.dest]){
			te+=dfs(x.dest,loc,dist+x.dist);
		}
	}
	partof[loc]+=te;
	return te;
}
void decompfulltree(int loc){
	int next=decompsubtree(loc,-1,dfssize(loc,-1)/2);
	cent[next]=true;
	patham[0]=1;
	for(int i=0;i<matrix[next].size();i++){
		if(!cent[matrix[next][i].dest]){
			lli te=dfs(matrix[next][i].dest,next,matrix[next][i].dist);
			totalans+=te;
			partof[next]+=te;
		}
		for(auto x:tepatham){
			patham[x.first]+=x.second;
		}
		tepatham.clear();
	}
	patham.clear();
	for(int i=matrix[next].size()-1;i>=0;i--){
		if(!cent[matrix[next][i].dest]){
			dfs(matrix[next][i].dest,next,matrix[next][i].dist);
		}
		for(auto x:tepatham){
			patham[x.first]+=x.second;
		}
		tepatham.clear();
	}
	patham.clear();
	for(auto x:matrix[next]){
		if(!cent[x.dest])decompfulltree(x.dest);
	}
}
lli gcd(lli a, lli b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    int a,b;
    lli c;
    for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
    }
    decompfulltree(1);
    for(int i=1;i<=n;i++){
	    lli te=gcd(totalans,partof[i]);
	    if(te==0){
		    printf("%lli / 1\n",partof[i]);
	    }
	    else {
		    printf("%lli / %lli\n", partof[i] / te, totalans / te);
	    }
    }
    return 0;
}