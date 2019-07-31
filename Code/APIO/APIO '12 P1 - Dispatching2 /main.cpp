#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
random_device rd;
struct node{
	int size;
	unsigned int priority;
	lli data,sum;
	node* child[2];
	node(lli a=0){
		child[0]=NULL;
		child[1]=NULL;
		size=1;
		data=a;
		sum=a;
		priority=rd();
	}
	void recalc(){
		size=(child[0]?child[0]->size:0)+((child[1]?child[1]->size:0))+1;
		sum=(child[0]?child[0]->sum:0)+((child[1]?child[1]->sum:0))+data;
	}
	node* rotation(int ch){//ch is which child is going up
		node* te=child[ch];
		child[ch]=child[ch]->child[!ch];
		te->child[!ch]=this;
		recalc();
		te->recalc();
		return te;
	}
	node* insert(int x){
		int ch=(data<x);
		if(!child[ch])child[ch]= new node(x);
		else child[ch]=child[ch]->insert(x);
		recalc();
		if(child[ch]->priority>priority)return rotation(ch);
		return this;
	}
	int getmax(lli left){
		if(sum<=left)return size;
		if((child[0]?child[0]->sum:0)+data<=left){
			return (child[0]?child[0]->size:0)+1+(child[1]?child[1]->getmax(left-(child[0]?child[0]->sum:0)-data):0);
		}
		return (child[0]?child[0]->getmax(left):0);
	}
	node* unio(node* oth){
		if(oth->size>=size){
			oth=oth->insert(data);
			if(child[0])oth=child[0]->unio(oth);
			if(child[1])oth=child[1]->unio(oth);
			free(this);
			return oth;
		}
		else{
			return oth->unio(this);
		}
	}
	void print(){
		if(child[0])child[0]->print();
		printf("%lli %lli %d:",data,sum,size);
		if(child[1])child[1]->print();
	}
};
const int MAXN=100001;
vector<int> matrix[MAXN];
lli cost[MAXN];
lli leadership[MAXN];
lli m;
lli ans=0;
node* dfs(int loc){
	node* cur=new node(cost[loc]);
	for(int i:matrix[loc]){
		cur=cur->unio(dfs(i));
	}
	ans=max(ans,(lli)cur->getmax(m)*leadership[loc]);
	return cur;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n>>m;
	int master=-1;
	int parent;
	for(int i=1;i<=n;i++){
		cin>>parent>>cost[i]>>leadership[i];
		matrix[parent].push_back(i);
		if(parent==0)master=i;
	}
	dfs(master);
	printf("%lli\n",ans);
	return 0;
}