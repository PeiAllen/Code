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
    string buffer="jU5t_a_sna_3lpm19ga4a_u_4_mfre41";
        int i;
        for (i=0; i<8; i++) {
	        ans[i]=buffer[i];
        }
        for (; i<16; i++) {
        	ans[23-i]=buffer[i];
        }
        for (; i<32; i+=2) {
        	ans[46-i]=buffer[i];
        }
        for (i=31; i>=17; i-=2) {
        	ans[i]=buffer[i];
        }
       rep(i,0,32)pr(ans[i]);
    return 0;
}