#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> matrix[400001];
int dfs(int loc, int parent){
	priority_queue<int> q;
	int ma=1;//parent of leaf
	for(int x:matrix[loc])if(x!=parent)q.push(dfs(x,loc));
	int i=0;
	while(!q.empty()){
		ma=max(ma,q.top()+(i++));//if they move to children, you repush them out
		q.pop();
	}
	return ma;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int in;
    for(int i=1;i<n;i++){
    	cin>>in;
    	matrix[in].push_back(i);
    	matrix[i].push_back(in);
    }
	printf("%d\n",dfs(0,-1));
    return 0;
}