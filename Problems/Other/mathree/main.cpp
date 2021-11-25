#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}


const int MN=(1<<13);
int dist[MN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    dist[1]=0;
    for(int i=0;i<MN;i++)dist[i]=INT_MAX;
    queue<int> q;
    q.push(1);
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        if(cur*2<MN&&dist[cur*2]>dist[cur]+1){
            dist[cur*2]=dist[cur]+1;
            q.push(cur*2);
        }
        if(cur-1>=1&&dist[cur-1]>dist[cur]+1){
            dist[cur-1]=dist[cur]+1;
            q.push(cur-1);
        }
    }
    int cnt=0;
    for(int i=1;i<MN;i++)if(dist[i]<=12)cnt++;
    printf("%d\n",cnt);
    return 0;
}