#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<pii> matrix[MAXN];
int depth[MAXN];
int lowestdepth[MAXN];
bool apoint[MAXN];
bool bridge[MAXN];
bool gone[MAXN];
int components=0;
int root;
void GetComponents(int loc, int edgeindex, int dep){
    depth[loc]=dep,lowestdepth[loc]=dep;
    int telowestdepth=dep;
    int childcnt=0;
    for(auto x:matrix[loc]){
        if(x.second!=edgeindex){
            if(depth[x.first])telowestdepth=min(telowestdepth,depth[x.first]);
            else{
                childcnt++;
                GetComponents(x.first,x.second,dep+1);
                lowestdepth[loc]=min(lowestdepth[loc],lowestdepth[x.first]);
            }
        }
    }
    apoint[loc]=(lowestdepth[loc]==dep);
    if(loc==root&&childcnt==1)apoint[loc]=false;
    lowestdepth[loc]=min(lowestdepth[loc],telowestdepth);
    if(loc!=root) {
        bridge[edgeindex] = (lowestdepth[loc] == dep);
        components += bridge[edgeindex];
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
    for(int i=0;i<n;i++) {
        if(!depth[i]) {
            components++;
            root = i;
            GetComponents(i, 0, 1);
        }
    }
    printf("%d\n",components);
    for(int i=0;i<n;i++){
        if(!gone[i]){
            queue<int> q;
            q.push(i);
            gone[i]=true;
            vector<int> nodes;
            while(sz(q)){
                int cur=q.front();
                q.pop();
                nodes.push_back(cur);
                for(auto x:matrix[cur]){
                    if(!bridge[x.second]&&!gone[x.first]){
                        gone[x.first]=true;
                        q.push(x.first);
                    }
                }
            }
            printf("%d ",sz(nodes));
            for(auto x:nodes)printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}