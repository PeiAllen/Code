#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
const ll MIV=-1e9,MAV=1e9;
struct line{
    ll m,b;
    line(ll a=0, ll c=LLONG_MIN){
        m=a,b=c;
    }
    ll at(ll x){
        return x*m+b;
    }
};
struct lichao{
    struct node{
        int left,right;
        line data;
        node(){
            data.m=0,data.b=LLONG_MIN;
            left=-1,right=-1;
        }
    };
    vector<node> t;
    lichao(){
        t={node()};
    }
    void clear(){
        t=vector<node>();
        t={node()};
    }
    int update(int ind, ll le, ll ri, line a){
        if(a.b==LLONG_MIN)return ind;
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        ll mid=le+(ri-le)/2;
        bool lef=a.at(le)>=t[ind].data.at(le),mi=a.at(mid)>=t[ind].data.at(mid);
        if(mi)swap(a,t[ind].data);
        if(le==ri)return ind;
        if(lef==mi){int te=update(t[ind].right,mid+1,ri,a);t[ind].right=te;}
        else {int te=update(t[ind].left,le,mid,a);t[ind].left=te;}
        return ind;
    }
    ll query(int ind, ll le, ll ri, ll x){
        if(ind==-1)return LLONG_MIN;
        ll mid=le+(ri-le)/2;
        if(x<=mid)return max(t[ind].data.at(x),query(t[ind].left,le,mid,x));
        return max(t[ind].data.at(x),query(t[ind].right,mid+1,ri,x));
    }
}tree;
ll ans[MN];
int del[MN];
pll val[MN];
bool update[MN];
void solve(int l, int r, const vector<pair<pii,pll>> &updates, const vector<pair<pair<int,ll>,int>> &queries){
    if(sz(queries)==0||sz(updates)==0)return;
    if(l==r)assert(0);
    int mid=(l+r)/2;
    vector<pair<pii,pll>> lupdates,rupdates,tupdate;
    vector<pair<pair<int,ll>,int>> lqueries,rqueries;
    for(auto x:updates){
        if(x.first.second<=mid)lupdates.push_back(x);
        else if(x.first.first>mid)rupdates.push_back(x);
        else tupdate.push_back(x);
    }
    for(auto x:queries){
        if(x.first.first<=mid)lqueries.push_back(x);
        else rqueries.push_back(x);
    }
    sort(tupdate.begin(),tupdate.end());
    int ptr=0;
    for(auto x:tupdate){
        while(ptr<sz(lqueries)&&lqueries[ptr].first.first<x.first.first){
            ans[lqueries[ptr].second]=max(ans[lqueries[ptr].second],tree.query(0,MIV,MAV,lqueries[ptr].first.second));
            ptr++;
        }
        tree.update(0,MIV,MAV,line(x.second.first,x.second.second));
    }
    while(ptr<sz(lqueries)){
        ans[lqueries[ptr].second]=max(ans[lqueries[ptr].second],tree.query(0,MIV,MAV,lqueries[ptr].first.second));
        ptr++;
    }
    tree.clear();
    sort(tupdate.begin(),tupdate.end(),[&](const auto& lhs, const auto &rhs){
        return rhs.first.second<lhs.first.second;
    });
    ptr=sz(rqueries)-1;
    for(auto x:tupdate){
        while(ptr>=0&&rqueries[ptr].first.first>x.first.second){
            ans[rqueries[ptr].second]=max(ans[rqueries[ptr].second],tree.query(0,MIV,MAV,rqueries[ptr].first.second));
            ptr--;
        }
        tree.update(0,MIV,MAV,line(x.second.first,x.second.second));
    }
    while(ptr>=0){
        ans[rqueries[ptr].second]=max(ans[rqueries[ptr].second],tree.query(0,MIV,MAV,rqueries[ptr].first.second));
        ptr--;
    }
    tree.clear();
    solve(l,mid,lupdates,lqueries),solve(mid+1,r,rupdates,rqueries);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    ll a;
    cin>>n;
    vector<pair<pii,pll>> updates;
    vector<pair<pair<int,ll>,int>> queries;
    int qcnt=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t==1){
            cin>>val[i].first>>val[i].second;
            update[i]=true;
        }
        else if(t==2){
            cin>>a;
            del[a]=i;
        }
        else{
            cin>>a;
            ans[qcnt]=LLONG_MIN;
            queries.push_back({{i,a},qcnt++});
        }
    }
    for(int i=1;i<=n;i++){
        if(update[i])updates.push_back({{i,(del[i]?del[i]-1:n)},val[i]});
    }
    solve(1,n,updates,queries);
    for(int i=0;i<qcnt;i++){
        if(ans[i]==LLONG_MIN)printf("EMPTY\n");
        else printf("%lli\n",ans[i]);
    }
    return 0;
}