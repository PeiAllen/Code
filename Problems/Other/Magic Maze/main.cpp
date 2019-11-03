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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//168
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
const int MAXN=1e5+1;
int prefixr[MAXN][168];
int prefixc[MAXN][168];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    sc(n,q);
    int in;
	    rep(i, 1, n + 1) {
		    sc(in);
		    rep(j, 0, 168) {
			    if (in % primes[j] == 0)prefixr[i][j]=1;
			    prefixr[i][j]+=prefixr[i-1][j];
		    }
	    }
	rep(i, 1, n + 1) {
		sc(in);
		rep(j, 0, 168) {
			if (in % primes[j] == 0)prefixc[i][j]=1;
			prefixc[i][j]+=prefixc[i-1][j];
		}
	}
    int ra,ca,rb,cb;
    while(q--){
    	sc(ra,ca,rb,cb);
    	int best=-1;
    	rep(i, 168, 0) {
    		if (prefixr[ra][i]-prefixr[ra-1][i]){
    			if(prefixr[rb][i]-prefixr[rb-1][i]){
    				if(prefixc[cb][i]-prefixc[ca-1][i]){
    					best=max(best,primes[i]);
    					break;
    				}
    			}
    		}
    	}
	    rep(i, 168, 0) {
		    if (prefixc[ca][i]-prefixc[ca-1][i]){
			    if(prefixc[cb][i]-prefixc[cb-1][i]){
				    if(prefixr[rb][i]-prefixr[ra-1][i]){
					    best=max(best,primes[i]);
					    break;
				    }
			    }
		    }
	    }
	    rep(i,168,0){
    		if(prefixc[ca][i]-prefixc[ca-1][i]){
    			if(prefixr[rb][i]-prefixr[rb-1][i]){
				    best=max(best,primes[i]);
				    break;
    			}
    		}
    	}
	    rep(i,168,0){
		    if(prefixr[ra][i]-prefixr[ra-1][i]){
			    if(prefixc[cb][i]-prefixc[cb-1][i]){
				    best=max(best,primes[i]);
				    break;
			    }
		    }
	    }
	    rep(i,168,0){
    		if(prefixr[rb][i]-prefixr[ra-1][i]==rb-ra+1){
    			best=max(best,primes[i]);
			    break;
    		}
    	}
	    rep(i,168,0){
		    if(prefixc[cb][i]-prefixc[ca-1][i]==cb-ca+1){
			    best=max(best,primes[i]);
			    break;
		    }
	    }
	    prl(best);
    }
    return 0;
}