#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=7;
bool gone[MN][MN];
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
char type[4]={'D','U','R','L'};
string a;
bool good(int x, int y){
    return x>=0&&x<7&&y>=0&&y<7&&!gone[x][y];
}
int solve(int x, int y, int movecnt){
    if(movecnt==sz(a)){
        return pii{x,y}==pii{6,0};
    }
    if(pii{x,y}==pii{6,0})return 0;
    gone[x][y]=true;
    int am=0;
    for(int i=0;i<4;i++){
        if(a[movecnt]=='?'||type[i]==a[movecnt]){
            int nx=x+xc[i],ny=y+yc[i];
            if(good(nx,ny)){
                int nnx=nx+xc[i],nny=ny+yc[i];
                int oth=2*(!(i/2));
                if(!good(nnx,nny)&&good(nx+xc[oth],ny+yc[oth])&&good(nx+xc[oth+1],ny+yc[oth+1])){
                    continue;
                }
                am+=solve(nx,ny,movecnt+1);
            }
        }
    }
    gone[x][y]=false;
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>a;
    printf("%d\n",solve(0,0,0));
    return 0;
}