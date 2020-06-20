#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=17;
int arr[MAXN];
ll dp[(int)(1<<16)][17];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[(1<<i)][i]=1;
    }
    for(int i=1;i<(1<<n);i++){
        if(__builtin_popcount(i)>1) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < n; l++) {
                        if (i & (1 << l) && abs(arr[l] - arr[j]) > k) {
                            dp[i][j] += dp[i - (1 << j)][l];
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=dp[(1<<n)-1][i];
    }
    printf("%lli\n",ans);
    return 0;
}