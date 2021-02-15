#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=4e5+1;
bool gone[MAXN];
vector<int> matrix[MAXN];
void bfs(int loc){
    queue<int> q;
    q.push(loc);
    gone[loc]=true;
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(auto x:matrix[cur]){
            if(!gone[x])gone[x]=true,q.push(x);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
    }
    bfs(1);
    char op;
    while(q--){
        cin>>op>>a;
        if(op=='?'){
            if(gone[a])printf("YES\n");
            else printf("NO\n");
        }
        else{
            cin>>b;
            matrix[a].push_back(b);
            if(gone[a]&&!gone[b])bfs(b);
        }
    }
    return 0;
}