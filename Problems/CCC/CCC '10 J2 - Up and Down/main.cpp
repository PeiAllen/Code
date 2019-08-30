#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int a,b,c,d,s;
	cin>>a>>b>>c>>d>>s;
	int n=s/(a+b)*(a-b)+min(a,s%(a+b))-max(0,min(b,(s%(a+b))-a));
	int br=s/(c+d)*(c-d)+min(c,s%(c+d))-max(0,min(d,(s%(c+d))-c));
	if(n==br)printf("Tied\n");
	else if(n>br)printf("Nikky\n");
	else printf("Byron\n");
    return 0;
}