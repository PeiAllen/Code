#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
vector<int> matrix[MN];
bool gone[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,n,a;
    cin>>m>>n;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>a,matrix[a].push_back(i*j);
    queue<int> q;
    gone[m*n]=true,q.push(m*n);
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(auto x:matrix[cur])if(!gone[x])q.push(x),gone[x]=true;
    }
    if(gone[1])printf("yes\n");
    else printf("no\n");
    return 0;
}