#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct pa{
	lli x,y;
	pa(lli a=0, lli b=0):x(a),y(b){}
};
lli n,m;
lli make(lli x){
	while(x<0)x+=m;
	while(x>=m)x-=m;
	return x;
}
pa exgcd(lli a, lli b){
	if(b==0)return pa(1,0);
	else{
		pa te=exgcd(b,a%b);
		return pa(te.y,te.x-te.y*a/b);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	printf("%lli\n",make(exgcd(n,m).x));
	return 0;
}