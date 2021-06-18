#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int outdeg[MN];
vector<pair<pii,pii>> in[MN];
bool pruned[MN];
int te[MN],val[MN];
bool done[MN];
void pruneedge(const pair<pair<pii,pii>,int> &teedge){
    if(done[teedge.second])return;
    done[teedge.second]=true;
    pair<pii,pii> edge=teedge.first;
    te[edge.first.first]=min(te[edge.first.first],max(edge.second.first,val[edge.first.second]-edge.second.second));
    outdeg[edge.first.first]--;
    if(outdeg[edge.first.first]==0){
        val[edge.first.first]=te[edge.first.first];
        pruned[edge.first.first]=true;
        for(auto x:in[edge.first.first]){
            pruneedge({{{x.first.first,edge.first.first},x.second},x.first.second});
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b,c,d;
    cin>>n>>m;
    vector<pair<pair<pii,pii>,int>> edges;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        edges.push_back({{{a,b},{c,d}},i});
        outdeg[a]++;
        in[b].push_back({{a,i},{c,d}});
    }
    queue<int> prun;
    for(int i=1;i<=n;i++){
        te[i]=INT_MAX;
        if(outdeg[i]==0)prun.push(i);
    }
    while(sz(prun)){
        int cur=prun.front();
        prun.pop();
        pruned[cur]=true;
        for(auto x:in[cur]){
            outdeg[x.first.first]--;
            if(outdeg[x.first.first]==0){
                prun.push(x.first.first);
            }
        }
    }
    sort(edges.begin(),edges.end(),[&](const auto &lhs, const auto &rhs){
        return lhs.first.second.first>rhs.first.second.first;
    });
    for(auto x:edges){
        if(!pruned[x.first.first.second]){
            pruneedge(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(te[i]==INT_MAX)printf("-1%c"," \n"[i==n]);
        else printf("%d%c",val[i]," \n"[i==n]);
    }
    return 0;
}