#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
int bit[MAXN],st[MAXN],en[MAXN],alien[MAXN],lst[MAXN];
set<pii> locs[MAXN];
vector<int> matrix[MAXN];
int sparse[20][2*MAXN];
int depth[MAXN];
int n,k,m;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int et,let;
void dfs(int loc, int dep){
    depth[loc]=dep;
    st[loc]=et++;
    lst[loc]=let;
    sparse[0][let++]=loc;
    for(auto x:matrix[loc])if(!st[x])dfs(x,dep+1),sparse[0][let++]=loc;
    en[loc]=et-1;
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=let;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=lst[a],b=lst[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)cin>>alien[i];
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b),matrix[b].push_back(a);
    }
    et=1;
    let=0;
    dfs(1,1);
    ms();
    for(int i=1;i<=n;i++)locs[alien[i]].insert({st[i],i});
    for(int i=1;i<=k;i++){
        int last=-1;
        for(auto x:locs[i]){
            update(x.first,1);
            if(last!=-1){
                update(st[getlca(last,x.second)],-1);
            }
            last=x.second;
        }
    }
    int c;
    while(m--){
        cin>>a>>b;
        if(a==1){
            cin>>c;
            if(alien[b]==c)continue;
            auto it=locs[alien[b]].lower_bound({st[b],b}),ne=next(it,1);
            if(ne!=locs[alien[b]].end())update(st[getlca(b,ne->second)],1);
            if(it!=locs[alien[b]].begin()){
                auto pr=prev(it,1);
                update(st[getlca(b,pr->second)],1);
                if(ne!=locs[alien[b]].end())update(st[getlca(pr->second,ne->second)],-1);
            }
            locs[alien[b]].erase(it);
            it=locs[c].lower_bound({st[b],b});
            if(it!=locs[c].end())update(st[getlca(b,it->second)],-1);
            if(it!=locs[c].begin()){
                auto pr=prev(it,1);
                update(st[getlca(b,pr->second)],-1);
                if(it!=locs[c].end())update(st[getlca(pr->second,it->second)],1);
            }
            locs[c].insert({st[b],b});
            alien[b]=c;
        }
        else{
            printf("%d\n",query(en[b])-query(st[b]-1));
        }
    }
    return 0;
}