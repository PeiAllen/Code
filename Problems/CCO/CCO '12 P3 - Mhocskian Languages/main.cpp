#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int dp[26][30][30];
string in;
set<int> cs[26];
vector<pii> arr[26];
int go(int var,int l, int r){
	if(dp[var][l][r]!=-1)return dp[var][l][r];
	if(l==r)return dp[var][l][r]=cs[var].count(in[l]-'a');
	for(pii x:arr[var]){
		for(int i=l;i<r;i++){
			if(go(x.first,l,i)&&go(x.second,i+1,r)){
				return dp[var][l][r]=1;
			}
		}
	}
	return dp[var][l][r]=0;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int v,t;
	cin>>v>>t;
	int first;
	char a;
	for(int i=0;i<v;i++){
		cin>>a;
		if(i==0)first=a-'A';
	}
	for(int i=0;i<t;i++)cin>>a;
	int ch;
	cin>>ch;
	char b;
	for(int i=0;i<ch;i++){
		cin>>a>>b;
		cs[a-'A'].insert(b-'a');
	}
	cin>>ch;
	char c;
	for(int i=0;i<ch;i++){
		cin>>a>>b>>c;
		arr[a-'A'].push_back({b-'A',c-'A'});
	}
	cin>>ch;
	for(int i=0;i<ch;i++){
		cin>>in;
		memset(dp,-1, sizeof(dp));
		printf("%d\n",go(first,0,in.size()-1));
	}
	return 0;
}