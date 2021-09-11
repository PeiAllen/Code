#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
random_device rd;
struct node{
	lli data;
	int am;
	unsigned int priority;
	struct node* child[2];
	node(lli a){
		data=a;
		am=1;
		priority=rd();
		child[0]=NULL;
		child[1]=NULL;
	}
	int gtsz(int a) { return (child[a] ? child[a]->am : 0); }
	void recalc(){am=1+gtsz(0)+gtsz(1);}
	struct node* rot(int ch){
		auto temp=child[ch];
		child[ch]=temp->child[!ch];
		temp->child[!ch]=this;
		recalc();
		temp->recalc();
		return temp;
	}
	struct node* insert(lli a){
		int ch=(a>data);
		if(!child[ch])child[ch]=new node(a);
		else child[ch]=child[ch]->insert(a);
		recalc();
		if(child[ch]->priority>priority)return rot(ch);
		return this;
	}
	void deltree(){
		if(child[0])child[0]->deltree();
		if(child[1])child[1]->deltree();
		delete(this);
	}
	int query(lli a){
		if(a>=data)return gtsz(0)+1+(child[1]?child[1]->query(a):0);
		return (child[0]?child[0]->query(a):0);
	}
};
struct treap{
	node* rt;
	treap(){
		rt=NULL;
	}
	void insert(lli a){
		if(rt)rt=rt->insert(a);
		else rt=new node(a);
	}
	void del(){
		if(rt){
			rt->deltree();
			rt=NULL;
		}
	}
	lli query(lli a){
		if(rt)return rt->query(a);
		else return 0;
	}
};
const int MAXN=1e5+1;
int n,k;
lli val[MAXN];
vector<int> matrix[MAXN];
bool cent[MAXN];
int subtreesize[MAXN];
int dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(int x:matrix[loc])if(!cent[x]&&x!=parent)subtreesize[loc]+=dfssize(x,loc);
	return subtreesize[loc];
}
int decompsubtree(int loc, int parent, int size){
	for(int x:matrix[loc]){
		if(!cent[x]&&x!=parent&&subtreesize[x]>size)return decompsubtree(x,loc,size);
	}
	return loc;
}
vector<lli> down[4];
treap up[4];
void dfs(int loc, int parent, int dir, lli last, lli sum){//down inc is 1
	sum+=val[loc];
	int tedir=(last==val[loc]?3:(last>val[loc]?2:1));
	if(dir==3)dir=tedir;
	else if(tedir!=3&&dir!=tedir)dir=0;
	if(dir){
		down[dir].push_back(sum);
		for(int x:matrix[loc]){
			if(!cent[x]&&x!=parent)dfs(x,loc,dir,val[loc],sum);
		}
	}
}
lli ans=0;
void decompfulltree(int loc){
	int next=decompsubtree(loc,-1,dfssize(loc,-1)/2);
	cent[next]=true;
	up[1].del();
	up[2].del();
	up[3].del();
	up[3].insert(val[next]);
	if(val[next]<=0)ans+=1;
	for(int x:matrix[next]){
		if(!cent[x]){
			dfs(x,next,3,val[next],0);
			for(lli y:down[1]){
				ans+=up[2].query(0-y)+up[3].query(0-y);
			}
			for(lli y:down[2]){
				ans+=up[1].query(0-y)+up[3].query(0-y);
			}
			for(lli y:down[3]){
				ans+=up[1].query(0-y)+up[2].query(0-y)+up[3].query(0-y);
			}
			rep(i,1,4){
				for(lli y:down[i]){
					up[i].insert(y+val[next]);
				}
				down[i].clear();
			}
		}
	}
	for(int x:matrix[next]){
		if(!cent[x])decompfulltree(x);
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,k);
    rep(i,1,n+1){
    	sc(val[i]);
    	val[i]-=k;
    }
    int a,b;
    rep(i,1,n){
    	sc(a,b);
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }
    decompfulltree(1);
    prl(ans);
    return 0;
}