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
    int n,m,k;
    cin>>n>>m>>k;
    int r[m][2],l[m],p[k];
    for(int i=0;i<m;i++){
        cin>>r[i][0]>>r[i][1]>>l[i];
    }
    for(int i=0;i<k;i++){
        cin>>p[i];
    }
    printf("%d\n",travel_plan(n,m,r,l,k,p));
    return 0;
}