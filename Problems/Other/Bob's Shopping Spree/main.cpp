#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
ll dp[2][MAXN];
int deq[MAXN];
int l,r;
pair<int,ll> arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        for(int j=0;j<=k;j++)if(j>=arr[i].first)dp[0][j]=max(dp[0][j],dp[0][j-arr[i].first]+arr[i].second);
    }
    int cur=1,prev=0;
    int t,d,a;
    ll q;
    for(int i=0;i<m;i++){
        cin>>q>>t>>d>>a;
        for(int mo=0;mo<d;mo++){
            l=0,r=-1;
            for(int loc=mo;loc<=k;loc+=d){
                while(l<=r&&dp[prev][deq[r]]+arr[t].second*q*((loc-deq[r])/d)<=dp[prev][loc])r--;
                deq[++r]=loc;
                while(l<=r&&deq[l]<loc-a*d)l++;
                dp[cur][loc]=dp[prev][deq[l]]+arr[t].second*q*((loc-deq[l])/d);
            }
        }
        swap(prev,cur);
    }
    ll ans=0;
    for(int i=0;i<=k;i++)ans=max(ans,dp[prev][i]);
    printf("%lli\n",ans);
    return 0;
}