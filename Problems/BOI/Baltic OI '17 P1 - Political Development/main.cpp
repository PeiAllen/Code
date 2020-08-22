#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e4+1;
unordered_set<int> matrix[MAXN];
int deg[MAXN];
bool done[MAXN];
int ans=1;
vector<int> nodes;
vector<int> curnodes;
void go(int loc){
    if(loc==sz(nodes)){
        ans=max(ans,sz(curnodes)+1);
        return;
    }
    go(loc+1);
    int cur=nodes[loc];
    for(int x:curnodes){
        if(!matrix[cur].count(x))return;
    }
    curnodes.push_back(nodes[loc]);
    go(loc+1);
    curnodes.pop_back();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a;
    int b;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>b;
            matrix[i].insert(b);
        }
    }
    priority_queue<pii,vector<pii>,greater<>> q;
    for(int i=0;i<n;i++){
        deg[i]=sz(matrix[i]);
        q.push({deg[i],i});
    }
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(!done[cur.second]){
            nodes=vector<int>();
            for(auto x:matrix[cur.second])nodes.push_back(x);
            go(0);
            done[cur.second]=true;
            for(auto x:matrix[cur.second]){
                matrix[x].erase(cur.second);
                deg[x]--;
                q.push({deg[x],x});
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}