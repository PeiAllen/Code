#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
	if(x3>x4)swap(x3,x4);
	if(y3>y4)swap(y3,y4);
	printf("%lli\n",(y2-y1)*(x2-x1)+(y4-y3)*(x4-x3)-max((lli)0,min(y2,y4)-max(y1,y3))*max((lli)0,min(x2,x4)-max(x1,x3)));
	return 0;
}