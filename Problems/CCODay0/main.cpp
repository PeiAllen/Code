#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<pii> adj[MN];
int st[MN],lst[MN],et;
vector<int> nodes;
set<int> partof[MN];
vector<int> edgecnt;
vector<vector<int>> comps;
set<int> cntnode[MN];
void dfs(int loc, int edgeind){
    lst[loc]=st[loc]=et++;
    nodes.push_back(loc);
    for(auto x:adj[loc]){
        if(x.second==edgeind)continue;
        if(!st[x.first]){
            dfs(x.first,x.second);
            if(lst[x.first]==st[loc]){
                comps.push_back({loc});
                partof[loc].insert(sz(comps)-1);
                while(1){
                    auto cur=nodes.back();
                    nodes.pop_back();
                    comps.back().push_back(cur);
                    partof[cur].insert(sz(comps)-1);
                    if(cur==x.first)break;
                }
            }
            lst[loc]=min(lst[loc],lst[x.first]);
        }
        else lst[loc]=min(lst[loc],st[x.first]);
    }
    if(lst[loc]==st[loc])nodes.pop_back();
}
int main(int argc, char *argv[]) {
    int s,t;
    cin>>s>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        nodes=vector<int>(),comps=vector<vector<int>>(),edgecnt=vector<int>();
        et=1;
        for(int i=1;i<=n;i++)partof[i]=set<int>(),st[i]=0,lst[i]=0,adj[i]=vector<pii>(),cntnode[i]=set<int>();
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
            cntnode[a].insert(b);
            cntnode[b].insert(a);
        }
        if(s==1){
            dfs(1,-1);
            bool work=false;
            for(int i=0;i<sz(comps);i++){
                int cnt=0;
                for(int j=0;j<sz(comps[i]);j++){
                    int am=0;
                    for(auto x:adj[comps[i][j]]){
                        if(partof[x.first].count(i))am++;
                    }
                    if(am>2)cnt++;
                }
                if(cnt>=2)work=true;
            }
            if(work)printf("YES\n");
            else printf("NO\n");
        }
        else if(s==2){
            dfs(1,-1);
            bool work=false;
            for(auto x:comps){
                if(sz(x)>=3)work=true;
            }
            if(work)printf("YES\n");
            else printf("NO\n");
        }
        else if(s==3){
            dfs(1,-1);
            bool work=false;
            for(auto x:comps){
                if(sz(x)>=4)work=true;
            }
            if(work)printf("YES\n");
            else printf("NO\n");
        }
        else if(s==4){
            bool work=false;
            for(int i=1;i<=n;i++){
                vector<int> nodes;
                for(auto x:adj[i]){
                    nodes.push_back(x.first);
                }
                sort(nodes.begin(),nodes.end()),nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
                if(sz(nodes)>=3)work=true;
            }
            if(work)printf("YES\n");
            else printf("NO\n");
        }
        else{
            dfs(1,-1);
            bool work=false;
            edgecnt.resize(sz(comps),0);
            for(int i=0;i<sz(comps);i++){
                int cnt=0;
                for(int j=0;j<sz(comps[i]);j++){
                    int am=0;
                    for(auto x:adj[comps[i][j]]){
                        if(partof[x.first].count(i))edgecnt[i]++;
                        else am++;
                    }
                    if(am)cnt++;
                }
                if(cnt>=2)work=true;
            }
            for(int i=0;i<sz(comps);i++){
                edgecnt[i]/=2;
                if(edgecnt[i]>sz(comps[i])&&sz(comps[i])>4)work=true;
                if(sz(comps[i])==4){
                    auto good=[&](int x, int y, int z){
                        if(cntnode[x].count(y)&&cntnode[x].count(z)&&cntnode[y].count(z))return true;
                        return false;
                    };
                    for(int j=0;j<4;j++){
                        if(good(comps[i][(j+1)%4],comps[i][(j+2)%4],comps[i][(j+3)%4])){
                            for(auto x:adj[comps[i][(j+1)%4]]){
                                if(!partof[x.first].count(i)){
                                    work=true;
                                }
                            }
                            for(auto x:adj[comps[i][(j+2)%4]]){
                                if(!partof[x.first].count(i)){
                                    work=true;
                                }
                            }
                            for(auto x:adj[comps[i][(j+3)%4]]){
                                if(!partof[x.first].count(i)){
                                    work=true;
                                }
                            }
                        }
                    }
                }
            }
            if(work)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}