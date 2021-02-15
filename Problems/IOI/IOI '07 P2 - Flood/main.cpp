#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
map<int,set<pii>> addhori;
map<int,set<int>> remhori;
map<int,vector<pii>> kept;
map<int,vector<pii>> combined;
map<int,vector<pair<pii,int>>> vert;
pii points[MAXN];
vector<pii> matrix[4*MAXN];
int dist[4*MAXN];
vector<pii> dsu;
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int newnode(){
    int cur=sz(dsu);
    dsu.push_back({cur,1});
    return cur;
}
void addedge(int a, int b, int ind){
    matrix[a].push_back({b,ind});
    matrix[b].push_back({a,ind});
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>points[i].first>>points[i].second;
    int w;
    cin>>w;
    int a,b;
    set<int> ls;
    for(int i=1;i<=w;i++){
        cin>>a>>b;
        if(points[a].first==points[b].first){
            ls.insert(points[a].first);
            vert[points[a].first].push_back({{min(points[a].second,points[b].second),max(points[a].second,points[b].second)},i});
        }
        else{
            ls.insert(min(points[a].first,points[b].first)),ls.insert(max(points[a].first,points[b].first));
            addhori[min(points[a].first,points[b].first)].insert({points[a].second,i});
            remhori[max(points[a].first,points[b].first)].insert(points[a].second);
        }
    }
    dsu.push_back({0,1});
    set<pii> cur={{-1,0}};
    for(int i:ls){
        auto &vertte=vert[i];
        auto &addhorite=addhori[i];
        auto &remhorite=remhori[i];
        auto &keptte=kept[i];
        auto &combinedte=combined[i];
        sort(vertte.begin(),vertte.end());
        vector<pii> te;
        int last=0;
        for(int j=1;j<sz(vertte);j++){
            if(vertte[j].first.first!=vertte[j-1].first.second){
                te.push_back({vertte[last].first.first,vertte[j-1].first.second});
                last=j;
            }
        }
        if(sz(vertte))te.push_back({vertte[last].first.first,vertte.back().first.second});
        combinedte=move(te);
        for(auto it=addhorite.begin();it!=addhorite.end();){
            pii x=*it;
            it++;
            if(remhorite.count(x.first)){
                keptte.push_back(x);
                remhorite.erase(x.first);
                addhorite.erase(x);
            }
        }
        for(auto x:addhorite){
           auto it=prev(cur.lower_bound({x.first,0}),1);
           int ind=newnode();
           uni(ind,it->second);
           cur.insert({x.first,ind});
        }
        for(auto x:combinedte){
            auto it=cur.lower_bound({x.first,0});
            auto stop=cur.lower_bound({x.second+1,0});
            if(stop!=it)stop=prev(stop,1);
            while(it!=stop){
                int loc=it->first;
                it++;
                cur.erase(prev(it,1));
                cur.insert({loc,newnode()});
            }
        }
        for(auto x:remhorite){
            auto it=cur.lower_bound({x,0});
            uni(it->second,prev(it,1)->second);
            cur.erase(it);
        }
    }
    cur={{-1,0}};
    int nodecnt=1;
    for(int i:ls){
        auto &vertte=vert[i];
        auto &addhorite=addhori[i];
        auto &remhorite=remhori[i];
        auto &keptte=kept[i];
        auto &combinedte=combined[i];
        vector<int> toleft;
        for(auto x:vertte){
            toleft.push_back(prev(cur.lower_bound({x.first.second,0}),1)->second);
        }
        for(auto x:addhorite){
            cur.insert({x.first,nodecnt++});
        }
        for(auto x:combinedte){
            auto it=cur.lower_bound({x.first,0});
            auto stop=cur.lower_bound({x.second+1,0});
            if(stop!=it)stop=prev(stop,1);
            while(it!=stop){
                int loc=it->first;
                it++;
                cur.erase(prev(it,1));
                cur.insert({loc,nodecnt++});
            }
        }
        for(auto x:remhorite){
            auto it=cur.lower_bound({x,0});
            cur.erase(it);
        }
        for(auto x:addhorite){
            auto it=cur.lower_bound({x.first,0});
            addedge(find(prev(it,1)->second),find(it->second),x.second);
        }
        for(auto x:keptte){
            auto it=cur.lower_bound({x.first,0});
            addedge(find(prev(it,1)->second),find(it->second),x.second);
        }
        for(int j=0;j<sz(vertte);j++){
            addedge(find(toleft[j]),find(prev(cur.lower_bound({vertte[j].first.second,0}),1)->second),vertte[j].second);
        }
    }
    dist[find(0)]=1;
    queue<int> q;
    q.push(find(0));
    set<int> ans;
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(auto x:matrix[cur]){
            if(!dist[x.first]){
                dist[x.first]=dist[cur]+1;
                q.push(x.first);
            }
        }
    }
    for(int i=0;i<sz(dsu);i++){
        if(find(i)==i){
            for(auto x:matrix[i]){
                if(dist[x.first]==dist[i])ans.insert(x.second);
            }
        }
    }
    printf("%d\n",sz(ans));
    for(auto x:ans)printf("%d\n",x);
    return 0;
}