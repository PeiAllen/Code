#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli mod=1e6;
lli fix(lli a){
    while(a<0)a+=mod;
    return a%mod;
}
lli fastpow(lli a, lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
pii loc[MAXN];
lli solve(int cur, int peg){
    if(cur<=0)return 0;
    if(loc[cur].first==peg)return solve(cur-1,peg);
    return fix(solve(cur-1,3-loc[cur].first-peg)+fastpow(2,cur-1));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int in;
    for(int i=0;i<a;i++){
        cin>>in;
        loc[in]={0,i};
    }
    for(int i=0;i<b;i++){
        cin>>in;
        loc[in]={1,i};
    }
    for(int i=0;i<c;i++){
        cin>>in;
        loc[in]={2,i};
    }
    printf("%d\n%lli\n",loc[n].first+1,solve(n-1,loc[n].first));
    return 0;
}