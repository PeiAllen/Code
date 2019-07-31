#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=100001;
vector<int> matrix[MAXN];
int depth[MAXN];
int dsum[MAXN];
vector<vector<int>> sqrttree;
int blocksize=2;
int madepth=1;
struct node{
	lli data, sumofd,nodes;
	lli lazyc, lazyd;//c*sumd-d(u)*lazyd(d(u)*c)
	int le,ri;
	struct node* left;
	struct node* right;
	node(lli a=0, lli b=0, lli c=0, lli d=-1, lli e=0):data(a),nodes(b),sumofd(c),lazyc(d),lazyd(e),le(0),ri(0),left(NULL),right(NULL){}
	bool maketree(int l, int r){
		le=l;
		ri=r;
		if(le!=ri){
			int mid=(le+ri)/2;
			left= new node();
			right= new node();
			bool a=left->maketree(l,mid);
			if(!a)left=NULL;
			a=right->maketree(mid+1,r);
			if(!a)right=NULL;
			sumofd=(left?left->sumofd:0)+(right?right->sumofd:0);
			nodes=(left?left->nodes:0)+(right?right->nodes:0);
		}
		else{
			sumofd=(lli)dsum[le]*le;
			nodes=(lli)dsum[le];
		}
		if(nodes==0){
			delete(this);
			return false;
		}
		return true;
	}
	void resolvelazy(){
		data+=lazyc*sumofd-lazyd*nodes;
		if(left){//(c+c2)*sumd-nodes(c*d(i)+c2*d(j))
			if(left->lazyc==-1)left->lazyc=0;
			left->lazyc+=lazyc;
			left->lazyd+=lazyd;
		}
		if(right) {
			if (right->lazyc == -1)right->lazyc = 0;
			right->lazyc += lazyc;
			right->lazyd += lazyd;
		}
		lazyc=-1;
		lazyd=0;
	}
	void onein(lli c, lli d, int loc){
		if(lazyc!=-1)resolvelazy();
		if(loc<le||loc>ri)return;
		if(le!=ri){
			if(left) {
				left->onein(c, d, loc);
			}
			if(right) {
				right->onein(c, d, loc);
			}
		}
		data+=c*((lli)loc-d);
	}
	void rangein(lli c,lli d,int l, int r){
		if(lazyc!=-1)resolvelazy();
		if(l>r||l>ri||r<le)return;
		if(l<=le&&r>=ri){
			lazyc=c;
			lazyd=d*c;
			resolvelazy();
			return;
		}
		if(left) {
			left->rangein(c, d, l, r);
		}
		if(right) {
			right->rangein(c, d, l, r);
		}
		data=(left?left->data:0)+(right?right->data:0);
	}
	lli sumq(int l, int r) {
		if (lazyc != -1)resolvelazy();
		if (l > r || l > ri || r < le)return 0;
		if (l <= le && r >= ri) return data;
		return (left?left->sumq(l,r):0)+(right?right->sumq(l,r):0);
	}
	lli oneq(int loc){
		if (lazyc != -1)resolvelazy();
		if(loc<le||loc>ri)return 0;
		if(le==ri){
			return data/nodes;
		}
		return (left?left->oneq(loc):0)+(right?right->oneq(loc):0);
	}
};
vector<node> sumtree;
int partof[MAXN];
vector<int> blocktree;
vector<int> blockeulerbegin;
vector<int> blockeulerend;
int eulerbegin[MAXN];
int eulerend[MAXN];
int blocktreesize=0;
int eulerloc=0;
void makesqrttree(int loc, int parent){
	eulerbegin[loc]=eulerloc++;
	for(int x:matrix[loc]){
		if(x!=parent)makesqrttree(x,loc);
		if(blocktreesize>blocksize){
			int mi=INT_MAX;
			int ma=INT_MIN;
			for(int y:blocktree){
				mi=min(mi,eulerbegin[y]);
				ma=max(ma,eulerend[y]);
				partof[y]=sqrttree.size();
			}
			blockeulerbegin.push_back(mi);
			blockeulerend.push_back(ma);
			sqrttree.push_back(blocktree);
			blocktree.clear();
			blocktreesize=0;
		}
	}
	eulerend[loc]=eulerloc++;
	blocktree.push_back(loc);
	blocktreesize+=1;
}
void declaresumtree(int ind){
	memset(dsum,0,sizeof(dsum));
	for(int x:sqrttree[ind]){
		dsum[depth[x]]+=1;
	}
	sumtree.push_back(node());
	sumtree[ind].maketree(1,madepth);
}
void update(int u, int a, int b, lli c){
	for(int i=0;i<sqrttree.size();i++){
		if(partof[u]!=i&&blockeulerbegin[i]>=eulerbegin[i]&&blockeulerend[i]<=eulerend[i]){
			sumtree[i].rangein(c,(lli)depth[u],a,b);
		}
	}
	for(int x:sqrttree[partof[u]]){
		if(eulerbegin[x]>=eulerbegin[u]&&eulerend[x]<=eulerend[u]&&a<=depth[x]&&depth[x]<=b){
			sumtree[partof[u]].onein(c,(lli)depth[u], depth[x]);
		}
	}
}
lli query(int u, int a, int b){
	lli ans=0;
	for(int i=0;i<sqrttree.size();i++){
		if(partof[u]!=i&&blockeulerbegin[i]>=eulerbegin[i]&&blockeulerend[i]<=eulerend[i]){
			ans+=sumtree[i].sumq(a,b);
		}
	}
	for(int x:sqrttree[partof[u]]){
		if(eulerbegin[x]>=eulerbegin[u]&&eulerend[x]<=eulerend[u]&&a<=depth[x]&&depth[x]<=b){
			ans+=sumtree[partof[u]].oneq(depth[x]);
		}
	}
	return ans;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int in;
	depth[0]=1;
	for(int i=1;i<n;i++){
		cin>>in;
		matrix[i].push_back(in);
		matrix[in].push_back(i);
		depth[i]=depth[in]+1;
		madepth=max(madepth,depth[i]);
	}
	makesqrttree(0,-1);
	int mi=INT_MAX;
	int ma=INT_MIN;
	for(int y:blocktree){
		mi=min(mi,eulerbegin[y]);
		ma=max(ma,eulerend[y]);
		partof[y]=sqrttree.size();
	}
	blockeulerbegin.push_back(mi);
	blockeulerend.push_back(ma);
	sqrttree.push_back(blocktree);
	blocktree.clear();
	blocktreesize=0;
	for(int i=0;i<sqrttree.size();i++){
		declaresumtree(i);
	}
	string qu;
	int u,a,b;
	lli c;
	for(int i=0;i<q;i++){
		cin>>qu;
		if(qu=="UPDATE"){
			cin>>u>>a>>b>>c;
			update(u,a+1,b+1,c);
		}
		else{
			cin>>u>>a>>b;
			printf("%lli\n",query(u,a+1,b+1));
		}
	}
}