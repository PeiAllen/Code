#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int dp[90001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int tot=0;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<k){
            printf("Impossible\n");
            return 0;
        }
        tot+=a;
    }
    dp[0]=0;
    for(int i=1;i<=90000;i++)dp[i]=-1;
    for(int i=0;i<m;i++){
        cin>>a;
        for(int j=90000;j>=a;j--){
            if(dp[j-a]>=0)dp[j]=max(dp[j],dp[j-a]+min(n,a));
        }
    }
    for(int i=tot;i<=90000;i++){
        if(dp[i]>=n*k){
            printf("%d\n",i-tot);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}