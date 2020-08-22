#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
ll par[MAXN];
ll depth[MAXN];
ll et[MAXN],en[MAXN],et2[MAXN];//exclusiove en
ll sparse[18][2*MAXN];
vector<ll> matrix[MAXN];
vector<pair<ll,pll>> queries[MAXN];
ll ans[MAXN];
ll n,q;
ll ev=0,ev2=0;
void dfs(ll loc){
    sparse[0][ev2]=depth[loc];
    et2[loc]=ev2++;
    et[loc]=ev++;
    for(auto x:matrix[loc]){
        dfs(x);
        sparse[0][ev2]=depth[loc];
        ev2++;
    }
    en[loc]=ev-1;
}
void mt(){
    for(ll i=1;i<=17;i++){
        for(ll j=0;j<=ev2-(1<<i);j++){
            sparse[i][j]=min(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(ll a, ll b){
    a=et2[a],b=et2[b];
    if(a>b)swap(a,b);
    ll k=log2(b-a+1);
    return min(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
vector<ll> ets[MAXN];
ll pc[MAXN];
ll bs,mab;
void solve(ll loc){
    for(ll i=0;i<=mab;i++){
        pc[i]+=upper_bound(ets[i].begin(),ets[i].end(),en[loc])-lower_bound(ets[i].begin(),ets[i].end(),et[loc]);
    }
    for(auto x:queries[loc]){
        if(x.second.first/bs==x.second.second/bs)for(int i=x.second.first;i<=x.second.second;i++)ans[x.first]+=query(loc,i);
        else{
            ll lb=x.second.first/bs+1,rb=x.second.second/bs-1;
            for(ll i=lb;i<=rb;i++)ans[x.first]+=pc[i];
            for(ll i=x.second.first;i<lb*bs;i++)ans[x.first]+=query(loc,i);
            for(ll i=x.second.second;i>=(rb+1)*bs;i--)ans[x.first]+=query(loc,i);
        }
    }
    for(auto x:matrix[loc])solve(x);
    for(ll i=0;i<=mab;i++){
        pc[i]-=(upper_bound(ets[i].begin(),ets[i].end(),en[loc])-lower_bound(ets[i].begin(),ets[i].end(),et[loc]));
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
   // freopen("C:\\Users\\allen\\OneDrive\\Documents\\GitHub\\Code\\Problems\\Other\\Bob's LCA\\in","r",stdin);
    cin>>n>>q;
    depth[0]=1;
    bs=sqrt(n);
    mab=(n-1)/bs;
    for(ll i=1;i<n;i++){
        cin>>par[i];
        depth[i]=depth[par[i]]+1;
        matrix[par[i]].push_back(i);
    }
    dfs(0);
    mt();
    ll l,r,x;
    for(ll i=0;i<q;i++){
        cin>>l>>r>>x;
        queries[x].push_back({i,{l,r}});
    }
    for(ll i=0;i<n;i++){
        ets[i/bs].push_back(et[i]);
    }
    for(ll i=0;i<=mab;i++){
        sort(ets[i].begin(),ets[i].end());
    }
    solve(0);
    for(ll i=0;i<q;i++)printf("%lli\n",ans[i]);
    return 0;
}