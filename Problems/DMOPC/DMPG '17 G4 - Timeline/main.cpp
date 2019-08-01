#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	set<pii> events;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		events.insert({a,b});
	}
	int q;
	cin>>q;
	char c,d;
	for(int i=0;i<q;i++){
		cin>>c;
		if(c=='T'){
			ciN>>a>>b;
		}
	};
    return 0;
}