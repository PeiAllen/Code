#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int sparse[18][MN],ncnt;
vector<pii> arr;
vector<int> adj[2*MN];
ll val[2*MN];
bool used[2*MN];
int st[2*MN],en[2*MN],parent[2*MN],etind[2*MN];
int et=0;
struct seg{
    struct node{
        pair<ll,int> data;
        ll lazy;
        void apply(ll v){
            data.first+=v;
            lazy+=v;
        }
        node(){
            data={0,0};
            lazy=0;
        }
    }t[4*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].data.second=etind[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].data=max(t[left].data,t[right].data);
    }
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=max(t[left].data,t[right].data);
    }
}tree;
int mp(int a, int b){//a<=b
    if(arr[b].first<arr[a].first)return b;
    return a;
}
void ms(){
    for(int i=1;i<18;i++){
        for(int j=0;j+(1<<i)<sz(arr);j++){
            sparse[i][j]=mp(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getmin(int a, int b){
    int k=__lg(b-a+1);
    return mp(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
void creategraph(int l, int r, int par, ll stdepth){
    if(l>r)return;
    int node=ncnt++;
    adj[par].push_back(node);
    parent[node]=par;
    int cur=getmin(l,r);
    val[node]=(arr[cur].first-stdepth)*ll(arr[r+1].second-arr[l].second);
    int mival=arr[cur].first;
    while(1){
        int te=ncnt++;
        val[te]=0;
        adj[node].push_back(te);
        parent[te]=node;
        creategraph(l,cur-1,node,mival);
        l=cur+1;
        if(l>r)break;
        cur=getmin(l,r);
        if(arr[cur].first!=mival)break;
    }
    creategraph(l,r,node,mival);
}
void dfs(int loc){
    etind[et]=loc;
    st[loc]=et++;
    for(auto x:adj[loc])dfs(x);
    en[loc]=et-1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x,y,k;
    cin>>n;
    cin>>x>>y;
    for(int i=1;i<n-1;i+=2){
        cin>>x>>y;
        sparse[0][sz(arr)]=sz(arr);
        arr.push_back({y,x});
        cin>>x>>y;
    }
    cin>>x>>y;
    arr.push_back({0,x});
    ms();
    ncnt=1;
    creategraph(0,sz(arr)-2,0,0);
    et=1;
    dfs(1);
    tree.mt(0,1,et-1);
    for(int i=1;i<ncnt;i++)tree.update(0,1,et-1,st[i],en[i],val[i]);
    cin>>k;
    ll ans=0;
    while(k--){
        pair<ll,int> loc=tree.t[0].data;
        ans+=loc.first;
        int cur=loc.second;
        while(cur!=0&&!used[cur]){
            used[cur]=true;
            tree.update(0,1,et-1,st[cur],en[cur],-val[cur]);
            cur=parent[cur];
        }
    }
    printf("%lli\n",ans);
    return 0;
}