#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll bit[MN];
int bitcnt[MN];
vector<ll> vals;
void update(int loc, ll val){
    for(;loc<=sz(vals);loc+=loc&-loc)bit[loc]+=val;
}
void updatecnt(int loc, int val){
    for(;loc<=sz(vals);loc+=loc&-loc)bitcnt[loc]+=val;
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int querycnt(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bitcnt[loc];
    return sum;
}
ll dist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    char t;
    ll a,b;
    cin>>n>>m;
    vector<pair<bool,pll>> ops;
    vals.push_back(0);
    for(int i=0;i<m;i++){
        cin>>t>>a>>b;
        if(t=='U'){
            vals.push_back(b);
            ops.push_back({0,{a,b}});
        }
        else ops.push_back({1,{a,b}});
    }
    sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<m;i++){
        if(ops[i].first){
            int above=querycnt(sz(vals))-querycnt(lower_bound(vals.begin(),vals.end(),ops[i].second.second)-vals.begin()-1+1);
            ll below=query(lower_bound(vals.begin(),vals.end(),ops[i].second.second)-vals.begin()-1+1);
            if(above*ops[i].second.second+below>=ops[i].second.first*ops[i].second.second)printf("TAK\n");
            else printf("NIE\n");
        }
        else{
            update(lower_bound(vals.begin(),vals.end(),dist[ops[i].second.first])-vals.begin()+1,-dist[ops[i].second.first]);
            updatecnt(lower_bound(vals.begin(),vals.end(),dist[ops[i].second.first])-vals.begin()+1,-1);
            dist[ops[i].second.first]=ops[i].second.second;
            update(lower_bound(vals.begin(),vals.end(),dist[ops[i].second.first])-vals.begin()+1,dist[ops[i].second.first]);
            updatecnt(lower_bound(vals.begin(),vals.end(),dist[ops[i].second.first])-vals.begin()+1,1);
        }
    }
    return 0;
}