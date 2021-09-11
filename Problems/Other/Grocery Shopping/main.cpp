#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll arr[MN],sparse[20][MN];
int cnt[MN];
int n,q,k;
void ms(){
    for(int i=1;i<=19;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(ll a, ll b){
    if(a>b)return 0;
    int k=log2(b-a+1);
    return max(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)cin>>arr[i],sparse[0][i]=max(ll(0),arr[i]*arr[i-1]-arr[i]-arr[i-1]);
    for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
    ms();
    char a;
    for(int i=1;i<=n;i++)cin>>a,cnt[i]=cnt[i-1]+(a=='E');
    int l,r;
    while(q--){
        cin>>l>>r;
        if(cnt[r]-cnt[l-1]<k)printf("Not enough oils!\n");
        else printf("%lli\n",arr[r]-arr[l-1]+query(l+1,r));
    }
    return 0;
}