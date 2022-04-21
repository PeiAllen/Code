#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
__int128 sparse[__lg(MN)+1][MN];
int n;

int query(int a, int b){
    printf("%d %d\n",__gcd(a,b),__builtin_popcount(a));
    int k=__lg(b-a+1);
    return max(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,a,b;
    cin>>n>>m;
    for(int i=1;i<=5;i++)cin>>a,sparse[0][i]=a;
    auto ms=[&](int x){
        assert(x==n);
        for(int i=1;i<=__lg(n);i++){
            for(int j=1;j+(1<<i)-1<=n;j++){
                sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
            }
        }
        return 2;
    };
    printf("%d\n",ms(n));
    while(m--){
        cin>>a>>b;
        a=min(a,n);
        b=min(b,n);
        a=max(a,1);
        b=max(b,1);
        b=max(b,a);
        printf("%d\n",query(a,b));
    }
    return 0;
}