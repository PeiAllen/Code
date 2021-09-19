#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=1e5+1;
int parent[MN];
int deg[MN];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=stoi(argv[1]),t=stoi(argv[2]), it=stoi(argv[3]);//t is the type, 1 for star, 2 for line
    printf("%d\n",n);
    for(int i=1;i<n;i++){
        parent[i]=(t==1?0:i-1);
    }
    vector<int> perm(n);
    for(int i=0;i<n;i++)perm[i]=i+1;
    shuffle(perm.begin(),perm.end());
    vector<pii> edges;
    for(int i=1;i<n;i++){
        edges.push_back({perm[parent[i]],perm[i]});
    }
    shuffle(edges.begin(),edges.end());
    for(auto x:edges)printf("%d %d\n",x.first,x.second),deg[x.first]++,deg[x.second]++;
    vector<int> leaves,oth;
    for(int i=1;i<=n;i++){
        if(deg[i]==1)leaves.push_back(i);
        else oth.push_back(i);
    }
    if(t==1){
        if(it==1){//a=b=f=center
            printf("%d %d\n",oth[0],oth[0]);
            printf("%d\n",oth[0]);
        }
        else if(it==2){//f=center, a or b = center
            if(rnd.next(0,1))printf("%d %d\n",oth[0],leaves[rnd.next(0,sz(leaves)-1)]);
            else printf("%d %d\n",leaves[rnd.next(0,sz(leaves)-1)],oth[0]);
            printf("%d\n",oth[0]);
        }
        else if(it==3){//f=not center, a or b = center
            int leafnode=leaves[rnd.next(0,sz(leaves)-1)];
            if(rnd.next(0,1))printf("%d %d\n",oth[0],leafnode);
            else printf("%d %d\n",leafnode,oth[0]);
            printf("%d\n",leafnode);
        }
        else if(it==4){//f=center, a and b not center
            shuffle(leaves.begin(),leaves.end());
            printf("%d %d\n",leaves[0],leaves[1]);
            printf("%d\n",oth[0]);
        }
        else if(it==5){//f=a or b, a and b not center
            shuffle(leaves.begin(),leaves.end());
            printf("%d %d\n",leaves[0],leaves[1]);
            printf("%d\n",oth[rnd.next(0,1)]);
        }
        else if(it==6){//f=a=b=leaf
            int leafnode=leaves[rnd.next(0,sz(leaves)-1)];
            printf("%d %d\n",leafnode,leafnode);
            printf("%d\n",leafnode);
        }
    }
    else if(t==2){
        int a=rnd.next(1,n),b=rnd.next(1,n);
        printf("%d %d\n",a,b);
        // ========= OUTPUT NODE ON PATH ===============
        auto outputNodeOnPath = [] (int N, vector<pii> edges, int A, int B, int type) {
            vector<vector<int>> g(N+1);
            for (auto [a, b] : edges) {
                g[a].push_back(b);
                g[b].push_back(a);
            }
            vector<int> path;
            function<bool(int, int, int)> getPath = [&] (int c, int p, int end) {
                if (c == end) {
                    path.push_back(c);
                    return true;
                }
                bool ok = false;
                for (auto to : g[c]) {
                    if (to != p) {
                        ok |= getPath(to, c, end);
                    }
                }
                if (ok) path.push_back(c);
                return ok;
            };
            getPath(A, -1, B);
            if(type==1){//random F
                printf("%d\n", path[rnd.next(0, (int)path.size()-1)]);
            }
            else if(type==2){//random endpoint
                if(rnd.next(0,1)==0)printf("%d\n",path[0]);
                else printf("%d\n",path[sz(path)-1]);
            }
            else assert(0);
        };
        // ========= OUTPUT NODE ON PATH ===============
        outputNodeOnPath(n, edges, a, b,it);
    }
    return 0;
}
