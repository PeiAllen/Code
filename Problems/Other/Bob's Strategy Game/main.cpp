#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pii> omatrix[MAXN];
vector<int> matrix[2*MAXN];
int oind[MAXN],olind[MAXN];
int cind=1;
stack<int> st;
int nodes;
int n,m;
int ind[2*MAXN];
int dist[2*MAXN],depth[2*MAXN];
int sparse[20][4*MAXN];
void GetBTree(int loc, int edgeind){
    oind[loc]=cind,olind[loc]=cind++;
    st.push(loc);
    for(auto x:omatrix[loc]){
        if(x.second!=edgeind){
            if(!oind[x.first]){
                GetBTree(x.first,x.second);
                if(olind[x.first]==oind[loc]){
                    for(int cur=st.top();cur!=x.first;st.pop(),cur=st.top()){
                        matrix[cur].push_back(nodes);
                        matrix[nodes].push_back(cur);
                    }
                    st.pop();
                    matrix[loc].push_back(nodes);
                    matrix[nodes].push_back(loc);
                    matrix[x.first].push_back(nodes);
                    matrix[nodes].push_back(x.first);
                    nodes++;
                }
                else if(olind[x.first]==oind[x.first])matrix[loc].push_back(x.first),matrix[x.first].push_back(loc);
                olind[loc]=min(olind[loc],olind[x.first]);
            }
            else olind[loc]=min(olind[loc],oind[x.first]);
        }
    }
    if(olind[loc]==oind[loc])st.pop();
}
void dfs(int loc, int parent, int dep){
    sparse[0][cind]=loc;
    ind[loc]=cind++;
    depth[loc]=dep;
    dist[loc]=dist[parent]+(loc<=n);
    for(auto x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc,dep+1);
            sparse[0][cind]=loc;
            cind++;
        }
    }
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=19;i++){
        for(int j=0;j+(1<<i)<=cind;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=ind[a],b=ind[b];
    if(a>b)swap(a,b);
    int k=log2(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        nodes=n+1;
        int a,b;
        for(int i=1;i<=n;i++)omatrix[i]=vector<pii>(),oind[i]=0,olind[i]=0;
        for(int i=1;i<=2*n;i++)matrix[i]=vector<int>();
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            omatrix[a].push_back({b,i});
            omatrix[b].push_back({a,i});
        }
        cind=1;
        GetBTree(1,0);
        cind=0;
        dfs(1,0,1);
        ms();
        int q;
        cin>>q;
        while(q--){
            int s;
            cin>>s;
            vector<int> points(s);
            for(int i=0;i<s;i++)cin>>points[i];
            sort(points.begin(),points.end(),[&](auto lhs,auto rhs){
               return ind[lhs]<ind[rhs];
            });
            int ans=0;
            int lca=points[0];
            for(int i=0;i<s;i++){
                lca=getlca(lca,points[i]);
                ans+=dist[points[i]]+dist[points[(i+1)%s]]-2*dist[getlca(points[i],points[(i+1)%s])];
            }
            ans/=2;
            ans-=s;
            ans+=lca<=n;
            printf("%d\n",ans);
        }
    }
    return 0;
}