#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int sketchy()
{
	static int asdf=1;
	asdf*=123456789;
	return asdf;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0;i<100;i++)printf("%d\n",sketchy());
    return 0;
}