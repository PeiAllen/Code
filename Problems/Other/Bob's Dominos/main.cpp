#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=18;
const int mod=1e9+7;
int dp[2][MN*MN][(1<<18)];
int arr[MN][MN];
int n,m;
int solve(){
    for(int i=0;i<n;i++){

    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[j][i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[j][i]==1)printf("0%c"," \n"[j==m-1]);
            else{
                arr[j][i]=1;
                printf("%d%c",solve()," \n"[j==m-1]);
                arr[j][i]=0;
            }
        }
    }
    return 0;
}