#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
vector<ll> dists[MAXN];
int cnt[MAXN];
vector<pair<int,ll>> matrix[MAXN];
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    for(int i=0;i<M;i++){
        matrix[R[i][0]].push_back({R[i][1],L[i]});
        matrix[R[i][1]].push_back({R[i][0],L[i]});
    }
    for(int i=0;i<K;i++){
        dists[P[i]].push_back(0);
        dists[P[i]].push_back(0);
        q.push({0,P[i]});
        q.push({0,P[i]});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cnt[cur.second]==0)assert(cur.first==dists[cur.second][cnt[cur.second]]),cnt[cur.second]++;
        else if(cnt[cur.second]==1){
            assert(cur.first==dists[cur.second][cnt[cur.second]]);
            cnt[cur.second]++;
            if(cur.second==0)return cur.first;
            for(auto x:matrix[cur.second]){
                if(sz(dists[x.first])<2){
                    dists[x.first].push_back(cur.first+x.second);
                    sort(dists[x.first].begin(),dists[x.first].end());
                    q.push({cur.first+x.second,x.first});
                }
                else if(cur.first+x.second<dists[x.first].back()){
                    dists[x.first].pop_back();
                    dists[x.first].push_back(cur.first+x.second);
                    sort(dists[x.first].begin(),dists[x.first].end());
                    q.push({cur.first+x.second,x.first});
                }
            }
        }
    }
    assert(0);
    return 0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    int r[4][2]={{0,1},{0,2},{3,2},{2,4}};
//    int l[4]={2,3,1,4};
//    int p[3]={1,3,4};
//    travel_plan(5,4,r,l,3,p);
//    int r[7][2]={{0,2},{0,3},{3,2},{2,1},{0,1},{0,4},{3,4}};
//    int l[7]={4,3,2,10,100,7,9};
//    int p[2]={1,3};
//    printf("%d\n",travel_plan(5,7,r,l,2,p));
    return 0;
}