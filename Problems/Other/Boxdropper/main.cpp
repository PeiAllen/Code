#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pair<pii,pii> boxes[501];
double dist[501][501],edgedist[501][501];
double getdist(int a, int b){
    int outerlength=max(boxes[a].second.first,boxes[b].second.first)-min(boxes[a].first.first,boxes[b].first.first),outerwidth=max(boxes[a].second.second,boxes[b].second.second)-min(boxes[a].first.second,boxes[b].first.second);
    ll innerlength=max(0,outerlength-(boxes[a].second.first-boxes[a].first.first)-(boxes[b].second.first-boxes[b].first.first)),innerwidth=max(0,outerwidth-(boxes[a].second.second-boxes[a].first.second)-(boxes[b].second.second-boxes[b].first.second));
    return sqrtl(innerlength*innerlength+innerwidth*innerwidth);
}
int main(){
    char in;
    int a,b;
    int boxam=0;
    while(scanf(" %c", &in)!=EOF){
        if(in=='B'){
            scanf(" %d %d %d %d", &boxes[boxam].first.first, &boxes[boxam].first.second, &boxes[boxam].second.first, &boxes[boxam].second.second);
            for(int i=0;i<boxam;i++)edgedist[i][boxam]=edgedist[boxam][i]=getdist(i,boxam),dist[i][boxam]=INT_MAX,dist[boxam][i]=INT_MAX;
            priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>> q;
            dist[boxam][boxam]=0;
            q.push({0,boxam});
            while(sz(q)){
                auto cur=q.top();
                q.pop();
                if(dist[boxam][cur.second]>=cur.first){
                    for(int i=0;i<boxam;i++){
                        if(cur.first+edgedist[cur.second][i]<dist[boxam][i]){
                            dist[boxam][i]=cur.first+edgedist[cur.second][i];
                            q.push({dist[boxam][i],i});
                        }
                    }
                }
            }
            for(int i=0;i<boxam;i++){
                dist[i][boxam]=dist[boxam][i];
                for(int j=0;j<i;j++){
                    if(dist[i][j]>dist[i][boxam]+dist[boxam][j]){
                        dist[i][j]=dist[j][i]=dist[i][boxam]+dist[boxam][j];
                    }
                }
            }
            boxam++;
        }
        else{
            scanf(" %d %d",&a,&b);
            printf("%.3f\n",dist[a-1][b-1]);
        }
    }
    return 0;
}