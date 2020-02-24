#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli dist[81][81];
pll dist2[81][81];
pll best[81];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>dist[i][j];
        dist[i][i]=1e10;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)best[j]={(lli)1e10,k};
        best[i]={0,0};
        priority_queue<pair<lli,pii>,vector<pair<lli,pii>>,greater<pair<lli,pii>>> q;
        q.push({0,{i,0}});
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            if(cur.second.second==k)continue;
            if(best[cur.second.first].first>=cur.first){
                for(int j=1;j<=n;j++){
                    lli ne=cur.first+dist[cur.second.first][j];
                    if(ne<best[j].first){
                        best[j]={ne,cur.second.second+1};
                        q.push({ne,{j,cur.second.second+1}});
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)dist2[i][j]=best[j];
    }
    lli ans=LLONG_MAX;
    for(int i=1;i<=n;i++){
       // for(int l=0;l<=k/2;l++){
        if(dist2[1][i].second +dist2[i][1].second==k){
            ans=min(ans,dist2[1][i].first +dist2[i][1].first);
        }
        else {
            for (int j = 1; j <= n; j++) {
                if (dist2[i][j].second + dist2[j][i].second != 0) {
                    //  if(j!=i) {
                    //     for (int l2 = 1; l2 <= (k - 2 * l) / 2; l2++) {
                    if ((k - (dist2[1][i].second + dist2[i][1].second)) % (dist2[i][j].second + dist2[j][i].second) ==
                        0) {
                        ans = min(ans,
                                  dist2[1][i].first + dist2[i][1].first + (dist2[i][j].first + dist2[j][i].first) *
                                                                          ((k -
                                                                            (dist2[1][i].second + dist2[i][1].second)) /
                                                                           (dist2[i][j].second + dist2[j][i].second)));
                    }
//                        if(dist2[1][i][l] +dist2[i][1][l] +(dist2[i][j][l]+dist2[j][i][l]) * (k - 2 * l) / (l2 * 2)==1)printf("%d %d %d %d\n",i,l,j,l2);
                    //    }

                    //  }
                }
            }
        }
        }

    assert(ans!=LLONG_MAX);
    printf("%lli\n",ans);
    return 0;
}