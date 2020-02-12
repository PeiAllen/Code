#include <bits/stdc++.h>
using namespace std;
template <typename T>
int sz(T &a){return (int)a.size();}
const int MAXN=2e3+1;
int dp[MAXN][MAXN];
int dist[MAXN][MAXN];
int to[MAXN][MAXN];
int done[MAXN];
pair<int,int> loc[MAXN];
int n;
vector<pair<int,int>> arr;
int go(int loc, int dis){
    int ind=(lower_bound(dist[loc],dist[loc]+n+1,dis)-dist[loc])-1;
    while(done[loc]<ind){
        dp[loc][done[loc]+1]=max(dp[loc][done[loc]],(to[loc][done[loc]+1]?go(to[loc][done[loc]+1],dist[loc][done[loc]+1]):0));
        done[loc]++;
    }
    return dp[loc][ind]+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>loc[i].first>>loc[i].second;
    }
    for(int i=1;i<=n;i++){
        arr.clear();
        for(int j=0;j<=n;j++){
            if(j!=i){
                arr.push_back({(loc[i].first-loc[j].first)*(loc[i].first-loc[j].first)+(loc[i].second-loc[j].second)*(loc[i].second-loc[j].second),j});
            }
        }
        sort(arr.begin(),arr.end());
        for(int j=0;j<sz(arr);j++){
            to[i][j+1]=arr[j].second;
            dist[i][j+1]=arr[j].first;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,go(i,(loc[i].first)*(loc[i].first)+(loc[i].second)*(loc[i].second)));
    }
    printf("%d\n",ans);
    return 0;
}