#include <bits/stdc++.h>//doesn't work as you can move up
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
string arr[1000000];
int group[1000000];
int ind=0;
int gr=1;
int indof[1000000];
int low[1000000];
bool inst[1000000];
stack<int> st;
int n,m;
vector<int> matrix[1000000];
bool gone[1000000];
void scc(int loc, int parent){
	indof[loc]=++ind;
	low[loc]=indof[loc];
	st.push(loc);
	inst[loc]=true;
	for(int x:matrix[loc]){
		if(x!=parent){
			if(!indof[x])scc(x,loc);
			if(inst[x])low[loc]=min(low[loc],low[x]);
		}
	}
	if(low[loc]==indof[loc]){
		int cur=st.top();
		st.pop();
		while(1){
			group[cur]=gr;
			inst[cur]=false;
			if(cur==loc)break;
			cur=st.top();
			st.pop();
		}
		gr++;
	}
}
bool dfs(int loc, int parent, int want){
	assert(arr[loc/m][loc%m]!='#');
	if(gone[loc])return false;
	if(loc==want)return true;
	gone[loc]=true;
	for(int x:matrix[loc]){
		if(!gone[x]){
			bool te=dfs(x,loc,want);
			if(te)return te;
		}
	}
	return false;
}
bool valid(int x, int y){
	if(x>=0&&x<n&&y>=0&&y<m){
		if(arr[x][y]!='#')return 1;
	}
	return 0;
}
//int xdir[2]={1,0};
//int ydir[2]={0,1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
//    bool gone[n][m];
//    memset(gone,0,sizeof(gone));
//    queue<pii> q;
//    gone[0][0]=true;
//    q.push({0,0});
//    while(!q.empty()){
//    	pii cur=q.front();
//    	q.pop();
//    	for(int i=0;i<2;i++){
//    		pii te={cur.first+xdir[i],cur.second+ydir[i]};
//    		if(te.first>=0&&te.first<n&&te.second>=0&&te.second<m){
//    			if(arr[te.first][te.second]!='#'){
//    				if(!gone[te.first][te.second]){
//    					gone[te.first][te.second]=true;
//    					q.push(te);
//    				}
//    			}
//    		}
//    	}
//    }
//    if(!gone[n-1][m-1]){
//	    printf("0\n");
//	    return 0;
//    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
			if(valid(i,j)){
				if(valid(i+1,j)){
					if(n==499&&m==499){
					//	if(i+1==n-1&&j==m-1)assert(0);
					}
					matrix[i*m+j].push_back((i+1)*m+j);
					matrix[(i+1)*m+j].push_back(i*m+j);
				}
				if(valid(i,j+1)){
					if(n==499&&m==499){
				//		if(i==n-1&&j+1==m-1)assert(0);
					}
					matrix[i*m+j].push_back(i*m+j+1);
					matrix[i*m+j+1].push_back(i*m+j);
				}
			}
    	}
    }
    if(!dfs(0,-1,(n-1)*m+m-1)){
	    printf("0\n");
	    return 0;
    }
    scc(0,-1);
    if(group[(n-1)*m+m-1]==0)printf("0\n");
    else if(group[0]==group[(n-1)*m+m-1])printf("2\n");
    else printf("1\n");
    return 0;
}