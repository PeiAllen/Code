#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
int val[MAXN];
vector<pii> matrix[MAXN];
vector<pii> mst[MAXN];
pii disjoint[MAXN];
//pii disjointgen[MAXN];
int degree[MAXN];
int n,m,q;
//int findgen(int a){
//	if(disjointgen[a].first==a)return a;
//	return findgen(disjointgen[a].first);
//}
//void unigen(int a, int b){
//	int ap=findgen(a),bp=findgen(b);
//	if(disjointgen[ap].second>disjointgen[bp].second){
//		disjointgen[bp].first=ap;
//		disjointgen[ap].second+=disjointgen[bp].second;
//	}
//	else{
//		disjointgen[ap].first=bp;
//		disjointgen[bp].second+=disjointgen[ap].second;
//	}
//}
int find(int a){
	if(disjoint[a].first==a)return a;
	return find(disjoint[a].first);
}
void uni(int a, int b){
	int ap=find(a),bp=find(b);
	if(disjoint[ap].second>disjoint[bp].second){
		disjoint[bp].first=ap;
		disjoint[ap].second+=disjoint[bp].second;
	}
	else{
		disjoint[ap].first=bp;
		disjoint[bp].second+=disjoint[ap].second;
	}
}
int lca[MAXN][18];
int depth[MAXN];
int maxlca[MAXN][18];
bool gone[MAXN];
void dfslca(int loc, int parent, int dep, int prev){
	lca[loc][0]=parent;
	gone[loc]=true;
	maxlca[loc][0]=prev;
	depth[loc]=dep;
	for(auto x:mst[loc]){
		if(x.first!=parent){
			dfslca(x.first,loc,dep+1,x.second);
		}
	}
}
void makelca(){
	for(int i=1;i<18;i++){
		for(int j=1;j<=m;j++){
			lca[j][i]=lca[lca[j][i-1]][i-1];
			maxlca[j][i]=max(maxlca[j][i-1],maxlca[lca[j][i-1]][i-1]);
		}
	}
}
int querylca(int a, int b){
	int ans=0;
	if(depth[a]!=depth[b]){
		if(depth[a]<depth[b])swap(a,b);
		int diff=depth[a]-depth[b];
		for(int i=0;i<18;i++){
			if(diff&(1<<i)){
				ans=max(ans,maxlca[a][i]);
				a=lca[a][i];
			}
		}
	}
	if(a==b)return ans;
	for(int i=17;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			ans=max(ans,max(maxlca[a][i],maxlca[b][i]));
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return max(ans,max(maxlca[a][0],maxlca[b][0]));
}
vector<int> sol;
pii query[MAXN];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
	registerGen(argc, argv, 1);
	rnd.setSeed(time(0));
    for(int cases=50;cases<51;cases++) {
    	sol.clear();
	    ofstream o("subtask2case"+to_string(cases)+".in");
	    memset(lca,0,sizeof(lca));
	    memset(depth,0,sizeof(depth));
	    memset(maxlca,0,sizeof(maxlca));
	    memset(gone,0,sizeof(gone));
	    n=100000,m=n-1,q=100000;
	   // n=rnd.next(1,100000),m=rnd.next(1,(int)min((lli)100000,min((lli)n*((lli)n-1)/(lli)2,(lli)5*(lli)n/(lli)2))),q=rnd.next(1,100000);
	    o<<n<<" "<<m<<" "<<q<<"\n";
	    for(int i=1;i<n;i++){
	    	degree[i]=0;
	   // 	disjointgen[i]={i,1};
	    	val[i]=rnd.next(1,(int)1e9);
	    	matrix[i].clear();
	    	o<<val[i]<<" ";
	    }
	 //   disjointgen[n]={n,1};
	    degree[n]=0;
	    val[n]=rnd.next(1,(int)1e9);
	    o<<val[n]<<"\n";
	    matrix[n].clear();
	    set<pii> used;
	    int a, b;
	    for(int i=1;i<=m;i++){
	    	mst[i].clear();
	    	while(1){
	    		//a=rnd.next(1,n);
	    		//b=rnd.next(1,n);
	    		a=i;
	    		b=i+1;
	    		if(a!=b&&!used.count({min(a,b),max(a,b)})&&matrix[a].size()+1<=5&&matrix[b].size()+1<=5)break;
	    		//if(findgen(a)!=findgen(b)&&matrix[a].size()+1<=5&&matrix[b].size()+1<=5)break;
	    	}
		    disjoint[i]={i,1};
	    //	unigen(a,b);
		    matrix[a].push_back({b,i});
		    matrix[b].push_back({a,i});
		    used.insert({min(a,b),max(a,b)});
	    	o<<a<<" "<<b<<"\n";
	    }
	    for(int i=0;i<q;i++){
		    while(1){
			    a=rnd.next(1,n);
			    b=rnd.next(1,n);
			    if(a!=b)break;
		    }
		    query[i]={a,b};
		    o<<a<<" "<<b<<"\n";
	    }
	    o.close();
	    ofstream o2("subtask2case"+to_string(cases)+".out");
	    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> qu;
	    for(int i=1;i<=n;i++){
		    for(int j=0;j<matrix[i].size();j++){
			    for(int k=j+1;k<matrix[i].size();k++){
				    qu.push({val[i],{matrix[i][j].second,matrix[i][k].second}});
			    }
		    }
	    }
	    while(!qu.empty()){
		    auto cur=qu.top();
		    qu.pop();
		    if(find(cur.second.first)!=find(cur.second.second)){
			    mst[cur.second.first].push_back({cur.second.second,cur.first});
			    mst[cur.second.second].push_back({cur.second.first,cur.first});
			    uni(cur.second.first,cur.second.second);
		    }
	    }
	    for(int i=1;i<=m;i++) {
		    if(!gone[i])dfslca(i, 0, 0, 0);
	    }
	    makelca();
	    for(int i=0;i<q;i++){
		    int ans=INT_MAX;
		    for(auto x:matrix[query[i].first]){
			    for(auto y:matrix[query[i].second]){
				    if(find(x.second)==find(y.second))ans=min(ans,querylca(x.second,y.second));
			    }
		    }
		    if(ans==INT_MAX)o2<<"-1\n";
		    else o2<<max(ans,val[query[i].second])<<"\n";
	    }
	    o2.close();
    }
    return 0;
}