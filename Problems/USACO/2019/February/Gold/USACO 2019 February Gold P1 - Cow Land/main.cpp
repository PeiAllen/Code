#include <bits/stdc++.h>

using namespace std;
template <typename T>
int sz(T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int arr[MAXN];
int st[MAXN];
int sts[MAXN];
int et=1;
int nxt[MAXN];
int par[MAXN];
int bit[MAXN];
int n,q;
int depth[MAXN];
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]^=val;
}
int bq(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans^=bit[loc];
    return ans;
}
int query(int l, int r){
    return bq(r)^bq(l-1);
}
int dfs(int loc, int parent, int dep){
    sts[loc]=1;
    depth[loc]=dep;
    int ind=0;
    par[loc]=parent;
    int toer=-1;
    if(matrix[loc][0]==parent)matrix[loc].erase(matrix[loc].begin());
    for(int x:matrix[loc]){
        if(x!=parent){
            sts[loc]+=dfs(x,loc,dep+1);
            if(sts[x]>sts[matrix[loc][0]]){
                swap(matrix[loc][0],matrix[loc][ind]);
            }
        }
        else{
            toer=ind;
        }
        ind++;
    }
    if(toer!=-1)matrix[loc].erase(matrix[loc].begin()+toer);
    return sts[loc];
}
void etdfs(int loc){
    st[loc]=et++;
    for(int x:matrix[loc]){
        nxt[x]=(x==matrix[loc][0]?nxt[loc]:x);
        etdfs(x);
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    int a,b;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    nxt[1]=1;
    etdfs(1);
    for(int i=1;i<=n;i++)update(st[i],arr[i]);
    int c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            update(st[b],arr[b]^c);
            arr[b]=c;
        }
        else{
            if(depth[nxt[b]]<depth[nxt[c]])swap(b,c);
            int ans=0;
            while(nxt[b]!=nxt[c]){
                ans^=query(st[nxt[b]],st[b]);
                b=par[nxt[b]];
                if(depth[nxt[b]]<depth[nxt[c]])swap(b,c);
            }
            ans^=query(min(st[c],st[b]),max(st[c],st[b]));
            printf("%d\n",ans);
        }
    }
    return 0;
}