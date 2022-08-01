#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int par[2][MN];
vector<int> adj[2][MN];
int root[2];
vector<int> et[2];
int st[2][MN];
int depth[2][MN];
int et2[2];
int sparse[2][__lg(2*MN)+1][2*MN];
void dfs(int tr,int loc){
    et[tr].push_back(loc);
    sparse[tr][0][et2[tr]]=loc;
    st[tr][loc]=et2[tr]++;
    for(auto x:adj[tr][loc]){
        depth[tr][x]=depth[tr][loc]+1;
        dfs(tr,x);
        sparse[tr][0][et2[tr]++]=loc;
    }
}
int mh(int tr, int a, int b){
    if(depth[tr][a]<depth[tr][b])return a;
    return b;
}
void ms(){
    for(int tr=0;tr<2;tr++){
        for(int i=1;i<=__lg(et2[tr]);i++){
            for(int j=0;j+(1<<i)<=et2[tr];j++){
                sparse[tr][i][j]=mh(tr,sparse[tr][i-1][j],sparse[tr][i-1][j+(1<<(i-1))]);
            }
        }
    }
}
int getlca(int tr, int a, int b){
    a=st[tr][a],b=st[tr][b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(tr,sparse[tr][k][a],sparse[tr][k][b-(1<<k)+1]);
}

vector<int> wanted;
pii bit[MN];
int val[MN];
int from[MN];
int n;
bool bad[MN];

void update(int loc, pii val){
    for(;loc<=n;loc+=loc&-loc){
        bit[loc]=max(bit[loc],val);
    }
}
pii query(int loc){
    pii ret={0,0};
    for(;loc>0;loc-=loc&-loc){
        ret=max(ret,bit[loc]);
    }
    return ret;
}
vector<int> getlis(vector<int> a){
    for(int i=1;i<=n;i++)bit[i]={0,0};
    for(auto x:a){
        pii best=query(x);
        from[x]=best.second;
        update(x,{best.first+1,x});
    }
    pii best=query(n);
    vector<int> ret;
    while(best.second!=0){
        ret.push_back(best.second);
        best.second=from[best.second];
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
vector<pair<pii,ll>> edges[2];
vector<pair<int,ll>> adj2[2][MN];
pair<int,ll> dsu[MN];
ll dists[2][MN];
void calcdists(int tr, int loc){
    for(auto x:adj2[tr][loc]){
        dists[tr][x.first]=dists[tr][loc]+x.second;
        calcdists(tr,x.first);
    }
}

int find(int a){
    if(dsu[a].first==a)return a;
    find(dsu[a].first);
    dsu[a].second+=dsu[dsu[a].first].second;
    return dsu[a].first=dsu[dsu[a].first].first;
}
bool uni(int a, int b, ll dis){//b is parent
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    dsu[ap].first=bp;
    dsu[ap].second=dis+dsu[b].second;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(4324232);
    int k,q,t;
    cin>>n>>k>>q>>t;
    for(int tr=0;tr<2;tr++) {
        for (int i = 1; i <= n; i++) {
            cin>>par[tr][i];
            par[tr][i]=max(par[tr][i],0);
            adj[tr][par[tr][i]].push_back(i);
        }
        root[tr]=adj[tr][0][0];
    }
    for(int tr=0;tr<2;tr++) {
        for (int i = 1; i <= n; i++) {
            sort(adj[tr][i].begin(),adj[tr][i].end());
        }
    }
    for (int i = 1; i <= n; i++) {
        if(adj[0][i]!=adj[1][i]||n>500000){
            shuffle(adj[0][i].begin(),adj[0][i].end(),gen);
            shuffle(adj[1][i].begin(),adj[1][i].end(),gen);
        }
    }
    for(int tr=0;tr<2;tr++) {
        dfs(tr, root[tr]);
    }
    ms();
    if(q==k-1) {
        vector<int> te;
        for (int i = 1; i <= n; i++) {
            val[et[0][i - 1]] = i;
        }
        for (int i = 1; i <= n; i++) {
            te.push_back(val[et[1][i - 1]]);
        }
        vector<int> first = getlis(te);
        reverse(te.begin(), te.end());
        vector<int> second = getlis(te);
        reverse(te.begin(), te.end());
//        for(int i=0;i<6&&max(sz(first),sz(second))<k;i++){
//            uniform_int_distribution<int> range(0,sz(te)-1);
//            rotate(te.begin(),te.begin()+range(gen),te.end());
//            first = getlis(te);
//            reverse(te.begin(), te.end());
//            second = getlis(te);
//            reverse(te.begin(), te.end());
//        }
        if (sz(first) < sz(second)) {
            swap(first, second);
            reverse(te.begin(), te.end());
        }
        if(sz(first)<k){
            for(auto x:first){
                bad[x]=true;
            }
            for(int i=1;i<=n;i++){
                if(!bad[i]&&sz(first)<k){
                    first.push_back(i);
                }
            }
            sort(first.begin(),first.end());
        }
        for (auto x: first) {
            wanted.push_back(et[0][x - 1]);
        }
        wanted.resize(k);
        for (auto x: wanted)printf("%d%c", x, " \n"[x == wanted.back()]);
        for (int i = 1; i < sz(wanted); i++) {
            printf("? %d %d\n", wanted[i - 1], wanted[i]);
        }
        printf("!\n");
        fflush(stdout);
        ll a;
        for (int i = 1; i < sz(wanted); i++) {
            for (int tr = 0; tr < 2; tr++) {
                cin >> a;
                int lca = getlca(tr, wanted[i - 1], wanted[i]);
                edges[tr].push_back({{wanted[i - 1], lca}, a});
                cin >> a;
                edges[tr].push_back({{wanted[i], lca}, a});
            }
        }
        for (int tr = 0; tr < 2; tr++) {
            for (int i = 1; i <= n; i++)dsu[i] = {i, 0};
            sort(edges[tr].begin(), edges[tr].end(), [&](const auto &lhs, const auto &rhs) {
                return depth[tr][lhs.first.second] < depth[tr][rhs.first.second];
            });
            for (auto x: edges[tr]) {
                if (find(x.first.first) == find(x.first.second))continue;
                ll dis = x.second - dsu[x.first.first].second;
                adj2[tr][x.first.second].push_back({dsu[x.first.first].first, dis});
                uni(x.first.first, x.first.second, dis);
            }
            int rt = find(wanted[0]);
            calcdists(tr, rt);
        }
    }
    else{
        for(int i=1;i<=k;i++)wanted.push_back(i);
        for (auto x: wanted)printf("%d%c", x, " \n"[x == wanted.back()]);
        sort(wanted.begin(),wanted.end(),[&](const auto &lhs, const auto &rhs){
           return st[0][lhs]<st[0][rhs];
        });
        for (int i = 1; i < sz(wanted); i++) {
            printf("? %d %d\n", wanted[i - 1], wanted[i]);
        }
        sort(wanted.begin(),wanted.end(),[&](const auto &lhs, const auto &rhs){
            return st[1][lhs]<st[1][rhs];
        });
        for (int i = 1; i < sz(wanted); i++) {
            printf("? %d %d\n", wanted[i - 1], wanted[i]);
        }
        printf("!\n");
        fflush(stdout);
        ll a;
        sort(wanted.begin(),wanted.end(),[&](const auto &lhs, const auto &rhs){
            return st[0][lhs]<st[0][rhs];
        });
        for (int i = 1; i < sz(wanted); i++) {
            for (int tr = 0; tr < 2; tr++) {
                cin >> a;
                int lca;
                if(tr==0) {
                    lca = getlca(tr, wanted[i - 1], wanted[i]);
                    edges[tr].push_back({{wanted[i - 1], lca}, a});
                }
                cin >> a;
                if(tr==0) {
                    edges[tr].push_back({{wanted[i], lca}, a});
                }
            }
        }
        sort(wanted.begin(),wanted.end(),[&](const auto &lhs, const auto &rhs){
            return st[1][lhs]<st[1][rhs];
        });
        for (int i = 1; i < sz(wanted); i++) {
            for (int tr = 0; tr < 2; tr++) {
                cin >> a;
                int lca;
                if(tr==1) {
                    lca= getlca(tr, wanted[i - 1], wanted[i]);
                    edges[tr].push_back({{wanted[i - 1], lca}, a});
                }
                cin >> a;
                if(tr==1) {
                    edges[tr].push_back({{wanted[i], lca}, a});
                }
            }
        }
        for (int tr = 0; tr < 2; tr++) {
            for (int i = 1; i <= n; i++)dsu[i] = {i, 0};
            sort(edges[tr].begin(), edges[tr].end(), [&](const auto &lhs, const auto &rhs) {
                return depth[tr][lhs.first.second] < depth[tr][rhs.first.second];
            });
            for (auto x: edges[tr]) {
                if (find(x.first.first) == find(x.first.second))continue;
                ll dis = x.second - dsu[x.first.first].second;
                adj2[tr][x.first.second].push_back({dsu[x.first.first].first, dis});
                uni(x.first.first, x.first.second, dis);
            }
            int rt = find(wanted[0]);
            calcdists(tr, rt);
        }
    }
    vector<pll> ans;
    int a,b;
    for(int i=1;i<=t;i++){
        cin>>a>>b;
        ans.push_back({dists[0][a]+dists[0][b]-2*dists[0][getlca(0,a,b)],dists[1][a]+dists[1][b]-2*dists[1][getlca(1,a,b)]});
    }
    for(int i=0;i<t;i++){
        printf("%lli %lli\n",ans[i].first,ans[i].second);
    }
    fflush(stdout);
    return 0;
}