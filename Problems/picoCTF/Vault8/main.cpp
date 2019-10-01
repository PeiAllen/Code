#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int switchBits(int a, int l, int r){
	int lb=((a&(1<<l))?1:0);
	int rb=((a&(1<<r))?1:0);
	if(rb){
		if(!lb)a+=(1<<l);
	}
	else{
		if(lb)a-=(1<<l);
	}
	if(lb){
		if(!rb)a+=(1<<r);
	}
	else{
		if(rb)a-=(1<<r);
	}
	return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int expected[32] = {
			0xF4,
			0xC0,
			0x97,
			0xF0,
			0x77,
			0x97,
			0xC0,
			0xE4,
			0xF0,
			0x77,
			0xA4,
			0xD0,
			0xC5,
			0x77,
			0xF4,
			0x86,
			0xD0,
			0xA5,
			0x45,
			0x96,
			0x27,
			0xB5,
			0x77,
			0xF1,
			0xC1,
			0xD1,
			0xA5,
			0xD1,
			0xD2,
			0xD0,
			0xA4,
			0xC0
	};
	for (int b = 0; b < 32; b++) {
		int c = expected[b];
		c = switchBits(c, 6, 7);
		c = switchBits(c, 2, 5);
		c = switchBits(c, 3, 4);
		c = switchBits(c, 0, 1);
		c = switchBits(c, 4, 7);
		c = switchBits(c, 5, 6);
		c = switchBits(c, 0, 3);
		c = switchBits(c, 1, 2);
		expected[b] = c;
	}
	rep(i,0,32)pr((char)expected[i]);
	prl("");
    return 0;
}