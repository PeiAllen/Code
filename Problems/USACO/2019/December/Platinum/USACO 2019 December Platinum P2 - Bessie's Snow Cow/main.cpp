#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int n,q;
int st[MAXN],en[MAXN];
ll sts[MAXN];
set<pii> locs[MAXN];
set<pii> already[MAXN];
vector<int> matrix[MAXN];
ll bit[2][MAXN];//0 is ancestorsum, 1 is subtreesum
void update(int ind, int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit[ind][loc]+=val;
}
ll query(int ind, int loc){
    ll ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[ind][loc];
    return ans;
}
int dfn;
ll dfs(int loc, int parent){
    st[loc]=dfn++;
    sts[loc]=1;
    for(auto x:matrix[loc])if(x!=parent)sts[loc]+=dfs(x,loc);
    en[loc]=dfn;
    return sts[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfn=1;
    dfs(1,0);
    int c;
    while(q--){
        cin>>a>>b;
        if(a==1){
            cin>>c;
            auto it=already[c].lower_bound({st[b],MAXN});
            if(it!=already[c].begin()&&prev(it,1)->second>=st[b])continue;
            for(auto it=locs[c].lower_bound({st[b],0});it!=locs[c].end()&&it->first<en[b];it=locs[c].lower_bound({st[b],0})){
                update(0,it->first,-1LL);
                update(0,en[it->second],1LL);
                update(1,it->first,-1LL*sts[it->second]);
                already[c].erase({it->first,en[it->second]-1});
                locs[c].erase(it);
            }
            locs[c].insert({st[b],b});
            already[c].insert({st[b],en[b]-1});
            update(0,st[b],1LL);
            update(0,en[b],-1LL);
            update(1,st[b],sts[b]);
        }
        else{
            printf("%lli\n",query(0,st[b])*sts[b]+query(1,en[b]-1)-query(1,st[b]));
        }
    }
    return 0;
}