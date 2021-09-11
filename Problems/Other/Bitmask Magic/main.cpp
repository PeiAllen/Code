#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
pii dist[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q,l,r;
    cin>>q>>l>>r;
    for(int i=l;i<=r;i++){
        queue<pii> q;
        q.push({i,0});
        dist[i]={0,i};
        while(sz(q)){
            pii cur=q.front();
            q.pop();
            int le=0;
            int tot=cur.first;
            for(int j=0;j<31-__builtin_clz(cur.first);j++){
                tot-=cur.first&(1<<j);
                int ne=(tot>>1)+le;
                if(dist[ne].second==0){
                    dist[ne]={cur.second+1,i};
                    q.push({ne,cur.second+1});
                }
                le+=cur.first&(1<<j);
            }
            if(31-__builtin_clz(cur.first)-1==31-__builtin_clz(le)&&dist[le].second==0){
                dist[le]={cur.second+1,i};
                q.push({le,cur.second+1});
            }
        }
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        if(dist[a].second==0||dist[a].second>a+b)printf("-1\n");
        else printf("%d\n",dist[a].first);
    }
    return 0;
}