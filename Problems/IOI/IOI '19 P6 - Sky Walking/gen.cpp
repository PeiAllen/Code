#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<int,set<pii>> bridges;
int height[100000];
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=15,m=rnd.next(15,20);
    printf("%d %d\n",n,m);
    set<int> locs;
    for(int i=0;i<n;i++){
        while(1) {
            int loc = rnd.next(0, (int) 1e9);
            if(!locs.count(loc)){
                locs.insert(loc);
                break;
            }
        }
    }
    int reei=0;
    for(auto x:locs){
        height[reei]=100;
        printf("%d %d\n",x,100);
        reei++;
    }
    for(int i=0;i<m;i++){
        while(1) {
            int l = rnd.next(0, n - 2), r = rnd.next(l + 1, n - 1);
            int hei = rnd.next(1,min(height[l],height[r]));
            if(bridges.count(hei)){
                auto it=bridges[hei].lower_bound({l,r});
                if(it!=bridges[hei].end()||it->first>=r){
                    if(it==bridges[hei].begin()||prev(it,1)->second<=l){
                        bridges[hei].insert({l,r});
                        printf("%d %d %d\n",l,r,hei);
                        break;
                    }
                }
            }
            else{
                bridges[hei].insert({l,r});
                printf("%d %d %d\n",l,r,hei);
                break;
            }
        }
    }
    int a=rnd.next(0,n-1);
    int b;
    while(1){
        b=rnd.next(0,n-1);
        if(b!=a)break;
    }
    printf("%d %d\n",a,b);
    return 0;
}