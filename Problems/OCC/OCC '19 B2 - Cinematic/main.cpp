#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,y;
	cin>>n>>y;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	lli in;
	map<string,lli> am;
	for(int i=0;i<n;i++){
		cin>>in;
		am[arr[i]]=in;
	}
	string a;
	lli ans=0;
	for(int i=0;i<y;i++){
		cin>>a;
		ans+=am[a];
		am[a]=0;
	}
	printf("%lli\n",ans);
    return 0;
}