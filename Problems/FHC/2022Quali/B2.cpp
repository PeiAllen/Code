#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=3001;
char arr[MN][MN];
int possfriends[MN][MN];
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int r,c;
        cin>>r>>c;
        queue<pii> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='#'){
                    possfriends[i][j]=0;
                }
                else{
                    possfriends[i][j]=0;
                    for(int k=0;k<4;k++){
                        pii nx={i+xc[k],j+yc[k]};
                        if(nx.first>=0&&nx.first<r&&nx.second>=0&&nx.second<c){
                            possfriends[i][j]++;
                        }
                    }
                }
                if(possfriends[i][j]<2){
                    q.push({i,j});
                }
            }
        }
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                pii nx={cur.first+xc[i],cur.second+yc[i]};
                if(nx.first>=0&&nx.first<r&&nx.second>=0&&nx.second<c){
                    possfriends[nx.first][nx.second]--;
                    if(possfriends[nx.first][nx.second]==1){
                        q.push(nx);
                    }
                }
            }
        }
        bool work=true;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(possfriends[i][j]<2&&arr[i][j]=='^'){
                    work=false;
                }
            }
        }
        printf("Case #%d: ",cs);
        if(!work){
            printf("Impossible\n");
        }
        else{
            printf("Possible\n");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(arr[i][j]=='#'){
                        printf("#");
                    }
                    else if(possfriends[i][j]<2){
                        printf(".");
                    }
                    else{
                        printf("^");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}