#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
bitset<30> arr[21];
bitset<5000> arr2[1000];
ll dp[1001][(1<<16)];
ll mod=1e9+7;
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l,m;
    cin>>n>>l>>m;
    if(l>16) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                char a;
                cin >> a;
                arr[i][j] = (a == '1');
            }
        }
        for (int i = 0; i < m; i++) {
            bitset<30> te;
            int ans = 0;
            for (int j = 0; j < l; j++) {
                char a;
                cin >> a;
                te[j] = (a == '1');
            }
            for (int j = 0; j < (1 << n); j++) {
                bitset<30> te2;
                for (int k = 0; k < n; k++) {
                    if (j & (1 << k))te2 |= arr[k];
                    else te2 &= arr[k];
                }
                if (te2 == te)ans++;
            }
            printf("%d\n", ans);
        }
    }
    else{
        dp[0][0]=1;
        for (int i = 1; i <= n; i++) {
            int x=0;
            for (int j = 0; j < l; j++) {
                char a;
                cin >> a;
                if(a=='1')x+=(1<<j);
            }
            for(int j=0;j<(1<<l);j++){
                dp[i][j&x]=fix(dp[i][j&x]+dp[i-1][j]);
                dp[i][j|x]=fix(dp[i][j|x]+dp[i-1][j]);
            }
        }
        while(m--){
            int x=0;
            for(int i=0;i<l;i++){
                char a;
                cin >> a;
                if(a=='1')x+=(1<<i);
            }
            printf("%lli\n",dp[n][x]);
        }
    }

    for(int i=0;i<n;i++){
        for (int j = 0; j < l; j++) {
            char a;
            cin >> a;
            arr2[i][j]=(a=='1');
        }
    }
    while(m--){
        bitset<5000> hasto;
        for (int j = 0; j < l; j++) {
            char a;
            cin >> a;
            hasto[j]=(a=='0');
        }
        
    }
    return 0;
}