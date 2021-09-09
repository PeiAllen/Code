#include "bits/stdc++.h"
#include "keys.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
struct dsu {
    pii t[MN];

    void reset(int n) {
        for (int i = 0; i <= n; i++)t[i] = {i, 1};
    }

    int find(int a) {
        if (t[a].first == a)return a;
        return t[a].first = find(t[a].first);
    }

    bool uni(int a, int b) {
        int ap = find(a), bp = find(b);
        if (ap == bp)return false;
        if (t[ap].second < t[bp].second)swap(ap, bp);
        t[bp].first = ap;
        t[ap].second += t[bp].second;
        return true;
    }
}cn,cc;
int parent[MN],n,m;
vector<int> totake[MN];
map<int,vector<int>> notkeyed[MN];
set<int> keys[MN];
priority_queue<pii> tocheck;
void merge(int a, int b){
    cn.uni(a,b);
    int par=cn.find(a);
    int ch=(a==par?b:a);
    parent[par]=-1;
    totake[par].insert(totake[par].end(),totake[ch].begin(),totake[ch].end());
    for(auto x:keys[ch]){
        keys[par].insert(x);
        if(notkeyed[par].count(x)){
            totake[par].insert(totake[par].end(),notkeyed[par][x].begin(),notkeyed[par][x].end());
            notkeyed[par].erase(x);
        }
    }
    for(auto x:notkeyed[ch]){
        if(keys[par].count(x.first))totake[par].insert(totake[par].end(),x.second.begin(),x.second.end());
        else notkeyed[par][x.first].insert(notkeyed[par][x.first].end(),x.second.begin(),x.second.end());
    }
}
vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c){
    n=sz(r),m=sz(u);
    for(int i=0;i<m;i++)notkeyed[u[i]][c[i]].push_back(v[i]),notkeyed[v[i]][c[i]].push_back(u[i]);
    vector<int> ans(n);
    cn.reset(n),cc.reset(n);
    for(int i=0;i<n;i++){
        parent[i]=-1;
        keys[i].insert(r[i]);
        if(notkeyed[i].count(r[i])){
            totake[i].insert(totake[i].end(),notkeyed[i][r[i]].begin(),notkeyed[i][r[i]].end());
            notkeyed[i].erase(r[i]);
        }
        tocheck.push({sz(totake[i]),i});
    }
    while(sz(tocheck)){
        auto cur=tocheck.top().second;
        tocheck.pop();
        cur=cn.find(cur);
        if(parent[cur]!=-1)continue;
        if(!sz(totake[cur]))continue;
        int oth=cn.find(totake[cur].back());
        totake[cur].pop_back();
        if(oth==cur){
            tocheck.push({sz(totake[cur]),cur});
            continue;
        }
        if(cc.find(oth)!=cc.find(cur)){
            parent[cur]=oth;
            cc.uni(oth,cur);
        }
        else{
            vector<int> route;
            while(oth!=cur){
                route.push_back(oth);
                oth=cn.find(parent[oth]);
            }
            while(sz(route)){
                merge(cur,route.back());
                cur=cn.find(cur);
                route.pop_back();
            }
            tocheck.push({sz(totake[cur]),cur});
        }
    }
    int misize=INT_MAX;
    for(int i=0;i<n;i++){
        if(cn.find(i)==i){
            if(parent[i]==-1){
                misize=min(misize,cn.t[i].second);
            }
        }
    }
    for(int i=0;i<n;i++)ans[i]=(cn.t[cn.find(i)].second==misize&&parent[cn.find(i)]==-1);
    return ans;
}

//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    int nn,mm;
//    cin>>nn>>mm;
//    vector<int> kkeys(nn),ledge(mm),redge(nn),cedge(nn);
//    for(int i=0;i<nn;i++){
//        cin>>kkeys[i];
//    }
//    for(int i=0;i<mm;i++){
//        cin>>ledge[i]>>redge[i]>>cedge[i];
//    }
//    auto te=find_reachable(kkeys,ledge,redge,cedge);
//    for(auto x:te)printf("%d ",x);
//    return 0;
//}