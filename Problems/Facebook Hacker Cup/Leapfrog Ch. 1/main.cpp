#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen ("C:\\Users\\allen\\CLionProjects\\Leapfrog Ch. 1\\input.txt","r",stdin);
	freopen ("C:\\Users\\allen\\CLionProjects\\Leapfrog Ch. 1\\output.txt","w",stdout);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		string n;
		cin>>n;
		int beta=0;
		for(int i=0;i<n.size();i++){
			if(n[i]=='B')beta+=1;
		}
		if(beta==n.size()-1){
			printf("Case #%d: N\n",test);
			continue;
		}
		if(beta>=n.size()/2){
			printf("Case #%d: Y\n",test);
			continue;
		}
		printf("Case #%d: N\n",test);
	}
	return 0;
}