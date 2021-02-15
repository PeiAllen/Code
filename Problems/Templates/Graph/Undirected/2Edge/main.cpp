#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int depth[MAXN],ldepth[MAXN];
vector<pii> matrix[MAXN];
stack<int> st;
vector<vector<int>> comps;
void dfs(int loc, int edgeind, int dep){//splits graph by bridges
    depth[loc]=dep,ldepth[loc]=dep;
    st.push(loc);
    for(auto x:matrix[loc]){
        if(x.second!=edgeind){
            if(depth[x.first])ldepth[loc]=min(ldepth[loc],depth[x.first]);
            else{
                dfs(x.first,x.second,dep+1);
                ldepth[loc]=min(ldepth[loc],ldepth[x.first]);
            }
        }
    }
    if(ldepth[loc]==depth[loc]){
        comps.push_back({});
        while(true){
            int cur=st.top();
            st.pop();
            comps.back().push_back(cur);
            if(cur==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        matrix[a].push_back({b,i});
        matrix[b].push_back({a,i});
    }
    for(int i=0;i<n;i++){
        if(!depth[i]){
            dfs(i,0,1);
        }
    }
    printf("%d\n",sz(comps));
    for(auto x:comps){
        printf("%d ",sz(x));
        for(auto y:x)printf("%d ",y);
        printf("\n");
    }
    return 0;
}