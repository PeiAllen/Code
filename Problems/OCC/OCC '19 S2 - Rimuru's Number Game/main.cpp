#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli n;
int startwith(lli a){
	if(a>n)return 0;
	return startwith(a*10+2)+startwith(a*10+3)+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n;
	printf("%d\n",startwith(0)-1);
    return 0;
}