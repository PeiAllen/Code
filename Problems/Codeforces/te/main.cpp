#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[503];
int dp[503][503];
int work(int a, int b){
    if(a==b)return arr[a];
    if(dp[a][b]!=-1)return dp[a][b];
    for(int i=a;i<b;i++){
        int l=work(a,i);
        int r=work(i+1,b);
        if(l&&r&&l==r)return dp[a][b]=l+1;
    }
    return dp[a][b]=0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int ans=0;
    while(l!=n){
        for(int i=n-1;i>=l;i--){
            printf("%d %d\n",l,i);
            if(work(l,i)){
                l=i+1,ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}