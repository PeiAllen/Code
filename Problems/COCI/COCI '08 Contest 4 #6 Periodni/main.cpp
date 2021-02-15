#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MAXN=501,MAXV=1e6+1;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll dp[MAXN][MAXN];
ll numofways[MAXN];
ll fact[MAXV],inv[MAXV];
int arr[MAXN];
vector<int> heights;
ll choose(ll a, ll b){
    return fact[a]*inv[a-b]%mod*inv[b]%mod;
}
ll permute(ll a, ll b){
    return fact[a]*inv[a-b]%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    fact[0]=1,inv[0]=1;
    for(ll i=1;i<MAXV;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fp(fact[i],mod-2);
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        heights.push_back(arr[i]);
    }
    heights.push_back(0);
    numofways[0]=1;
    sort(heights.begin(),heights.end()),heights.erase(unique(heights.begin(),heights.end()),heights.end());
    for(int i=sz(heights)-1;i>=1;i--){
        vector<pii> lengths;
        int left=1;
        for(int j=1;j<=n;j++){
            if(arr[j]<=heights[i-1]){
                if(j>left)lengths.push_back({left,j-1});
                left=j+1;
            }
        }
        if(n+1>left)lengths.push_back({left,n});
        for(auto x:lengths){
            fill(numofways+1,numofways+min(k,x.second-x.first+1)+1,0);
            for(int j=x.first;j<=x.second;){
                while(j<=x.second&&arr[j]<=heights[i])j++;
                if(j<=x.second){
                    int ne=j+1;
                    while(ne<=x.second&&arr[ne]>heights[i])ne++;
                    for(int l=min(k,x.second-x.first+1);l>=1;l--){
                        for(int m=1;m<=min(l,ne-j);m++)numofways[l]=(numofways[l]+numofways[l-m]*dp[j][m]%mod)%mod;
                    }
                    j=ne;
                }
            }
            fill(dp[x.first],dp[x.first]+k+1,0);
            for(int l=0;l<=min(k,x.second-x.first+1);l++){
                for(int m=0;m<=min({k-l,x.second-x.first+1-l,heights[i]-heights[i-1]});m++){
                    dp[x.first][l+m]=(dp[x.first][l+m]+numofways[l]*(choose(x.second-x.first+1-l,m)*permute(heights[i]-heights[i-1],m)%mod)%mod)%mod;
                }
            }
        }
    }
    printf("%lli\n",dp[1][k]);
    return 0;
}