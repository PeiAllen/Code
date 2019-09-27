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
	char ans[32];
	char myBytes[32] = {
			0x3b, 0x65, 0x21, 0xa , 0x38, 0x0 , 0x36, 0x1d,
			0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa ,
			0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
			0xa , 0x61, 0x31, 0x31, 0x30, 0x30, 0x67, 0x37,
	};
        for (int i=0; i<32; i++) {
        	ans[i]=myBytes[i]^0x55;
            pr(ans[i]);
        }
    return 0;
}