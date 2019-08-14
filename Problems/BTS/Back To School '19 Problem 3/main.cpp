#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long double n,m;
	cin>>n>>m;
	long double need=ceil(pow(n,1.0/(double)m));
	printf("%lli\n",(lli)ceil(log2((long double)need)));
	return 0;
}