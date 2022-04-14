#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pll arr[MN];
ll dp[MN][2];
int t,n,k;
ll solve(vector<pll> a){
    int ptr1=0,ptr2=0;
    ll take[2]={0,LLONG_MAX};
    ll take2[2]={0,LLONG_MAX};
    for(int i=1;i<sz(a);i++){
        while(a[ptr1+1].A<a[i].A-k){
            ptr1++;
            take[ptr1%2]=min(take[ptr1%2],dp[ptr1][0]);
            take[(ptr1+1)%2]=min(take[(ptr1+1)%2],dp[ptr1][1]);
            take2[ptr1%2]=min(take2[ptr1%2],dp[ptr1][0]);
        }
        while(ptr2+1<i-2&&a[ptr2+1].A<a[i].A-k){
            ptr2++;
            take2[(ptr2+1)%2]=min(take2[(ptr2+1)%2],dp[ptr2][1]);
        }
        dp[i][0]=dp[i][1]=LLONG_MAX;
        if(take[(i-1)%2]!=LLONG_MAX)dp[i][0]=take[(i-1)%2]+a[i].B;
        if(i>=2&&i+1<sz(a)&&a[i+1].A-a[i-1].A<=k&&take2[i%2]!=LLONG_MAX)dp[i][1]=take2[i%2]+a[i].B;
    }
    ll ans=((sz(a)-1)%2==0?0:LLONG_MAX);
    for(int i=1;i<sz(a);i++){
        ans=min(ans,dp[i][(sz(a)-i+1)%2]);
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i].A>>arr[i].B;
        if(t==2)arr[i].B*=-1;
    }
    vector<pll> tosolve={{0,0}};
    ll ans=0;
    for(int i=1;i<=n;i++){
        tosolve.push_back(arr[i]);
        if(i==n||arr[i+1].A-arr[i].A>k){
            ans+=solve(tosolve);
            tosolve=vector<pll>();
            tosolve.push_back({0,0});
        }
    }
    printf("%lli\n",(t==2?-1:1)*ans);
    return 0;
}