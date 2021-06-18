#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int dp[(1<<16)];
int cnt[16][26];
int len[16];
int solve(int mask){
    if(__builtin_popcount(mask)==1)return len[__lg(mask)];
    if(dp[mask]!=-1)return dp[mask];
    int ans=0;
    for(int c=0;c<26;c++) {
        int am=INT_MAX;
        for (int i = 0; i < 16; i++) {
            if (mask & (1 << i)) {
                am=min(am,cnt[i][c]);
            }
        }
        ans+=am;
    }
    int best=INT_MAX;
    for(int sub=mask;sub;sub=(sub-1)&mask){
        if(sub!=mask)best=min(best,solve(sub)+solve(mask^sub)-ans);
    }
    return dp[mask]=best;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        len[i]=sz(a);
        for(auto x:a){
            cnt[i][x-'a']++;
        }
    }
    for(int i=0;i<(1<<n);i++)dp[i]=-1;
    printf("%d\n",1+solve((1<<n)-1));
    return 0;
}