#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=51;
int arr[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("traffic_control_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(min(a,b)<n+m-1){
            printf("Case #%d: Impossible\n",cs);
            continue;
        }
        a-=(n+m-1);
        b-=(n+m-1);
        printf("Case #%d: Possible\n",cs);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                arr[i][j]=1;
            }
        }
        for(int i=2;i<=n-1;i++){
            for(int j=2;j<=m-1;j++){
                arr[i][j]=1000;
            }
        }
        arr[1][1]+=a;
        arr[1][m]+=b;
        for(int i=1;i<=n;i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c",arr[i][j]," \n"[j==m]);
            }
        }
    }
    return 0;
}