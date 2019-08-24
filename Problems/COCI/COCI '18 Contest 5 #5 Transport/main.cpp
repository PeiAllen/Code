#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<int,lli> pil;
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
	void recalc(){am=1+(child[0]?child[0]->am:0)+(child[1]?child[1]->am:0);}
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
		if(a<=data){
			if(child[0])return child[0]->query(a)+1+(child[1]?child[1]->am:0);
			return 1+(child[1]?child[1]->am:0);
		}
		return (child[1]?child[1]->query(a):0);
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
const int MAXN=100001;
lli gas[MAXN];
vector<pil> matrix[MAXN];
bool cent[MAXN];
int subtreesize[MAXN];
int dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(pil x:matrix[loc])if(x.first!=parent&&!cent[x.first])subtreesize[loc]+=dfssize(x.first,loc);
	return subtreesize[loc];
}
int decompsubtree(int loc, int parent, int size){
	for(pil x:matrix[loc]){
		if(x.first!=parent&&!cent[x.first]&&subtreesize[x.first]>size)return decompsubtree(x.first,loc,size);
	}
	return loc;
}
lli ans=0;
treap routes;
vector<lli> toadd;
void dfs(int loc,int parent, lli fuel, lli need,lli comemin,lli dist){//current fuel,excluding fuel at root, min fuel at one point, how much fuel is needed
	need=min(need,fuel);
	ans+=routes.query(abs(need));
	comemin=min(comemin+gas[loc]-dist,gas[loc]-dist);
	if(comemin>=0){
		toadd.push_back(fuel+gas[loc]);
	}
	for(pil x:matrix[loc]){
		if(x.first!=parent&&!cent[x.first]){
			dfs(x.first,loc,fuel-x.second+gas[loc],need,comemin,x.second);
		}
	}
}
void decompfulltree(int loc){
	int next=decompsubtree(loc,-1,dfssize(loc,-1)/2);
	cent[next]=true;
	routes.del();
	routes.insert(gas[next]);
	for(pil x:matrix[next]){
		if(!cent[x.first]){
			dfs(x.first,next,-x.second,0,0,x.second);
			ans+=toadd.size();
			for(lli y:toadd){
				routes.insert(y+gas[next]);
			}
			toadd.clear();
		}
	}
	routes.del();
	for(int x=matrix[next].size()-1;x>=0;x--){
		if(!cent[matrix[next][x].first]){
			dfs(matrix[next][x].first,next,-matrix[next][x].second,0,0,matrix[next][x].second);
			for(auto y:toadd){
				routes.insert(y+gas[next]);
			}
			toadd.clear();
		}
	}
	for(pil x:matrix[next]){
		if(!cent[x.first])decompfulltree(x.first);
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>gas[i];
    }
    int a,b;
    lli c;
    for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
    }
    decompfulltree(1);
    printf("%lli\n",ans);
    return 0;
}