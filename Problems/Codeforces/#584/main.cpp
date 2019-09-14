#include<bits/stdc++.h>
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

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	sc(t);
	while(t--){
		int n,m;
		sc(n,m);
		map<int,vector<pii>,greater<int>> nums;
		int a;
		vector<int> col[m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sc(a);
				nums[a].push_back({i,j});
				col[j].push_back(a);
			}
		}
		set<int> cols;
		for(auto x:nums){
			bool done=false;
			for(auto y:x.second){
				cols.insert(y.second);
				if(cols.size()==n){
					done=true;
					break;
				}
			}
			if(done)break;
		}
		vector<int> usecol;
		for(int x:cols){
			usecol.push_back(x);
		}
		int mas[n];
		for(int i=0;i<n;i++)mas[i]=0;
		for(int j=0;j<usecol.size();j++){
			int bes=-100;
			int loc=0;
			for(int k=0;k<n;k++){
				int te=0;
				for(int l=0;l<n;l++) {
					te += max(mas[(k + l) % n], col[usecol[j]][l]);
				}
				if(te>=bes){
					bes=te;
					loc=k;
				}
			}
			for(int l=0;l<n;l++) {
				mas[(loc + l) % n] = max(mas[(loc + l) % n], col[usecol[j]][l]);
			}
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=mas[i];
		}
		pr(sum);
		pr("\n");
	}
	return 0;
}