#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const ll mod=1e9+7;
ll dp[21][(1<<20)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,r;
    cin>>n>>r;
    int ex = (1 << n) - 1 - r;
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= ex; k++) {
            for (int f = 0; f <= ex; f++) {
                for(int d=0;d<=(1<<(i-2))-f;d++){
                    if((k -4*f-d)/2>=0&&(k -4*f-d)/2<=(?))
                }
                //dp[i][k] += max(ll(0), min((1 << (i - 2)) + k - 6 * f, (1 << (i - 2)) - f) - max(ll(0), ll(k - 4 * f))) * dp[i - 2][f];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= ex; i++) ans += dp[n][i];
    printf("%lld\n", ans % mod);
    return 0;
}
/*


 */
//d=k - 2*(2*(f))-2*c
//c=(k - 2*(2*(f))-d)/2
//a+c<=2