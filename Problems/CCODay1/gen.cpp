#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=8e5+1;
vector<int> adj[MN];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(stoi(argv[1]));
    int n=8,q=2000;
    printf("%d %d\n",n,q);
    for(int i=2;i<=n;i++){
        uniform_int_distribution<int> rnd(1,i-1);
        int p=rnd(gen);
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    for(int i=1;i<=n;i++){
        uniform_int_distribution<int> rnd(0,sz(adj[i])-1);
        int st=rnd(gen);
        rotate(adj[i].begin(),adj[i].begin()+st,adj[i].end());
        printf("%d ",sz(adj[i]));
        for(int j=0;j<sz(adj[i]);j++){
            printf("%d%c",adj[i][j]," \n"[j==sz(adj[i])-1]);
        }
    }
    uniform_int_distribution<ll> rnd2(ll(1),ll(n)*ll(n)+ll(2*n));
    while(q--){
        printf("%lli\n",rnd2(gen));
    }
    return 0;
}