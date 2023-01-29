#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=102;
int xc[4]={0,1,0,-1},yc[4]={-1,0,1,0};
vector<pii> adj[MN*MN*8];//(enter,leave)-> left, bottom, right, top
bool spec[MN][MN];
int dist[MN*MN*8];
int n,m;
int getindex(int a, int b){
    return ((a-1)*m+b)*8;
}
int getdist(int a, int b){
    for(int i=getindex(1,1);i<getindex(n,m)+8;i++){
        dist[i]=INT_MAX;
    }
    dist[a]=0;
    priority_queue<pii,vector<pii>,greater<>> q;
    q.push({0,a});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second])continue;
        for(auto x:adj[cur.second]){
            if(cur.first+x.second<dist[x.first]){
                dist[x.first]=cur.first+x.second;
                q.push({dist[x.first],x.first});
            }
        }
    }
    return dist[b];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int c;
    cin>>n>>m>>c;
    int px,py,dx,dy;
    cin>>px>>py>>dx>>dy;
    int cx,cy;
    int right,left,straight;
    for(int i=1;i<=c;i++){
        cin>>cx>>cy>>straight>>right>>left;
        spec[cx][cy]=true;
        int index=getindex(cx,cy);
        for(int j=0;j<4;j++){
            adj[index+j].push_back({index+4+(j+2)%4,straight});
            adj[index+j].push_back({index+4+(j-1+4)%4,left});
            adj[index+j].push_back({index+4+(j+1)%4,right});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int index=getindex(i,j);
            if(!spec[i][j]){
                for(int k=0;k<4;k++){
                    if(i==1&&j==1){
                        adj[index+k].push_back({index+4+(k+2)%4,0});
                        adj[index+k].push_back({index+4+(k-1+4)%4,0});
                        adj[index+k].push_back({index+4+(k+1)%4,0});
                    }
                    else{
                        adj[index+k].push_back({index+4+(k+2)%4,1});
                        adj[index+k].push_back({index+4+(k-1+4)%4,3});
                        adj[index+k].push_back({index+4+(k+1)%4,2});
                    }
                }
            }
            for(int k=0;k<4;k++){
                int nx=i+xc[k],ny=j+yc[k];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
                    adj[index+k+4].push_back({getindex(nx,ny)+(k+2)%4,1});
                }
            }
        }
    }
    int best=INT_MAX;
    int stop=getindex(1,1),pickup=getindex(px,py),dropoff=getindex(dx,dy);
    for(int start=1;start<=2;start++){
        for(int pick=0;pick<4;pick++){
            for(int drop=0;drop<4;drop++){
                for(int end=1;end<=2;end++){
                    int trek1=getdist(stop+4+start,pickup+pick);
                    int trek2=getdist(pickup+pick,dropoff+drop);
                    int trek3=getdist(dropoff+drop,stop+end);
                    if(trek1!=INT_MAX&&trek2!=INT_MAX&&trek3!=INT_MAX)best=min(best,trek1+trek2+trek3);
                }
            }
        }
    }
    printf("%d\n",best);
    return 0;
}