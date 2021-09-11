#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3001;
bitset<MN> basis[MN];
bitset<MN> person[MN];
vector<int> adj[MN];
bitset<MN> vectors[MN];
bitset<MN> resultant;
void add(bitset<MN> a, int ind){
    bitset<MN> used;
    used[ind]=true;
    for(int i=MN-1;i>=0;i--){
        if(!(a[i]))continue;
        if (basis[i].none()) {
            basis[i] = a;
            person[i] = used;
            return;
        }
        used ^= person[i];
        a ^= basis[i];
    }
}
bitset<MN> getvectors(bitset<MN> a){
    bitset<MN> used;
    for(int i=MN-1;i>=0;i--){
        if(!(a[i]))continue;
        if (basis[i].none()) {
            assert(0);
        }
        used ^= person[i];
        a ^= basis[i];
    }
    return used;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(auto x:adj[i])vectors[x][i]=true;
        if(sz(adj[i])%2==1){
            vectors[i][i]=true;
            resultant[i]=true;
        }
    }
    for(int i=1;i<=n;i++)add(vectors[i],i);
    bitset<MN> te=getvectors(resultant);
    printf("%d\n",n);
    for(int i=1;i<=n;i++)printf("%d%c",int(te[i])+1," \n"[i==n]);
    return 0;
}