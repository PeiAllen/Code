#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
pair<int,pii> dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second.first<dsu[bp].second.first)swap(ap,bp);
    dsu[ap].second.first+=dsu[bp].second.first;
    dsu[ap].second.second+=dsu[bp].second.second;
    dsu[bp].first=ap;
    return true;
}
vector<vector<int>> grid;
vector<pair<int,pii>> edges;
map<int,vector<int>> nodes;
int xc[2]={-1,0};
int yc[2]={0,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("exploreation_chapter_1_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int r,c,a;
        cin>>r>>c;
        grid=vector<vector<int>>(r,vector<int>(c));
        edges=vector<pair<int,pii>>();
        nodes=map<int,vector<int>>();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dsu[i*c+j]={i*c+j,{1,0}};
                cin>>grid[i][j];
                for(int k=0;k<2;k++){
                    pii nx={i+xc[k],j+yc[k]};
                    if(nx.first>=0&&nx.second>=0){
                        edges.push_back({min(grid[i][j],grid[nx.first][nx.second]),{i*c+j,nx.first*c+nx.second}});
                    }
                }
            }
        }
        sort(edges.begin(),edges.end());
        int gotten=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a;
                if(grid[i][j]>a)nodes[-a].push_back(i*c+j),gotten++;
            }
        }
        for(auto x:nodes){
            while(sz(edges)&&edges.back().first>-x.first){
                uni(edges.back().second.first,edges.back().second.second);
                edges.pop_back();
            }
            set<int> together;
            for(auto y:x.second){
                together.insert(find(y));
            }
            for(auto y:together){
                if(dsu[y].second.second>0)dsu[y].second.second--;
                dsu[y].second.second++;
            }
        }
        int ans=0;
        for(int i=0;i<r*c;i++){
            if(find(i)==i){
                ans+=dsu[i].second.second;
            }
        }
        printf("Case #%d: %d %d\n",cs,gotten,ans);
    }
    return 0;
}