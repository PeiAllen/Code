#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
int ind[MAXN],lind[MAXN];
vector<pii> matrix[MAXN];
stack<int> st;
vector<vector<int>> comps;
int cind=1;
bool inst[MAXN];
void dfs(int loc, int edgeind){
    ind[loc]=cind,lind[loc]=cind++;
    st.push(loc);
    inst[loc]=true;
    for(auto x:matrix[loc]){
        if(x.second!=edgeind){
            if(!ind[x.first]){
                dfs(x.first,x.second);
                lind[loc]=min(lind[loc],lind[x.first]);
            }
            else if(inst[x.first])lind[loc]=min(lind[loc],ind[x.first]);
        }
    }
    if(lind[loc]==ind[loc]){
        comps.push_back({});
        while(true){
            int cur=st.top();
            st.pop();
            inst[cur]=false;
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
    }
    for(int i=0;i<n;i++){
        if(!ind[i]){
            dfs(i,0);
        }
    }
    reverse(comps.begin(),comps.end());// for topological order in directed edge order
    printf("%d\n",sz(comps));
    for(auto x:comps){
        printf("%d ",sz(x));
        for(auto y:x)printf("%d ",y);
        printf("\n");
    }
    return 0;
}