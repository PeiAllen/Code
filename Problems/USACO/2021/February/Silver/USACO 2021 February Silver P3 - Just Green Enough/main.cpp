#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
int arr[MN][MN];
int psa[2][MN][MN];
int query(int t, int xl, int xh, int yl, int yh){
    return psa[t][xh][yh]-psa[t][xh][yl-1]-psa[t][xl-1][yh]+psa[t][xl-1][yl-1];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            psa[0][i][j]=psa[0][i-1][j]+psa[0][i][j-1]-psa[0][i-1][j-1];
            psa[1][i][j]=psa[1][i-1][j]+psa[1][i][j-1]-psa[1][i-1][j-1];
            if(arr[i][j]==100)psa[0][i][j]++;
            else if(arr[i][j]<100)psa[1][i][j]++;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int ptr[2]={0,0};
            for(int k=j;k>=1;k--){
                for(int t=0;t<2;t++){
                    while(ptr[t]+1<=i&&query(t,ptr[t]+1,i,k,j)>=1)ptr[t]++;
                }
                ans+=max(0,ptr[0]-ptr[1]);
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}