#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=2e6+2;
vector<vector<bool>> grid;
int n,m,k,s;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int v){
            data+=v,lazy+=v;
        }
    }t[2*MN];
    void clear(int ind, int le, int ri){
        t[ind].data=0,t[ind].lazy=0;
        if(le==ri)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        clear(left,le,mid),clear(right,mid+1,ri);
    }
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return INT_MAX;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
vector<vector<ll>> bit;
void update(int ind, int loc, ll val){
    for(; loc <= n; loc+= loc & -loc){
        bit[ind][loc]+=val;
    }
}
int query(int ind, int loc){
    ll val=0;
    for(;loc>0;loc-=loc&-loc){
        val+=bit[ind][loc];
    }
    return int(val);
}
int getfirst(int ind, ll v){
    v--;
    int pos=0;
    for(int i=__lg(n); i >= 0; i--){
        if(pos+(1<<i) <= n && bit[ind][pos + (1 << i)] <= v){
            pos+=(1<<i);
            v-=bit[ind][pos];
        }
    }
    if(pos==n)return n+10;
    return pos+1;
}
pii spell[MN];
int cost[MN];
void solve(){
    tree.clear(0, 1, n + 1);
    bit=vector<vector<ll>>(m + 1, vector<ll>(n + 1, 0));
    for(int i=1; i <= m; i++){
        for(int j=1; j <= n; j++){
            if(grid[j][i])update(i,j,1);
        }
    }
    vector<int> am(m + 1, 0);
    for(int i=1;i<k;i++){
        for(int j=1; j <= m; j++){
            am[j]+=grid[i][j];
        }
    }
    int movecnt=0;
    for(int i=k; i <= n; i++){
        int needed=0;
        for(int j=1; j <= m; j++){
            am[j]+=grid[i][j];
            if(grid[i][j]||am[j]>=k)needed++;
        }
        tree.update(0, 1, n + 1, i, i, needed + movecnt);
        movecnt++;
    }
    int needed=0;
    for(int j=1; j <= m; j++){
        if(am[j]>=k)needed++;
    }
    tree.update(0, 1, n + 1, n + 1, n + 1, needed + movecnt);
    for(int i=0;i<s;i++){
        int a=spell[i].first,b=spell[i].second;
        if(grid[a][b]){
            if(query(b,a-1)<k) {
               tree.update(0, 1, n + 1, a, a, -1);
                int getkloc=getfirst(b,k);
                int nextloc=getfirst(b,k+1);
                tree.update(0, 1, n + 1, getkloc + 1, nextloc - 1, -1);
            }
            update(b,a,-1);
        }
        else{
            if(query(b,a-1)<k) {
                tree.update(0, 1, n + 1, a, a, 1);
                int getkloc=max(a+1,getfirst(b,k-1)+1);
                int nextloc=getfirst(b,k);
                tree.update(0, 1, n + 1, getkloc, nextloc - 1, 1);
            }
            update(b,a,1);
        }
        grid[a][b]=!grid[a][b];
        cost[i]=min(cost[i],tree.query(0, 1, n + 1, k, n + 1));
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("valet_parking_chapter_2_input.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        char a;
        cin >> n >> m >> k >> s;
        grid=vector<vector<bool>>(n + 1, vector<bool>(m + 1, 0));
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                cin>>a;
                grid[i][j]=(a=='X');
            }
        }
        for(int i=0;i<s;i++){
            cost[i]=INT_MAX;
            cin>>spell[i].first>>spell[i].second;
        }
        vector<vector<bool>> og=grid;
        solve();
        grid=og;
        reverse(grid.begin()+1,grid.end());
        k= n - k + 1;
        for(int i=0;i<s;i++)spell[i].first= n - spell[i].first + 1;
        solve();
        ll ans=0;
        for(int i=0;i<s;i++){
            ans=ans+ll(cost[i]);
        }
        printf("Case #%d: %lli\n",cs,ans);
    }
    return 0;
}