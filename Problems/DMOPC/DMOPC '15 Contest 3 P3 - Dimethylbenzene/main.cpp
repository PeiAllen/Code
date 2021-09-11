#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pii arr[21];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=0;i<(1<<m);i++){
        if(__builtin_popcount(i)==6){
            vector<pii> edges;
            for(int j=0;j<m;j++){
                if(i&(1<<j))edges.push_back(arr[j]);
            }
            pii cur=edges[0];
            int front=cur.first;
            bool work=true;
            for(int e=2;e<=6&&work;e++){
                vector<pii> ne;
                for(auto x:edges){
                    if(x!=cur&&x!=edges[0]&&(x.first==cur.second||x.second==cur.second)){
                        ne.push_back(x);
                        if(x.second==cur.second)swap(ne.back().first,ne.back().second);
                    }
                }
                if(sz(ne)!=1)work=false;
                else cur=ne[0];
            }
            if(work&&(cur.second==front||cur.first==front)){
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}