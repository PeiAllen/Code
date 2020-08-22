#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e2+1;
const int MAXL=1e3+1;
const ll mod=1e9+7;
ll fix(ll a){
    return (a%mod+mod)%mod;
}
int arr[MAXN];
ll dp[MAXN][MAXL][MAXN][3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int value=0;value<=l;value++){
            for(int comps=0;comps<=i;comps++){
                for(int ends=0;ends<=min(2,comps);ends++){
                    if(comps)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value][comps][ends]*(ll(2)*ll(comps)-ll(ends)));
                }
            }
        }
    }
    return 0;
}
/*dp[loc][L][number of components][number of ends done]=number of ways
transitions, append to the front of a component/endof a component (can only combine to end or front of end or begin)
                    apply cost of +arr[i],-arr[i]
            make new compoment
                    cost of -arr[i],-arr[i]
            connect two components, (can only combine to end or front of end or begin)
                    cost of +arr[i],+arr[i]
            add beginning/end node
                    cost of -arr[i]
*/