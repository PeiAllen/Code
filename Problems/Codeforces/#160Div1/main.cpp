#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
int pf[501];
bool baf[501];
lli mod;
lli fix(lli a){
    if(a<0)a+=mod;
    else if(a>=mod)a-=mod;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>mod;
    int middle=upper_bound(primes.begin(),primes.end(),sqrt(n))-primes.begin();
    int end=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
    lli ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<middle;j++){
            if(i%primes[j]==0)pf[i]+=(1<<j);
        }
        for(int j=middle;j<end;j++)if(i%primes[j]==0)baf[i]=true;
    }
    if(middle==0) {
        lli tetot=1;
        for (int k = middle; k < end; k++) {
            lli aam = 1, bam = 1;
            for (int l = 1; l * primes[k] <= n; l++) {
                aam = aam * (lli) 2 % mod;
                bam = bam * (lli) 2 % mod;
            }
            tetot = tetot * fix(aam + bam - 1) % mod;
        }
        ans = fix(tetot + ans);
    }
    else {
        for (int i = 0; i < (1 << middle); i++) {
            lli tot = 0;
            int othj = 0;
            lli tetot = 1;
            for (int k = 0; k < middle; k++)if (i & (1 << k) && !(0 & (1 << k)))othj += (1 << k);
            for (int k = 2; k <= n; k++) {
                if (!baf[k] && ((pf[k] | 0) == 0 || (pf[k] || othj) == othj))tetot = tetot * (lli) 2 % mod;
            }
            for (int k = middle; k < end; k++) {
                lli aam = 1, bam = 1;
                for (int l = 1; l * primes[k] <= n; l++) {
                    if ((pf[l] | 0) == 0)aam = aam * (lli) 2 % mod;
                    if ((pf[l] | othj) == othj)bam = bam * (lli) 2 % mod;
                }
                tetot = tetot * fix(aam + bam - 1) % mod;
            }
            tot = fix(tetot + tot);
            for (int j = i; j; j = (j - 1) & i) {
                othj = 0;
                tetot = 1;
                for (int k = 0; k < middle; k++)if (i & (1 << k) && !(j & (1 << k)))othj += (1 << k);
                for (int k = 2; k <= n; k++) {
                    if (!baf[k] && ((pf[k] | j) == j || (pf[k] || othj) == othj))tetot = tetot * (lli) 2 % mod;
                }
                for (int k = middle; k < end; k++) {
                    lli aam = 1, bam = 1;
                    for (int l = 1; l * primes[k] <= n; l++) {
                        if ((pf[l] | j) == j)aam = aam * (lli) 2 % mod;
                        if ((pf[l] | othj) == othj)bam = bam * (lli) 2 % mod;
                    }
                    tetot = tetot * fix(aam + bam - 1) % mod;
                }
                tot = fix(tetot + tot);
            }
            ans = fix(ans + tot * (lli) (__builtin_popcount(i) % 2 ? 1 : -1));
        }
    }
    printf("%lli\n",ans);
    return 0;
}