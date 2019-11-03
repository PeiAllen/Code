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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//168
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
const int MAXN=101;
bool arr[MAXN][MAXN][168];
int col[MAXN],row[MAXN];
bool dp[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
	sc(n,q);
	rep(i,1,n+1)sc(row[i]);
	rep(i,1,n+1)sc(col[i]);
	rep(i,1,n+1)rep(j,1,n+1)rep(k,0,168)arr[i][j][k]=(row[i]*col[j]%primes[k]==0);
	int ra,ca,rb,cb;
	while(q--){
		sc(ra,ca,rb,cb);
		bool work=false;
		rep(x,168,0) {
			memset(dp,0,sizeof(dp));
			dp[ra-1][ca] = true;
			rep(i, ra, rb + 1)rep(j, ca, cb + 1) {
					dp[i][j]=arr[i][j][x]&(dp[i-1][j]|dp[i][j-1]);
			}
			if(dp[rb][cb]){
				prl(primes[x]);
				work=true;
				break;
			}
		}
		if(!work)prl(-1);
	}
    return 0;
}