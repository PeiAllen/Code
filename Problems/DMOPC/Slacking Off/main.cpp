#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll randnum[MN];
map<ll,ll> cnt;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n>m){
        vector<string> te(m);
        for(int i=0;i<m;i++){
            te[i].resize(n);
            for(int j=0;j<n;j++)te[i][j]=arr[j][i];
        }
        arr=te;
        swap(n,m);
    }
    vector<vector<ll>> psa(m);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(ll(1), ll(1e18));
    for(int i=0;i<n;i++)randnum[i]=dis(gen);
    for(int i=0;i<m;i++){
        psa[i].resize(n+1);
        for(int j=0;j<n;j++){
            psa[i][j+1]=psa[i][j]^(arr[j][i]=='B'?randnum[j]:0);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[i][k]!=arr[j][k]){
                    for(auto x:cnt)ans+=x.second*(x.second-1)/2;
                    cnt=map<ll,ll>();
                }
                else cnt[psa[k][j+1]^psa[k][i]]++;
            }
            for(auto x:cnt){
                ans+=x.second*(x.second-1)/2;
            }
            cnt=map<ll,ll>();
        }
    }
    printf("%lli\n",ans);
    return 0;
}