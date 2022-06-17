#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=6001;
pii dp[MN][MN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)dp[i][i]={-1,-1};
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            dp[i][j]={-1,-1};
            if(s[i-1]==s[i]&&dp[i+2][j].first!=-1){
                dp[i][j]={0,0};
                continue;
            }
            if(len>=3&&s[i-1]==s[i]&&s[i]==s[i+1]&&dp[i+3][j].first!=-1){
                dp[i][j]={1,1};
                continue;
            }
            for(int a=i+2;a<=j;a++){
                if(s[a-1]==s[i]&&dp[i+1][a-1].first!=-1&&dp[a+1][j].first!=-1){
                    dp[i][j]={2,a};
                    break;
                }
                if(a+1<=j&&s[a]==s[a-1]&&s[a-1]==s[i]&&dp[i+1][a-1].first!=-1&&dp[a+2][j].first!=-1){
                    dp[i][j]={3,a};
                    break;
                }
            }
            if(dp[i][j].first==-1){
                if(){
                    for(int a=i+3;a<=j;a++){
                        if(s[a-1]==s[i]&&dp[i+1][a-1].first!=-1&&dp[a+1][j].first!=-1){
                            dp[i][j]={2,a};
                            break;
                        }
                        if(a+1<=j&&s[a]==s[a-1]&&s[a-1]==s[i]&&dp[i+1][a-1].first!=-1&&dp[a+2][j].first!=-1){
                            dp[i][j]={3,a};
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}