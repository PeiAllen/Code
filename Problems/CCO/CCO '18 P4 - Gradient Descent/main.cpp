#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int r,c,k;
map<pii,int> queried;
int query(int x, int y){
    if(x>r||y>c)return INT_MAX;
    if(queried.count({x,y}))return queried[{x,y}];
    printf("? %d %d\n",x,y);
    int s;
    cin>>s;
    return queried[{x,y}]=s;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    cin>>r>>c>>k;
    int xlo=1,xhi=r,ylo=1,yhi=c;
    while(xlo!=xhi||ylo!=yhi){
        int xmid=(xlo+xhi)/2,ymid=(ylo+yhi)/2;
        int val=query(xmid,ymid);
        if(xlo!=xhi){
            if(query(xmid+1,ymid)>val)xhi=xmid;
            else xlo=xmid+1;
        }
        if(ylo!=yhi){
            if(query(xmid,ymid+1)>val)yhi=ymid;
            else ylo=ymid+1;
        }
    }
    printf("! %d",query(xlo,ylo));
    return 0;
}