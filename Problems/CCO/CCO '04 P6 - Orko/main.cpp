#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
map<char,int> conver={{'R',0},{'Y',1},{'G',2},{'B',3}};
int who[20];
int dp[(1<<20)][2];
int solve(int cards, int player){
    if(cards==0)return 0;
    if(dp[cards][player]!=-1)return dp[cards][player];
    int ans=0;
    for(int i=0;i<20;i++){
        if(who[i]==player&&(cards&(1<<i))){
            bool samecol=false;
            for(int j=0;j<20;j++){
                if(who[j]==!player&&(cards&(1<<j))){
                    if(j/5==i/5)samecol=true;
                }
            }
            int maenemy=0;
            for(int j=0;j<20;j++){
                if(who[j]==!player&&(cards&(1<<j))&&((j/5==i/5)==samecol)){
                    if(samecol&&j%5>i%5)maenemy=max(maenemy,1+solve(cards-(1<<i)-(1<<j),!player));
                    else maenemy=max(maenemy,(__builtin_popcount(cards)-2)/2-solve(cards-(1<<i)-(1<<j),player));
                }
            }
            ans=max(ans,__builtin_popcount(cards)/2-maenemy);
        }
    }
    return dp[cards][player]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    getline(cin,a);
    while(a[0]!='*'){
        for(int i=0;i<(1<<20);i++)for(int j=0;j<2;j++)dp[i][j]=-1;
        for(int i=0;i<20;i++)who[i]=1;
        for(int i=0;i<10;i++)who[conver[a[i*3]]*5+(a[i*3+1]-'1')]=0;
        printf("%d\n",solve((1<<20)-1,0));
        getline(cin,a);
    }
    return 0;
}