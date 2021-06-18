#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2001;
ll psa[2][MN][MN];
ll arr[MN][MN];
ll k;
int n,m;
bool work(int pre, int suf){
    if(suf<0)return false;
    int lx=1,rx=n,ly=1,ry=m;
    while(lx<=rx){
        if(psa[0][lx][ry]-psa[0][lx][ly-1]<=k)lx++;
        else if(psa[0][rx][ry]-psa[0][rx][ly-1]<=k)rx--;
        else if(ly+1<=1+pre&&psa[1][ly][rx]-psa[1][ly][lx-1]<=k)ly++;
        else if(ry-1>=m-suf&&psa[1][ry][rx]-psa[1][ry][lx-1]<=k)ry--;
        else break;
    }
    if(lx>rx)return true;
    return false;
}
int solve(){
    int suf=m-1,ans=n+m;
    for(int pre=0;pre<=m-1;pre++){
        while(pre+suf>=m||work(pre,suf))suf--;
        ans=min(ans,pre+suf+1+n);
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>k>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psa[0][i][j]=psa[0][i][j-1]+arr[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            psa[1][i][j]=psa[1][i][j-1]+arr[j-1][i-1];
        }
    }
    int ans=solve();
    swap(n,m);
    swap(psa[0],psa[1]);
    ans=min(ans,solve());
    printf("%d\n",ans);
    return 0;
}