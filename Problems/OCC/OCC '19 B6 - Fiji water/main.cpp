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
	if(y%2)cout<<(n%2?"Modo\n":"Winnie\n");
	else cout<<(((n-1)%(y+1)==y?1:((n-1)%(y+1))%2)?"Winnie\n":"Modo\n");
	return 0;
}