#include <bits/stdc++.h>
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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	char myBytes[32] = {
			106 , 85  , 53  , 116 , 95  , 52  , 95  , 98  ,
			0x55, 0x6e, 0x43, 0x68, 0x5f, 0x30, 0x66, 0x5f,
			0142, 0131, 0164, 063 , 0163, 0137, 066 , 070 ,
			'0' , '2' , 'c' , '0' , '4' , 'c' , 'b' , '7' ,
	};
	rep(i,0,32)printf("%c",myBytes[i]);
    return 0;
}