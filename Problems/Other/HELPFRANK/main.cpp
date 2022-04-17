#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)
const int MN=1001;
ll ans[MN];
int32_t main() {
    boost();
//    for(int mod=2;mod<=100;mod++){
        int mod=251;
        int am=0;
        vector<int> bad;
        int cnt=0;
        int totient=0;
        for(int i=1;i<mod;i++){
            if(__gcd(mod,i)==1)totient++;
        }
        for(int i=2;i<=2;i++){
            set<int> residue;
            for(int j=0;j<mod;j++){
                ll v=j;
                for(int k=1;k<i;k++){
                    v=v*j%mod;
                }
                residue.insert(v);
            }
            if(residue.size()<=(mod+1)/2){
                printf("%d\n",(residue.size()));
                for(auto x:residue)printf("%d ",x);
            }
        }
//        printf("\%d\n",cnt);
//    }
    return 0;
}