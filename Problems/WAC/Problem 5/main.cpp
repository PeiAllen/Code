#include <bits/stdc++.h>
using namespace std;
vector<int> matrix[50003];
vector<int> matrix2[50003];
set<int> matrixte[50003];
int n,m,k,tn;
int inde=1;
int lowind[50003];
bool inst[50003];
int partof[50003];
int scnum=1;
bool gone[50003];
bitset<50003> cango[50003];
stack<int> st;
int flip(int a){
	return (a+n-1)%tn+1;
}
void add(int a,int b){
	matrix[flip(a)].push_back(b);
	matrix[flip(b)].push_back(a);
}
void scc(int loc){
	int cur=inde++;
	lowind[loc]=cur;
	st.push(loc);
	inst[loc]=true;
	for(int x:matrix[loc]){
		if(!lowind[x])scc(x);
		if(inst[x])lowind[loc]=min(lowind[loc],lowind[x]);
	}
	if(lowind[loc]==cur){
		while(st.top()!=loc){
			int te=st.top();
			st.pop();
			inst[te]=false;
			partof[te]=scnum;
		}
		st.pop();
		inst[loc]=false;
		partof[loc]=scnum++;
	}
}
void dfs(int loc){
	gone[loc]=true;
	cango[loc][loc]=true;
	for(int x:matrix2[loc]){
		if(!gone[x])dfs(x);
		cango[loc]|=cango[x];
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    tn=n*2;
    int in;
    vector<int> must;
    for(int i=0;i<k;i++){
		cin>>in;
		add(in,in);
		must.push_back(in);
    }
    string in2;
    int in1;
    for(int i=0;i<m;i++){
    	cin>>in2>>in>>in1;
    	if(in2=="FRIENDS"){
    		add(in,flip(in1));
    		add(flip(in),in1);
    	}
    	else if(in2=="ENEMIES"){
			add(flip(in),flip(in1));
    	}
    	else if(in2=="PARTNERS"){
			add(in,in1);
			add(flip(in),flip(in1));
    	}
    	else{
			add(in,in1);
    	}
    }
    for(int i=1;i<=n*2;i++){
    	if(!lowind[i])scc(i);
    }
    for(int i=1;i<=n;i++){
		if(partof[i]==partof[i+n]&&partof[i]){
			printf("NO\n");
			return 0;
		}
    }
    printf("YES\n");
    for(int i=1;i<=tn;i++){
    	for(int x:matrix[i]){
    		matrixte[partof[i]].insert(partof[x]);
    	}
    }
	for(int i=1;i<scnum;i++){
		for(int x:matrixte[i]){
			matrix2[i].push_back(x);
		}
	}
	for(int i=1;i<scnum;i++) {
		if(!gone[i])dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(cango[partof[i]][partof[i+n]])printf("0");
		else if(cango[partof[i+n]][partof[i]])printf("1");
		else printf("?");
	}
	printf("\n");
    return 0;
}