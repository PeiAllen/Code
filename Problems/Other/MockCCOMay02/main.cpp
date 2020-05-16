#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e4+1;
lli am[MAXN],val[MAXN];
vector<int> matrix[MAXN];
int largest=0;
void dfs(int loc, int parent, int dep){
    largest=max(largest,dep);
    for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    while(m--){
        int n;
        lli k;
        cin>>n>>k;
        int par;
        lli tot=0;
        largest=0;
        for(int i=1;i<=n;i++)matrix[i].clear();
        for(int i=1;i<=n;i++){
            cin>>par>>am[i]>>val[i];
            tot+=am[i];
            if(par>0) {
                matrix[par].push_back(i);
                matrix[i].push_back(par);
            }
        }
        dfs(1,0,1);
        printf("%lli\n",(lli)largest+min(tot,k));
    }
    return 0;
}