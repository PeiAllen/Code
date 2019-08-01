#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int llu;
llu mo=1e9+7;
vector<vector<llu>> matrixmultiply(vector<vector<llu>> a, vector<vector<llu>> b){
	vector<vector<llu>> ans;
	ans.resize(a.size());
	for(int i=0;i<a.size();i++){
		ans[i].resize(b[i].size(),0);
		for(int j=0;j<b[i].size();j++)for(int k=0;k<a[i].size();k++){
			ans[i][j]+=(a[i][k]*b[k][j])%mo;
			ans[i][j]%=mo;
		}
	}
	return ans;
}
llu getfib(string n){
	vector<vector<llu>> matrix={{1,1},{1,0}};
	vector<vector<llu>> ans={{1,1},{1,0}};
	for(int i=n.size()-1;i>=0;i--){
		int am=n[i]-'0';
		while(am--){
			ans=matrixmultiply(ans,matrix);
		}
		vector<vector<llu>> te=matrix;
		for(int j=0;j<9;j++) {
			matrix = matrixmultiply(matrix, te);
		}
	}
	return ans[1][0];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string n;
	cin>>n;
	int loc=n.size()-1;
	while(n[loc]=='0'){
		n[loc--]='9';
	}
	n[loc]=(char)((int)n[loc]-1);
	printf("%llu\n",getfib(n));
	return 0;
}