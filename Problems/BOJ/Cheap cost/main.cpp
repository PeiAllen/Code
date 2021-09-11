#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=9;
unordered_map<string,int> dp[2];
string normalize(const string& a){
    string ans(sz(a),'0');
    map<char,char> cnt;
    for(int i=0;i<sz(a);i++){
        if(a[i]=='0')continue;
        if(!cnt.count(a[i])){
            char te=char(int('1')+sz(cnt));
            cnt[a[i]]=te;
        }
        ans[i]=cnt[a[i]];
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,cur=1;
    cin>>n>>m;
    dp[0][string(m,'0')]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            dp[cur]=unordered_map<string,int>();
            for(const auto& x:dp[!cur]){
                if(x.first[0]=='0'||int(x.first.find_last_of(x.first[0]))!=0){
                    string ne=normalize(x.first.substr(1)+"0");
                    if(dp[cur].count(ne))dp[cur][ne]=min(dp[cur][ne],x.second);
                    else dp[cur][ne]=x.second;
                }
                string ne=x.first.substr(1);
                if(x.first[0]=='0'&&(j==0||x.first.back()=='0'))ne.push_back('0'-1);
                else if(x.first[0]!='0'&&j!=0&&x.first.back()!='0'){
                    ne.push_back(x.first.back());
                    for(char &y:ne)if(y==x.first[0])y=x.first.back();
                }
                else ne.push_back(max(x.first[0],(j==0?'0':x.first.back())));
                ne=normalize(ne);
                if(dp[cur].count(ne))dp[cur][ne]=min(dp[cur][ne],x.second+a);
                else dp[cur][ne]=x.second+a;
            }
            for(const auto& x:dp[cur]){
                if(x.first.find('2')==string::npos){
                    ans=min(ans,x.second);
                }
            }
            cur=!cur;
        }
    }
    printf("%d\n",ans);
    return 0;
}