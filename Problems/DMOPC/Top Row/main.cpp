#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1,MQ=5e5+1;
struct sam{
    struct node{
        int sufind,len,link;
        int to[26];
        node(int l, int i){
            len=l,sufind=i;
            link=-1;
            for(int j=0;j<26;j++)to[j]=-1;
        }
    };
    vector<node> t;
    int last;
    sam(){
        last=0;
        t={node(0,-1)};
    }
    void add(char x, int ind){
        int cur=sz(t),charval=x-'a';
        t.push_back(node(t[last].len+1,ind));
        int from=last;
        while(from!=-1&&t[from].to[charval]==-1)t[from].to[charval]=cur,from=t[from].link;
        if(from==-1)t[cur].link=0;
        else{
            int plink=t[from].to[charval];
            if(t[plink].len==t[from].len+1)t[cur].link=plink;
            else{
                int clone=sz(t);
                t.push_back(node(t[from].len+1,-1));
                for(int i=0;i<26;i++)t[clone].to[i]=t[plink].to[i];
                t[clone].link=t[plink].link;
                t[plink].link=t[cur].link=clone;
                while(from!=-1&&t[from].to[charval]==plink)t[from].to[charval]=clone,from=t[from].link;
            }
        }
        last=cur;
    }
    void clear(){
        t=vector<node>();
    }
}solver;
int n;
struct seg{
    struct node{
        struct arssum{
            int d;
            ll tosub, firstterm;
            arssum(){
                d=0,tosub=0,firstterm=0;
            }
            void update(ll val, ll st){
                ll td=(val>=0?1:-1);
                d+=td;
                firstterm+=val-td*(n-st);
                tosub+=(n-st)*(ll(2)*(val-td*(n-st))+(n-st-1)*td)/ll(2);
            }
            ll query(ll time){
                return (n-time+1)*(ll(2)*firstterm+(n-time+1-1)*d)/ll(2)-tosub;
            }
        };
        vector<pair<int,arssum>> data;
        node(){
            data={};
        }
        void update(ll val, ll st){
            if(sz(data)==0||data.back().first!=st)data.push_back({st,(sz(data)?data.back().second:arssum())});
            data.back().second.update(val,st);
        }
        ll query(ll time){
            int loc=upper_bound(data.begin(),data.end(),time,[&](const ll &val, const pair<int,arssum> &cur){
                return cur.first<val;
            })-data.begin();
            if(loc==0)return 0;
            return data[loc-1].second.query(time);
        }
    }t[2*MN];
    void update(int ind, int le, int ri, int l, int r, ll val, ll st){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].update(val,st);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val,st),update(right,mid+1,ri,l,r,val,st);
    }
    ll query(int ind, int le, int ri, int loc, ll time){
        ll val=t[ind].query(time);
        if(le==ri)return val;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(loc<=mid)return val+query(left,le,mid,loc,time);
        return val+query(right,mid+1,ri,loc,time);
    }
}tree;
int samind[MN];
vector<int> adj[2*MN];
set<pii> indicies[2*MN];
vector<pair<pii,pii>> info;
vector<pair<pii,ll>> updates[MN];
int startchain(int loc, int lind, int rind){
    info.push_back({{lind,rind},{1,solver.t[loc].len}});
    return sz(info)-1;
}
void endchain(int ind, int loc){
    info[ind].second.first=solver.t[loc].len+1;
}
int dfs(int loc){
    int cur=loc;
    if(solver.t[loc].sufind!=-1)indicies[loc].insert({solver.t[loc].sufind,startchain(loc,solver.t[loc].sufind,n+1)});
    for(auto ne:adj[loc]){
        int te=dfs(ne);
        if(sz(indicies[te])>sz(indicies[cur]))swap(te,cur);
        for(auto x:indicies[te]){
            endchain(x.second,loc);
            auto it=indicies[cur].lower_bound({x.first,0});
            if(it!=indicies[cur].begin()){
                auto before=prev(it,1);
                endchain(before->second,loc);
                int val=before->first;
                indicies[cur].erase(before);
                indicies[cur].insert({val,startchain(loc,val,x.first)});
            }
            indicies[cur].insert({x.first,startchain(loc,x.first,(it==indicies[cur].end()?n+1:it->first))});
        }
    }
    return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    n=sz(s);
    for(int i=1;i<=sz(s);i++)solver.add(s[i-1],i);
    for(int i=0;i<sz(solver.t);i++){
        if(solver.t[i].sufind!=-1)samind[solver.t[i].sufind]=i;
        if(solver.t[i].link!=-1)adj[solver.t[i].link].push_back(i);
    }
    dfs(0);
    for(int i=0;i<sz(solver.t);i++)indicies[i]=set<pii>(),adj[i]=vector<int>();
    solver.clear();
    for(auto x:info){
        if(x.second.first<=x.second.second) {
            updates[x.first.first - x.second.first + 1].push_back({{x.first.first, x.first.second - 1}, x.second.first + 1});
            updates[x.first.first - (x.second.second + 1) + 1].push_back({{x.first.first, x.first.second - 1}, -(x.second.second + 1+1)});
        }
    }
    info=vector<pair<pii,pii>>();
    for(int i=sz(s);i>=1;i--){
        for(auto x:updates[i]){
            tree.update(0,1,n,x.first.first,x.first.second,x.second,i);
        }
        updates[i]=vector<pair<pii,ll>>();
    }
    int q;
    cin>>q;
    ll a,b,lastans=0;
    while(q--){
        cin>>a>>b;
        a^=lastans,b^=lastans;
        printf("%lli\n",lastans=tree.query(0,1,n,b,a));
    }
    return 0;
}