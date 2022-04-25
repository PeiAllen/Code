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
    int m=20,t=rnd.next(1,1000);
    printf("%d %d\n",m,t);
    vector<pii> things;
    for(int i=0;i<m;i++){
        int n=rnd.next(1,50),needed=rnd.next(0,min(100,t));
        t-=needed;
        if(i==m-1&&t>40){
            int fix=(t-40+rnd.next(0,40));
            t-=fix,needed+=fix;
        }
        printf("%d %d\n",n,needed);
        for(int j=1;j<=n;j++){
            things.push_back({i+1,j});
            printf("%d %d\n",rnd.next(1,3),rnd.next(1,100));
        }
    }
    int p=rnd.next(1,6);
    printf("%d\n",p);
    for(int i=1;i<=p;i++){
        int type=rnd.next(1,3);
        int a=rnd.next(0,sz(things)-2),b=rnd.next(a+1,sz(things)-1);
        if(type<=2)printf("%d %d %d %d %d %d\n",type,things[a].first,things[a].second,things[b].first,things[b].second,rnd.next(1,100));
        else printf("%d %d %d %d %d\n",type,things[a].first,things[a].second,things[b].first,things[b].second);
    }
    return 0;
}