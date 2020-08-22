#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
char arr[4001][4001];
bool gone[4001][4001];
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
queue<pii> q;
queue<pii> te;
int h,w;
void floodfill(){
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pii ne={cur.first+xc[i],cur.second+yc[i]};
            if(ne.first>=0&&ne.first<h&&ne.second>=0&&ne.second<w&&arr[ne.first][ne.second]!='.'){
                if(!gone[ne.first][ne.second]) {
                    gone[ne.first][ne.second]=true;
                    if(arr[ne.first][ne.second]==arr[cur.first][cur.second])q.push(ne);
                    else te.push(ne);
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>h>>w;
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    gone[0][0]=true;
    q.push({0,0});
    while(sz(q)){
        floodfill();
        ans++;
        while(sz(te))q.push(te.front()),te.pop();
    }
    printf("%d\n",ans);
    return 0;
}