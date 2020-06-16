#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
unordered_map<bitset<5000>,ll> dp[1001];
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
    dp[0][0]=1;
    for (int i = 1; i <= n; i++) {
        bitset<5000> x(0);
        for (int j = 0; j < l; j++) {
            char a;
            cin >> a;
            if(a=='1')x[j]=true;
        }
        for(auto j:dp[i-1]){
            dp[i][j.first&x]=fix(dp[i][j.first&x]+j.second);
            dp[i][j.first|x]=fix(dp[i][j.first|x]+j.second);
        }
    }
    while(m--){
        bitset<5000> x(0);
        for(int i=0;i<l;i++){
            char a;
            cin >> a;
            if(a=='1')x[i]=true;
        }
        if(dp[n].count(x))printf("%lli\n",dp[n][x]);
        else printf("0\n");
    }

    return 0;
}