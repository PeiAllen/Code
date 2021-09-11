#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+1;
const ll mod=1e9+7;
vector<int> matrix[MAXN];
vector<ll> tri[MAXN];
int rptr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        sort(matrix[i].begin(),matrix[i].end(),[&](auto &lhs, auto &rhs){
            return pii{sz(matrix[rhs]),rhs}<pii{sz(matrix[lhs]),lhs};
        });
        tri[i].resize(sz(matrix[i]),0);
    }
    for(int i=1;i<=n;i++){
        while(rptr[i]<sz(matrix[i])&&pii{sz(matrix[matrix[i][rptr[i]]]),matrix[i][rptr[i]]}>pii{sz(matrix[i]),i})rptr[i]++;
        for(int j=0;j<rptr[i];j++){
            for(int k=j+1;k<rptr[i];k++){
                int loc=lower_bound(matrix[matrix[i][k]].begin(),matrix[matrix[i][k]].end(),matrix[i][j],[&](auto &it, auto &val){
                    return pii{sz(matrix[val]),val}<pii{sz(matrix[it]),it};
                })-matrix[matrix[i][k]].begin();
                if(loc!=sz(matrix[matrix[i][k]])&&matrix[matrix[i][k]][loc]==matrix[i][j]){
                    ans=(ans+(ll(sz(matrix[i])-2)*ll(sz(matrix[matrix[i][j]])-2)%mod))%mod;
                    ans=(ans+(ll(sz(matrix[i])-2)*ll(sz(matrix[matrix[i][k]])-2)%mod))%mod;
                    ans=(ans+(ll(sz(matrix[matrix[i][k]])-2)*ll(sz(matrix[matrix[i][j]])-2)%mod))%mod;
                    tri[matrix[i][k]][loc]++;
                    tri[i][j]++;
                    tri[i][k]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<rptr[i];j++)ans=(ans-(tri[i][j]*(tri[i][j]-1)%mod)+mod)%mod;
    }
    printf("%lli\n",ans);
    return 0;
}