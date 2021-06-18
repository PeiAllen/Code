#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e4+1;
struct dsu{
    pii node[MN];
    vector<pair<pii,pair<pii,pii>>> his;
    void init(int n){
        for(int i=1;i<=n;i++)node[i]={i,1};
    }
    int find(int a){
        if(node[a].first==a)return a;
        return find(node[a].first);
    }
    bool uni(int a, int b){
        int ap=find(a),bp=find(b);
        his.push_back({{ap,bp},{node[ap],node[bp]}});
        if(ap==bp)return false;
        if(node[ap].second<node[bp].second)swap(ap,bp);
        node[ap].second+=node[bp].second;
        node[bp].first=ap;
        return true;
    }
    void undo(){
        node[his.back().first.first]=his.back().second.first;
        node[his.back().first.second]=his.back().second.second;
        his.pop_back();
    }
}graph;
int n,m,ans=INT_MAX;
vector<pair<int,pii>> aedges[MN],bedges[MN];
void cdq(int al, int ar, int bl, int br){//everything with <al and <=bl is added.
    int mid=(al+ar)/2;
    int cnt=0;
    for(int i=al;i<=mid;i++){
        for(auto x:aedges[i]){
            if(x.first<=bl){
                graph.uni(x.second.first,x.second.second);
                cnt++;
            }
        }
    }
    int opt=MN;
    for(int i=bl;i<=br;i++){
        if(graph.find(1)==graph.find(n)){
            opt=i;
            break;
        }
        if(i==br)break;
        for(auto x:bedges[i+1]){
            if(x.first<=mid){
                graph.uni(x.second.first,x.second.second);
                cnt++;
            }
        }
    }
    while(cnt--)graph.undo();
    cnt=0;
    if(al==ar){
        if(opt!=MN)ans=min(ans,opt+al);
        return;
    }
    if(opt!=MN) {
        for (int i = bl + 1; i <= opt; i++) {
            for (auto x:bedges[i]){
                if(x.first<al){
                    graph.uni(x.second.first,x.second.second);
                    cnt++;
                }
            }
        }
        cdq(al, mid, opt, br);
        while(cnt--)graph.undo();
        cnt=0;
    }
    for(int i=al;i<=mid;i++){
        for(auto x:aedges[i]){
            if(x.first<=bl){
                graph.uni(x.second.first,x.second.second);
                cnt++;
            }
        }
    }
    cdq(mid+1,ar,bl,min(opt,br));
    while(cnt--)graph.undo();
    cnt=0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int x,y,a,b;
    graph.init(n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>a>>b;
        aedges[a].push_back({b,{x,y}});
        bedges[b].push_back({a,{x,y}});
    }
    cdq(1,MN-1,1,MN-1);
    if(ans==INT_MAX)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}