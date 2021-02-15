#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
vector<int> comp[MN][2];
vector<int> matrix[MN];
bool dp[MN][MN];
int dir[MN];
int cind;
int n,m;
bool dfs(int loc, int col){
    comp[cind][col-1].push_back(loc),dir[loc]=col;
    for(auto x:matrix[loc]){
        if(!dir[x]){
            if(!dfs(x,(col==1?2:1)))return false;
        }
        else if(dir[x]==col)return false;
    }
    return true;
}
string getans(int loc){
    string ans(n,0);
    for(int i=cind-1;i>=0;i--){
        if(loc-sz(comp[cind-i][0])>=0&&dp[i][loc-sz(comp[cind-i][0])]){
            for(auto x:comp[cind-i][0])ans[x-1]='1';
            for(auto x:comp[cind-i][1])ans[x-1]='2';
            loc-=sz(comp[cind-i][0]);
        }
        else{
            for(auto x:comp[cind-i][0])ans[x-1]='2';
            for(auto x:comp[cind-i][1])ans[x-1]='1';
            loc-=sz(comp[cind-i][1]);
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)cin>>a>>b,matrix[a].push_back(b),matrix[b].push_back(a);
    for(int i=1;i<=n;i++){
        if(!dir[i]){
            cind++;
            if(!dfs(i,1)){
                printf("-1\n");
                return 0;
            }
        }
    }
    dp[0][0]=true;
    for(int i=1;i<=cind;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=(j-sz(comp[cind-i+1][0])>=0?dp[i-1][j-sz(comp[cind-i+1][0])]:false)|(j-sz(comp[cind-i+1][1])>=0?dp[i-1][j-sz(comp[cind-i+1][1])]:false);
        }
    }
    string ans;
    for(int i=n/2;;i--){
        if(dp[cind][i]){
            ans=getans(i);
            break;
        }
    }
    for(int i=(n+1)/2;;i++){
        if(dp[cind][i]){
            ans=min(ans,getans(i));
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}