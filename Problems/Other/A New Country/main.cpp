#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e4+1;
vector<pii> matrix[MAXN];
int ind[MAXN],lind[MAXN];
stack<int> st;
vector<vector<int>> comps;
vector<pii> matrix2[MAXN];
int cind=1;
bool inst[MAXN];
int pind[MAXN];
int province[MAXN];
int dist[MAXN][201];
bool gone[(int)1e3+1];
pair<int,pii> distp[(int)1e3+1][(int)1e3+1];
vector<int> stcities[(int)1e3+1];
void dfs(int loc){
    ind[loc]=cind,lind[loc]=cind++;
    st.push(loc);
    inst[loc]=true;
    for(auto x:matrix[loc]){
        if(!ind[x.first]){
            dfs(x.first);
            lind[loc]=min(lind[loc],lind[x.first]);
        }
        else if(inst[x.first])lind[loc]=min(lind[loc],ind[x.first]);
    }
    if(lind[loc]==ind[loc]){
        comps.push_back({});
        int curind=1;
        while(true){
            int cur=st.top();
            st.pop();
            inst[cur]=false;
            pind[cur]=curind++;
            province[cur]=sz(comps)-1;
            comps.back().push_back(cur);
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,que;
    cin>>n>>m>>que;
    int a,b,p;
    for(int i=0;i<m;i++){
        cin>>a>>b>>p;
        matrix[a].push_back({b,p});
    }
    for(int i=1;i<=n;i++)if(!ind[i])dfs(i);
    for(int i=1;i<=n;i++){
        bool edgecity=false;
        for(auto x:matrix[i]){
            if(province[x.first]!=province[i]){
                matrix2[x.first].push_back({i,x.second}),matrix2[i].push_back(x);
                stcities[province[x.first]].push_back(x.first);
                edgecity=true;
            }
        }
        for(int j=0;j<=200;j++)dist[i][j]=INT_MAX;
        if(edgecity)stcities[province[i]].push_back(i);
        priority_queue<pii,vector<pii>,greater<>> q;
        q.push({0,i});
        dist[i][pind[i]]=0;
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            if(dist[i][pind[cur.second]]>=cur.first){
                for(auto x:matrix[cur.second]){
                    if(province[x.first]==province[i]&&dist[i][pind[x.first]]>cur.first+x.second){
                        dist[i][pind[x.first]]=cur.first+x.second;
                        q.push({dist[i][pind[x.first]],x.first});
                    }
                }
            }
        }
    }
    for(int i=0;i<sz(comps);i++) {
        sort(stcities[i].begin(),stcities[i].end());
        stcities[i].erase(unique(stcities[i].begin(),stcities[i].end()),stcities[i].end());
    }
    for(int i=0;i<sz(comps);i++){
        for(int j=0;j<sz(comps);j++)gone[j]=false;
        gone[i]=true;
        for(auto startcity:stcities[i]){
            queue<pii> q;
            for(auto x:matrix2[startcity]){
                q.push({x.first,x.second});
                distp[i][province[x.first]]={x.second,{startcity,x.first}};
                gone[province[x.first]]=true;
            }
            while(sz(q)){
                auto cur=q.front();
                q.pop();
                for(auto y:stcities[province[cur.first]]){
                    for(auto x:matrix2[y]){
                        if(!gone[province[x.first]]){
                            gone[province[x.first]]=true;
                            distp[i][province[x.first]]={cur.second+dist[cur.first][pind[y]]+x.second,{startcity,x.first}};
                            q.push({x.first,distp[i][province[x.first]].first});
                        }
                    }
                }
            }
        }
    }
    while(que--){
        cin>>a>>b;
        if(province[a]==province[b])printf("%d\n",dist[a][pind[b]]);
        else printf("%d\n",distp[province[a]][province[b]].first+dist[a][pind[distp[province[a]][province[b]].second.first]]+dist[distp[province[a]][province[b]].second.second][pind[b]]);
    }
    return 0;
}