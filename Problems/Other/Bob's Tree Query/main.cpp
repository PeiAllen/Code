#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
int arr[MAXN];
ll bit[2][MAXN+3];
int n,q,r;
inline void update(int ind, int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit[ind][loc]+=val;
}
inline ll query(int ind, int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[ind][loc];
    return sum;
}
int sts[MAXN];
int depth[MAXN];
ll val[MAXN];
int st[MAXN],en[MAXN];
int et=1;
vector<int> matrix[MAXN];
int rep[MAXN];
int par[MAXN];
inline void updaterange(int l, int r, ll val){
    update(0,l,val),update(0,r+1,-val),update(1,l,val*(ll)(l-1)),update(1,r+1,-val*(ll)r);
}
inline ll queryrange(int l, int r){
    return ((query(0, r) * (ll)r) - query(1, r))-((query(0, l-1) * (ll)(l-1)) - query(1, l-1));
}
int dfssz(int loc, int parent){
    sts[loc]=1;
    if(matrix[loc][0]==parent)swap(matrix[loc][0],matrix[loc][sz(matrix[loc])-1]);
    for(int &x:matrix[loc]){
        if(x!=parent) {
            sts[loc] += dfssz(x, loc);
            if (sts[x] > sts[matrix[loc][0]])swap(x, matrix[loc][0]);
        }
    }
    return sts[loc];
}
void getstvalues(int loc, int parent){
    st[loc]=et++;
    for(int x:matrix[loc]){
        if(x!=parent){
            getstvalues(x,loc);
        }
    }
    en[loc]=et-1;
}
void dfs(int loc, int parent, int dep){
    depth[st[loc]]=dep;
    par[st[loc]]=st[parent];
    arr[st[loc]]=val[loc];
    updaterange(st[loc],st[loc],val[loc]);
    for(int x:matrix[loc]){
        if(x!=parent){
            rep[st[x]]=(x==matrix[loc][0]?rep[st[loc]]:st[x]);
            dfs(x,loc,dep+1);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q>>r;
    int a,b;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfssz(r,0);
    getstvalues(r,0);
    dfs(r,0,1);
    ll c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            updaterange(st[b],st[b],c);
        }
        else if(a==2){
            updaterange(st[b],en[b],c);
        }
        else{
            int fi=st[b],se=st[c];
            ll ans=0;
            while(rep[fi]!=rep[se]){
               if(depth[rep[fi]]<depth[rep[se]])swap(fi,se);
               ans+=queryrange(rep[fi],fi);
               fi=par[rep[fi]];
            }
            if(depth[fi]>depth[se])swap(fi,se);
            ans+=queryrange(fi,se);
            printf("%lli\n",ans);
        }
    }
    return 0;
}
/*
10 2 4
-13 -11 5 4 18 13 14 -8 -8 14
4 1
4 10
10 2
2 8
4 7
1 6
8 5
1 3
2 9
2 9 -4
3 8 6
 */