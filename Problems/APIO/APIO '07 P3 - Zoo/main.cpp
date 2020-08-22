#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int dp[2][(1<<5)][(1<<5)];
vector<pair<vector<int>,vector<int>>> child[MAXN+5];
int n,c;
bool valid(int loc, int cur, int st){
    if(loc>=n){
        for(int i=n;i<=loc;i++){
            if(!!(st&(1<<(i-n)))!=!!(cur&(1<<(i-(loc-4)))))return false;
        }
    }
    else if(loc<=8){
        for(int i=loc-4;i<=4;i++){
            if(!!(st&(1<<i))!=!!(cur&(1<<(i-(loc-4)))))return false;
        }
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>c;
    int e,f,l;
    for(int i=0;i<c;i++){
        cin>>e>>f>>l;
        e--;
        vector<int> fe,lo;
        int a;
        while(f--){
            cin>>a;
            a--;
            fe.push_back(a);
        }
        while(l--){
            cin>>a;
            a--;
            lo.push_back(a);
        }
        child[e+4].push_back({fe,lo});
    }
    int dploc=0;
    for(int i=0;i<(1<<5);i++)for(int j=0;j<(1<<5);j++)dp[dploc][i][j]=INT_MIN;
    for(int i=0;i<(1<<5);i++){
        dp[dploc][i][i]=0;
        for(auto x:child[4]){
            bool hap=false;
            for(auto y:x.first)if(!(i&(1<<y)))hap=true;
            for(auto y:x.second)if(i&(1<<y))hap=true;
            if(hap)dp[dploc][i][i]++;
        }
    }
    dploc=!dploc;
    for(int i=5;i<=n+3;i++){
        for(int cur=0;cur<(1<<5);cur++){
            for(int st=0;st<(1<<5);st++){
                if(valid(i,cur,st)){
                    dp[dploc][cur][st]=max(dp[!dploc][((cur-(cur&(1<<4)))<<1)+1][st],dp[!dploc][(cur-(cur&(1<<4)))<<1][st]);
                    for(auto x:child[i]){
                        bool hap=false;
                        for(int y:x.first){
                            y-=(i-4);
                            if(y<0)y+=n;
                            if(!(cur&(1<<y)))hap=true;
                        }
                        for(int y:x.second){
                            y-=(i-4);
                            if(y<0)y+=n;
                            if(cur&(1<<y))hap=true;
                        }
                        if(hap)dp[dploc][cur][st]++;
                    }
                }
                else dp[dploc][cur][st]=INT_MIN;
            }
        }
        dploc=!dploc;
    }
    int best=0;
    for(int i=0;i<(1<<5);i++)for(int j=0;j<(1<<5);j++)best=max(best,dp[!dploc][i][j]);
    printf("%d\n",best);
    return 0;
}