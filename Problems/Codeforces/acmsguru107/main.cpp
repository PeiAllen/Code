#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;
	if(n<9)printf("0\n");
	else if(n==9)printf("8\n");
	else{
		printf("72");
		for(int i=0;i<n-10;i++){
			printf("0");
		}
	}
	return 0;
}