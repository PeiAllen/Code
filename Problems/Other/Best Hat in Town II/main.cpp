#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int cur=1;
vector<int> matrix[(int)2e5+1];
vector<int> matrix2[(int)2e5+1];
set<int> matrix2te[(int)2e5+1];
int to[(int)1e5];
int cont[(int)2e5+1];
int ind=1;
int sccind=1;
vector<int> sccsize;
int partof[(int)2e5+1];
int indof[(int)2e5+1];
int low[(int)2e5+1];
stack<int> st;
bool inst[(int)2e5+1];
int dp[(int)2e5+1];
void scc(int loc){
	indof[loc]=ind;
	low[loc]=ind++;
	inst[loc]=true;
	st.push(loc);
	for(int x:matrix[loc]){
		if(!indof[x])scc(x);
		if(inst[x])low[loc]=min(low[loc],low[x]);
	}
	if(low[loc]==indof[loc]){
		int top=st.top();
		st.pop();
		sccsize.push_back(0);
		while(1){
			partof[top]=sccind;
			inst[top]=false;
			if(cont[top])sccsize.back()+=1;
			if(top==loc)break;
			top=st.top();
			st.pop();
		}
		sccind++;
	}
}
int fun(int a){
	if(dp[a]!=-1)return dp[a];
	int best=0;
	for(int x:matrix2[a]){
		best=max(best,fun(x));
	}
	return dp[a]=best+sccsize[a];
}
struct node{
	int ind,le,ri;
	struct node* left;
	struct node* right;
	node(){
		ind=0;
		le=0;
		ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r,ind=cur++;
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
		}
		else{
			to[le]=ind;
			cont[ind]=le;
		}
	}
	void makegraph(){
		if(le!=ri){
			matrix[left->ind].push_back(ind);
			matrix[right->ind].push_back(ind);
			left->makegraph();
			right->makegraph();
		}
	}
	void addedges(int cur,int l,int r){
		if(l>ri||r<le||l>r)return;
		if(le>=l&&ri<=r){
			matrix[ind].push_back(cur);
			return;
		}
		left->addedges(cur,l,r),right->addedges(cur,l,r);
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sccsize.push_back(0);
	int n,m;
	cin>>n>>m;
	node tree;
	tree.mt(1,n);
	tree.makegraph();
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		tree.addedges(to[a],b,c);
	}
	scc(to[1]);
	for(int i=1;i<cur;i++){
		for(int x:matrix[i]){
			if(partof[i]&&partof[x]) {
				if (partof[i] != partof[x]) {
					if (!matrix2te[partof[i]].count(partof[x])) {
						matrix2[partof[i]].push_back(partof[x]);
						matrix2te[partof[i]].insert(partof[x]);
					}
				}
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",fun(partof[to[1]]));
	return 0;
}