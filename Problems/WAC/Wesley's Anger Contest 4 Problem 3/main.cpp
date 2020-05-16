#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
typedef long double ld;
typedef pair<ld,ld> pld;
const int MAXN=16;
pair<pld,pld> squ[MAXN];
ld dp[(1<<15)][MAXN];
int n;
ld S;
pld pos(pld loc, pld v, ld time){
    return {loc.first+time*v.first,loc.second+time*v.second};
}
ld calc(pld cur, pld st, pld v){
    ld a=S*S-v.first*v.first-v.second*v.second;
    ld xd=st.first-cur.first;
    ld yd=st.second-cur.second;
    ld b=-(2*xd*v.first+2*yd*v.second);
    ld c=-(xd*xd+yd*yd);
    return (-b+sqrt(b*b-4*a*c))/(2*a);
}
ld go(int state, int cur){
    if(dp[state][cur]!=LLONG_MAX)return dp[state][cur];
    if(__builtin_popcount(state)==1)return dp[state][cur]=calc({0,0},squ[cur].first,squ[cur].second);
    int ns=state-(1<<cur);
    for(int i=0;i<n;i++){
        if(state&(1<<i)&&i!=cur){
            dp[state][cur]=min(dp[state][cur],go(ns,i)+calc(pos(squ[i].first,squ[i].second,go(ns,i)),pos(squ[cur].first,squ[cur].second,go(ns,i)),squ[cur].second));
        }
    }
    return dp[state][cur];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>S;
    for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)dp[i][j]=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>squ[i].first.first>>squ[i].first.second>>squ[i].second.first>>squ[i].second.second;
    }
    ld ans=LLONG_MAX;
    int fs=(1<<n)-1;
    for(int i=0;i<n;i++){
        ans=min(ans,go(fs,i));
    }
    printf("%.6Lf\n",ans);
    return 0;
}