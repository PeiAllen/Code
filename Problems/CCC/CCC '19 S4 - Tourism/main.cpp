
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=1e6+1;
const int MAXL=21;
lli n,k;
lli sparse[MAXL][MAXN];
lli arr[MAXN];
lli dp[MAXN];
lli day[MAXN];
int ip[MAXN];
int deq[MAXN];
int le,ri;
void ms(){
    for(int i=1;i<MAXL;i++){
        for(int j=1;j<=n-(1<<i)+1;j++){
            sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
lli query(int a, int b){
    int k=31-__builtin_clz(b-a+1);
    return max(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int interpoint(int a, int b){
    int lo=b,hi=n;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(day[mid]==day[b]||dp[a]+query(a+1,mid)>dp[b]+query(b+1,mid))lo=mid+1;
        else hi=mid;
    }
    if(lo>=a+k+1)return a+k+1;
    if(day[lo]==day[b]||dp[a]+query(a+1,lo)>dp[b]+query(b+1,lo))return n+1;
    return lo;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(lli i=1;i<=n;i++){
        cin>>arr[i];
        sparse[0][i]=arr[i];
        day[i]=(i+k-1)/k;
    }
    ms();
    dp[0]=0;
    deq[ri]=0;
    for(lli i=1;i<=n;i++){
        while(ri-le>=1&&(deq[le]<i-k||(day[deq[le+1]]!=day[i]&&dp[deq[le]]+query(deq[le]+1,i)<=dp[deq[le+1]]+query(deq[le+1]+1,i))))le++;
        dp[i]=dp[deq[le]]+query(deq[le]+1,i);
        ip[ri]=interpoint(deq[ri],i);
        while(ri-le>=1&&ip[ri-1]>=ip[ri])ri--,ip[ri]=interpoint(deq[ri],i);
        deq[++ri]=i;
    }
    printf("%lli",dp[n]);
    return 0;
}