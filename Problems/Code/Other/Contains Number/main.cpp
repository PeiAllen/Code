#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int in;
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>in;
		s.insert(in);
	}
	while(q--){
		cin>>in;
		cout<<(s.count(in)?"YES\n":"NO\n");
	}
	return 0;
}