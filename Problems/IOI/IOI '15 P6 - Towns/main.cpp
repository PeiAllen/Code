#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<int,int>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=111;
vector<pii> adj[MN];
void addedge(int a, int b, int c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
int rdist[MN];
void dfs(int loc, int parent, int w){
    if(parent==-1)rdist[loc]=0;
    else rdist[loc]=rdist[parent]+w;
    for(auto x:adj[loc])if(x.first!=parent)dfs(x.first,loc,x.second);
}
int getDistance(int i, int j){
    dfs(i,-1,0);
    return rdist[j];
}
int hubDistance(int N, int sub){
    vector<vector<int>> dist(2,vector<int>(N));
    vector<int> torep(N);
    for(int i=1;i<N;i++)dist[0][i]=getDistance(0,i);
    int diaside1=max_element(dist[0].begin(),dist[0].end())-dist[0].begin();
    for(int i=0;i<N;i++)if(i!=diaside1)dist[1][i]=getDistance(diaside1,i);
    map<int,vector<int>> nodes;
    map<int,int> madist;
    for(int i=0;i<N;i++){
        int x=(dist[0][i]+dist[1][i]-dist[0][diaside1])/2;
        torep[i]=x;
        madist[dist[1][i]-x]=max({madist[dist[1][i]-x],x});
        nodes[dist[1][i]-x].push_back(i);
    }
    map<int,int> pre,suf;
    for(auto x:madist){
        int dis=x.second;
        if(sz(pre))dis=max(dis,pre.rbegin()->second+x.first-pre.rbegin()->first);
        pre[x.first]=dis;
    }
    for(auto it=madist.rbegin();it!=madist.rend();it++){
        int dis=it->second;
        if(sz(suf))dis=max(dis,suf.begin()->second+suf.begin()->first-it->first);
        suf[it->first]=dis;
    }
    for(auto &&x:madist)x.second=max({x.second,pre[x.first],suf[x.first]});
    int bestdist=INT_MAX;
    vector<int> center;
    for(auto x:madist){
        if(x.second<bestdist){
            bestdist=x.second;
            center=vector<int>();
        }
        if(x.second==bestdist)center.push_back(x.first);
    }
    bool bal=false;
    for(auto node:center){
        int leftcnt=0,rightcnt=0,oncnt=sz(nodes[node]);
        for(auto x:nodes){
            if(x.first<node)leftcnt+=sz(x.second);
            else if(x.first>node)rightcnt+=sz(x.second);
        }
        if(leftcnt>N/2||rightcnt>N/2)continue;
        if(oncnt<=N/2){
            bal=true;
            break;
        }
        vector<pii> trashed;
        vector<pair<pii,int>> contest[2];
        int cur=0;
        contest[0]=vector<pair<pii,int>>(),contest[1]=vector<pair<pii,int>>();
        for(auto x:nodes[node])contest[0].push_back({{x,1},1});
        while(sz(contest[cur])>=2){
            contest[!cur]=vector<pair<pii,int>>();
            for(int i=0;i<sz(contest[cur]);i+=2){
                if(i+1==sz(contest[cur]))contest[!cur].push_back(contest[cur][i]);
                else{
                    if(getDistance(contest[cur][i].first.first,contest[cur][i+1].first.first)==torep[contest[cur][i].first.first]+torep[contest[cur][i+1].first.first]){
                        if(contest[cur][i].first.second>contest[cur][i+1].first.second){
                            trashed.push_back({contest[cur][i+1].first.first,contest[cur][i+1].second});
                            contest[!cur].push_back({{contest[cur][i].first.first,contest[cur][i].first.second-contest[cur][i+1].first.second},contest[cur][i].second});
                        }
                        else if(contest[cur][i+1].first.second>contest[cur][i].first.second){
                            trashed.push_back({contest[cur][i].first.first,contest[cur][i].second});
                            contest[!cur].push_back({{contest[cur][i+1].first.first,contest[cur][i+1].first.second-contest[cur][i].first.second},contest[cur][i+1].second});
                        }
                        else trashed.push_back({contest[cur][i].first.first,contest[cur][i].second}),trashed.push_back({contest[cur][i+1].first.first,contest[cur][i+1].second});
                    }
                    else contest[!cur].push_back({{contest[cur][i].first.first,contest[cur][i].first.second+contest[cur][i+1].first.second},contest[cur][i].second+contest[cur][i+1].second});
                }
            }
            cur=!cur;
        }
        if(sz(contest[cur])==0){
            bal=true;
            break;
        }
        int am=contest[cur][0].second;
        int mnode=contest[cur][0].first.first;
        for(auto x:trashed)if(getDistance(mnode,x.first)!=torep[mnode]+torep[x.first])am+=x.second;
        if(am<=N/2){
            bal=true;
            break;
        }
    }
    return bestdist*(bal?1:-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    addedge(0,11,6);
    addedge(1,11,11);
    addedge(10,11,5);
    addedge(12,11,1);
    addedge(12,13,6);
    addedge(12,15,4);
    addedge(12,14,1);
    addedge(14,16,5);
    addedge(14,17,2);
    addedge(15,9,9);
    addedge(15,8,12);
    addedge(16,7,3);
    addedge(16,6,7);
    addedge(17,5,2);
    addedge(17,4,7);
    addedge(13,2,5);
    addedge(13,3,7);
    printf("%d\n",hubDistance(11,0));
    return 0;
}