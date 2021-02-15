#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1,MAXM=2e5+10;
vector<pii> matrix[MAXN];
bool cent[MAXN];
int sts[MAXN];
int ans[MAXN];
int bit[MAXM];
vector<int> ups[MAXN];
int n,m,q;
void update(int loc, int val){
    for(;loc<=m;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int dfssz(int loc, int parent){
    sts[loc]=1;
    for(auto x:matrix[loc])if(x.first!=parent&&!cent[x.first])sts[loc]+=dfssz(x.first,loc);
    return sts[loc];
}
int getcent(int loc, int parent, int hs){
    for(auto x:matrix[loc])if(x.first!=parent&&!cent[x.first]&&sts[x.first]>hs)return getcent(x.first,loc,hs);
    return loc;
}
struct timecontainer {
    map<int,vector<int>> t;
    int size;
    timecontainer() { t = map<int,vector<int>>(), size = 0; }
    timecontainer(pii ins) { t = {{ins.first,{ins.second}}}, size = 1; }
};
map<int,vector<int>> storage[MAXN][2];
struct stlcont{
    vector<timecontainer> t;
    stlcont(){t=vector<timecontainer>();}
    int merge(int a, int b){
        if(t[a].size<t[b].size)swap(a,b);
        for(auto &&x:t[b].t){
            if(t[a].t.count(x.first)){
                if(sz(t[a].t[x.first])<sz(x.second))t[a].t[x.first].swap(x.second);
                t[a].t[x.first].insert(t[a].t[x.first].begin(),x.second.begin(),x.second.end());
            }
            else t[a].t.insert(x);
        }
        t[a].size+=t[b].size;
        t[b]=timecontainer();
        return a;
    }
}arrive,leave;//earliest time they can arrive here and latest they can leave to get to correct node
pii dfs(int loc, int edge){
    pii cur={sz(arrive.t),sz(leave.t)};
    arrive.t.push_back({timecontainer({1,loc})}),leave.t.push_back({timecontainer({m,loc})});
    for(auto x:matrix[loc])if(x.second!=edge&&!cent[x.first]){
        pii te=dfs(x.first,x.second);
        cur={arrive.merge(cur.first,te.first),leave.merge(cur.second,te.second)};
    }
    auto it=arrive.t[cur.first].t.begin();
    bool open=false;
    for(auto x:ups[edge]){
        if(open)it=arrive.t[cur.first].t.lower_bound(x);
        else{
            if(it==arrive.t[cur.first].t.end()){
                open=sz(ups[edge])%2;
                break;
            }
            if(it->first<x&&!arrive.t[cur.first].t.count(x))arrive.t[cur.first].t[x]={};
            while(it->first<x){
                if(sz(it->second)>sz(arrive.t[cur.first].t[x]))it->second.swap(arrive.t[cur.first].t[x]);
                arrive.t[cur.first].t[x].insert(arrive.t[cur.first].t[x].end(),it->second.begin(),it->second.end());
                it++;
                arrive.t[cur.first].t.erase(prev(it,1));
            }
        }
        open^=1;
    }
    if(!open){
        for(auto teit=it;teit!=arrive.t[cur.first].t.end();teit++)arrive.t[cur.first].size-=sz(teit->second);
        arrive.t[cur.first].t.erase(it,arrive.t[cur.first].t.end());
    }
    it=leave.t[cur.second].t.end();
    reverse(ups[edge].begin(),ups[edge].end());
    for(auto x:ups[edge]){
        if(open)it=leave.t[cur.second].t.lower_bound(x);
        else{
            if(it==leave.t[cur.second].t.begin()){
                open=false;
                break;
            }
            it--;
            if(it->first>x-1&&!leave.t[cur.second].t.count(x-1))leave.t[cur.second].t[x-1]={};
            while(it->first>x-1){
                if(sz(it->second)>sz(leave.t[cur.second].t[x-1]))it->second.swap(leave.t[cur.second].t[x-1]);
                leave.t[cur.second].t[x-1].insert(leave.t[cur.second].t[x-1].end(),it->second.begin(),it->second.end());
                it--;
                leave.t[cur.second].t.erase(next(it,1));
            }
        }
        open^=1;
    }
    if(!open){
        for(auto teit=leave.t[cur.second].t.begin();teit!=it;teit++)leave.t[cur.second].size-=sz(teit->second);
        leave.t[cur.second].t.erase(leave.t[cur.second].t.begin(),it);
    }
    reverse(ups[edge].begin(),ups[edge].end());
    return cur;
}
void decomp(int loc){
    cent[loc=getcent(loc,0,dfssz(loc,0)/2)]=true;
    update(1,1);
    for(auto x:matrix[loc]){
        if(!cent[x.first]){
            pii te=dfs(x.first,x.second);
            storage[x.first][0]=arrive.t[te.first].t;
            storage[x.first][1]=leave.t[te.second].t;
            arrive=stlcont(),leave=stlcont();
            for(auto y:storage[x.first][0])update(y.first,sz(y.second));
        }
    }
    ans[loc]+=query(m)-1;
    for(auto x:matrix[loc]) {
        if (!cent[x.first]) {
            int sum=0;
            auto it=storage[x.first][0].begin();
            for(auto y:storage[x.first][1]){
                while(it!=storage[x.first][0].end()&&it->first<=y.first)sum+=sz(it->second),it++;
                int toadd=query(y.first)-sum;
                if(toadd)for(auto z:y.second)ans[z]+=toadd;
            }
        }
    }
    update(1,-1);
    for(auto x:matrix[loc])if(!cent[x.first]){
        for(auto y:storage[x.first][0])update(y.first,-sz(y.second));
        storage[x.first][0]=map<int,vector<int>>();
        storage[x.first][1]=map<int,vector<int>>();
    }
    for(auto x:matrix[loc])if(!cent[x.first])decomp(x.first);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back({b,i});
        matrix[b].push_back({a,i});
    }
    for(int i=1;i<=m;i++){
        cin>>a;
        ups[a].push_back(i);
    }
    decomp(1);
    while(q--){
        cin>>a;
        printf("%d\n",ans[a]+1);
    }
    return 0;
}