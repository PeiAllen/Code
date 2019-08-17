#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<int> matrix[26];
vector<int> ord;
bool gone[26];
bool pathgone[26];
void paerase(int loc){
	for(int i=0;i<ord.size();i++){
		if(ord[i]==loc){
			ord.erase(ord.begin()+i);
			return;
		}
	}
}
bool dfs(int loc){
	pathgone[loc]=true;
	if(gone[loc])paerase(loc);
	else gone[loc]=true;
	ord.push_back(loc);
	for(int x:matrix[loc]){
		if(pathgone[x])return 0;
		if(!dfs(x))return 0;
	}
	pathgone[loc]=false;
	return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string te[n];
    string arr[n];
    int place[n];
    for(int i=0;i<n;i++)cin>>te[i];
	for(int i=0;i<n;i++)cin>>place[i];
	for(int i=0;i<n;i++)arr[i]=te[place[i]];
	for(int i=1;i<n;i++){
		int l=0;
		while(l<min(arr[i].size(),arr[i-1].size())&&arr[i][l]==arr[i-1][l]){
			l++;
		}
		if(l==min(arr[i].size(),arr[i-1].size())){
			printf("NE\n");return 0;
		}
		matrix[arr[i-1][l]-'a'].push_back(arr[i][l]-'a');
	}
	for(int i=0;i<26;i++)if(!gone[i]){
		bool te=dfs(i);
		if(!te)printf("NE\n");return 0;
	}
	for(int x:ord){
		printf("%c",x+'a');
	}
	return 0;
}