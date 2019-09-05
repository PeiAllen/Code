#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<vector<int>> dp;
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
bool valid(int x, int y){
	if(x<0||x>=n||y<0||y>=m)return 0;
	if(arr[x][y]=='#')return 0;
	return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
			if(valid(i,j)){
				if(valid(i+1,j)){
					matrix[i*m+j].push_back((i+1)*m+j);
					matrix[(i+1)*m+j].push_back(i*m+j);
				}
				if(valid(i,j+1)){
					matrix[i*m+j].push_back(i*m+j+1);
					matrix[i*m+j+1].push_back(i*m+j);
				}
			}
    	}
    }
    scc(0,-1);
    if(group[(n-1)*m+m-1]==0)printf("0\n");
    else if(group[0]==group[(n-1)*m+m-1])printf("2\n");
    else printf("1\n");
    return 0;
}