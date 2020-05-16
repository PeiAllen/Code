#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
bool col[10],row[10];
lli am[100];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
     lli v=(1LL<<n)-1; // current permutation of bits
    while(v<(1LL<<n*n)){
            for(lli j=0;j<n;j++)col[j]=false,row[j]=false;
            int cnt=0;
            for (lli j = 0; j < n * n; j++) {
                if(v & (1LL << j)) {
                    if (row[j / n])cnt++;
                    if (col[j % n])cnt++;
                    row[j / n] = true, col[j % n] = true;
                }
            }
            bool work=true;
            for(int j=0;j<n*n;j++){
                if(!row[j/n]&&!col[j%n])work=false;
            }
            if(!work){
                lli t = v | (v - 1); // t gets v's least significant 0 bits set to 1
// Next set to 1 the most significant bit to change,
// set to 0 the least significant ones, and add the necessary 1 bits.
                v = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
                continue;
            }
            am[cnt]++;

        lli t = v | (v - 1); // t gets v's least significant 0 bits set to 1
// Next set to 1 the most significant bit to change,
// set to 0 the least significant ones, and add the necessary 1 bits.
        v = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    }
    for(int i=0;i<n*n;i++)printf("%d:%lli %f\n",i,am[i],(double)am[i]/(double)am[0]);
    return 0;
}