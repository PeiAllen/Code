#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int n;
int loc[MN];
vector<int> parent;
vector<pii> position;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k,a,b;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        loc[b]=a;
    }
    vector<pii> paths;
    paths.push_back({1,0});
    parent.push_back(-1),position.push_back({1,1});
    for(int i=2;i<=n&&sz(paths);i++){
        if(loc[i]==0)paths.resize(1);
        else{
            if(sz(paths)==1){
                if(loc[i]==paths[0].first){
                    if(loc[i]==n||loc[i-1]==loc[i]+1)paths.resize(0);
                    else{
                        int te=sz(parent);
                        parent.push_back(paths[0].second);
                        parent.push_back(te);
                        position.push_back({paths[0].first+1,i-1});
                        position.push_back({paths[0].first+1,i-1});
                        paths[0].first++,paths[0].second=sz(parent)-1;
                    }
                }
                else if(loc[i]>paths[0].first&&loc[i]<n&&!(loc[i-1]>paths[0].first&&loc[i-1]<=loc[i]+1)){
                    int cur=paths[0].second,up=sz(parent)+1,con=sz(parent)+2;
                    parent.push_back(cur),parent.push_back(up-1),parent.push_back(cur);
                    position.push_back({loc[i]+1,i-1});
                    position.push_back({loc[i]+1,i-1});
                    position.push_back(position[cur]);
                    paths.push_back({loc[i]+1,up});
                    paths[0].second=con;
                }
            }
            else{
                if(loc[i]==0||loc[i]<paths[0].first)paths.resize(1);
                else if(loc[i]>=paths[1].first){
                    if(loc[i]==n)paths.resize(1);
                    else {
                        int te=sz(parent);
                        parent.push_back(paths[1].second);
                        parent.push_back(te);
                        position.push_back({loc[i]+1,i-1});
                        position.push_back({loc[i]+1,i-1});
                        paths[1].first=loc[i]+1,paths[1].second=sz(parent)-1;
                    }
                }
                else{//paths[0].first<=loc[i]<paths[1].first
                    if(loc[i-1]>loc[i]+1){
                        paths.resize(1);
                        int cur=paths[0].second,up=sz(parent)+1,con=sz(parent)+2;
                        parent.push_back(cur),parent.push_back(up-1),parent.push_back(cur);
                        position.push_back({loc[i]+1,i-1});
                        position.push_back({loc[i]+1,i-1});
                        position.push_back(position[cur]);
                        paths.push_back({loc[i]+1,up});
                        paths[0].second=con;
                    }
                    else {
                        if(loc[i]==paths[0].first){
                            paths[0]=paths[1],paths.resize(1);
                        }
                    }
                }
            }
        }
        for(auto x:paths)position[x.second].second++;
    }
    if(loc[n]&&sz(paths)==2){
        paths[0]=paths[1],paths.resize(1);
    }
    if(sz(paths)==0||paths[0].first<loc[n]){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int cur=paths[0].second;
    vector<pii> path={{n,n}};
    while(cur!=-1)path.push_back(position[cur]),cur=parent[cur];
    path.push_back({1,1});
    reverse(path.begin(),path.end());
    for(int i=1;i<sz(path);i++){
        printf("%s",string(path[i].first-path[i-1].first+path[i].second-path[i-1].second,(path[i].first!=path[i-1].first?'U':'R')).c_str());
    }
    printf("\n");
    return 0;
}