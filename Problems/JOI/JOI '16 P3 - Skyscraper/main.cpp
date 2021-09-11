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
ll arr[MAXN];
ll dp[MAXN][MAXL][MAXN][3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int value=0;value<=l;value++){
            for(int comps=1;comps<=i;comps++){
                for(int ends=0;ends<=2;ends++){
                    if(value-(arr[i]-arr[i-1])*(ll(2)*ll(comps)-ll(ends))>=0)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value-(arr[i]-arr[i-1])*(ll(2)*ll(comps)-ll(ends))][comps][ends]*(ll(2)*ll(comps)-ll(ends))%mod);
                    if(value-(arr[i]-arr[i-1])*(ll(2)*ll(comps-1)-ll(ends))>=0)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value-(arr[i]-arr[i-1])*(ll(2)*ll(comps-1)-ll(ends))][comps-1][ends]);
                    if(value-(arr[i]-arr[i-1])*(ll(2)*ll(comps+1)-ll(ends))>=0)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value-(arr[i]-arr[i-1])*(ll(2)*ll(comps+1)-ll(ends))][comps+1][ends]*fix(ll(comps+1-ends)*ll(comps+1-ends-1)%mod+ll(ends)*ll(comps+1-ends)%mod+ll(ends==2&&i==n)));
                    if(ends&&value-(arr[i]-arr[i-1])*(ll(2)*ll(comps-1)-ll(ends-1))>=0)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value-(arr[i]-arr[i-1])*(ll(2)*ll(comps-1)-ll(ends-1))][comps-1][ends-1]*ll(ends==2?1:2)%mod);
                    if(ends&&value-(arr[i]-arr[i-1])*(ll(2)*ll(comps)-ll(ends-1))>=0)dp[i][value][comps][ends]=fix(dp[i][value][comps][ends]+dp[i-1][value-(arr[i]-arr[i-1])*(ll(2)*ll(comps)-ll(ends-1))][comps][ends-1]*fix(ll(comps-(ends-1))*ll(ends==2?1:2)%mod+(i==n&&ends==2)));
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=l;i++)ans=fix(ans+dp[n][i][1][2]);
    printf("%lli\n",ans);
    return 0;
}
/*dp[loc][current cost][number of components with direction fixed(front and end)][number of ends done]=number of ways
transitions, append to the front of a component/endof a component (can only combine to end or front of end or begin)
                    apply cost of arr[i]-arr[i-1]*(numberofopenends)
            make new compoment
                    apply cost of arr[i]-arr[i-1]*(numberofopenends (not including new ends created))
            connect two components, (can only combine to end or front of end or begin) (Can only append two end points when i==n)
                    apply cost of arr[i]-arr[i-1]*(numberofopenends (not excluding new ends deleted))
            add beginning/end node
                    apply cost of arr[i]-arr[i-1]*(numberofopenends (not including new ends created))
            Append a begin/end node to a component (Can only append to a a end component when i==n)
                    apply cost of arr[i]-arr[i-1]*(numberofopenends (not including new ends created))
*/