#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=100001;
vector<int> matrix[MAXN];
int val[MAXN];
int lca[MAXN][18];
int cheapest[MAXN];
int depth[MAXN];
struct seg{
	int ind, loc;
	bool st;
	seg(int a=0, int b=0,bool c=false):ind(a),loc(b),st(c){}
	bool operator<(const seg& rhs) const{
		return loc>rhs.loc;
	}
};
void dfs(int loc, int parent, int best, int dep){
	lca[loc][0]=parent;
	depth[loc]=dep;
	if(val[loc]<=val[best])best=loc;
	cheapest[loc]=best;
	for(int i:matrix[loc]){
		if(i!=parent)dfs(i,loc,best,dep+1);
	}
}
int n;
void makelca(){
	for(int i=1;i<18;i++){
		for(int j=0;j<=n;j++){
			if(lca[j][i-1]==-1)lca[j][i]=-1;
			else lca[j][i]=lca[lca[j][i-1]][i-1];
		}
	}
}
int querylca(int a, int b){
	if(depth[a]!=depth[b]){
		if(depth[a]<depth[b])swap(a,b);
		int diff=depth[a]-depth[b];
		for(int i=0;i<18;i++){
			if(diff&(1<<i)){
				a=lca[a][i];
			}
		}
	}
	if(a==b)return lca[a][0];
	for(int i=17;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    val[0]=INT_MAX;
    cin>>n;
    priority_queue<seg> qu;
    stack<int> st;
    int a,b,c;
    for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		val[i]=c;
		qu.push(seg(i,a,true));
		qu.push(seg(i,b,false));
    }
    st.push(0);
    while(!qu.empty()){
    	seg cur=qu.top();
    	qu.pop();
    	if(cur.st) {
    		matrix[cur.ind].push_back(st.top());
		    matrix[st.top()].push_back(cur.ind);
		    st.push(cur.ind);
	    }
    	else{
    		st.pop();
    	}
    }
    dfs(0,-1,0,0);
    makelca();
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
    	cin>>a>>b;
    	int lca=querylca(a,b);
    	if(lca==0)printf("-1\n");
    	else printf("%d\n",cheapest[lca]);
    }
    return 0;
}