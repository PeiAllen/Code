#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int am=1;
    while(20+(am+1)*4+3*((am+1)+2)<=1e5)am++;
    int n=20+am*4+3*(am+2);
    printf("%d\n",n);
    vector<pii> edges;
    edges.push_back({1,7});
    edges.push_back({2,7});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({1,5});
    edges.push_back({1,6});
    for(int i=8;i<=20;i++){
        edges.push_back({i-1,i});
    }
    int curnode=21;
    for(int i=0;i<am;i++){
        edges.push_back({3,curnode});
        edges.push_back({curnode,curnode+1});
        edges.push_back({curnode,curnode+2});
        edges.push_back({curnode,curnode+3});
        curnode+=4;
    }
    for(int i=4;i<=6;i++){
        for(int j=0;j<am+2;j++){
            edges.push_back({i,curnode});
            curnode+=1;
        }
    }
    vector<int> p(n+1);
    for(int i=1;i<=n;i++)p[i]=i;
    shuffle(p.begin()+1,p.end());
    shuffle(edges.begin(),edges.end());
    for(auto x:edges){
        printf("%d %d\n",p[x.first],p[x.second]);
    }
    printf("%d %d\n",p[22],p[n]);
    printf("%d\n",p[1]);
    return 0;
}