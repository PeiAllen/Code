#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2001;
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
char arr[MN][MN];
int am[MN];
int first[MN];
int n,m;
bool gone[MN][MN];
int num[MN];
bool simulate(vector<pii> tostart){
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)gone[i][j]=false,num[j]=0;
    queue<pii> q;
    for(auto x:tostart){
        gone[x.first][x.second]=true;
        q.push(x);
        num[x.second]++;
    }
    while(sz(q)){
        pii cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pii nx={xc[i]+cur.first,yc[i]+cur.second};
            if(nx.first>=1&&nx.first<=n&&nx.second>=1&&nx.second<=m){
                if(arr[nx.first][nx.second]=='#'&&!gone[nx.first][nx.second]){
                    gone[nx.first][nx.second]=true;
                    q.push(nx);
                    num[nx.second]++;
                }
            }
        }
        pii nx={cur.first+1,cur.second};
        if(nx.first>=1&&nx.first<=n&&nx.second>=1&&nx.second<=m&&!gone[nx.first][nx.second]){
            gone[nx.first][nx.second]=true;
            q.push(nx);
        }
    }
    for(int i=1;i<=m;i++)if(num[i]<am[i])return false;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    vector<int> inds;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        cin>>arr[i][j];
        if(arr[i][j]=='#'&&first[j]==0)first[j]=i,inds.push_back(j);
    }
    for(int i=1;i<=m;i++)cin>>am[i];
    int ans=INT_MAX;
    for(int i=0;i<(1<<sz(inds));i++){
        vector<pii> touch;
        for(int j=0;j<sz(inds);j++){
            if(i&(1<<j))touch.push_back({first[inds[j]],inds[j]});
        }
        if(simulate(touch)){
            ans=min(ans,__builtin_popcount(i));
        }
    }
    if(ans==INT_MAX)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}