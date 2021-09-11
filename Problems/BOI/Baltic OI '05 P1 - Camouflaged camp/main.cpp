#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
int psa[MAXN][MAXN];
int am[MAXN][MAXN];
struct characteristics{
    pii loc,diem;
    bool arr,alt;
    characteristics(){
        loc={0,0},diem={0,0},arr=false,alt=false;
    }
}ch;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>psa[i][j];
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    int l,w;
    cin>>l>>w;
    int h;
    cin>>h;
    for(int i=0;i<h;i++){
        cin>>ch.loc.first>>ch.loc.second>>ch.diem.first>>ch.diem.second>>ch.arr>>ch.alt;
        for(int x=ch.loc.first;x-ch.loc.first+1+l-1<=r;x++){
            for(int y=ch.loc.second;y-ch.loc.second+1+w-1<=c;y++){
                bool work;
                if(ch.arr)work=(psa[x+ch.diem.first-1][y+ch.diem.second-1]-psa[x-1][y+ch.diem.second-1]-psa[x+ch.diem.first-1][y-1]+psa[x-1][y-1]<psa[x+ch.diem.first-1+1+ch.diem.first-1][y+ch.diem.second-1]-psa[x-1+1+ch.diem.first-1][y+ch.diem.second-1]-psa[x+ch.diem.first-1+1+ch.diem.first-1][y-1]+psa[x-1+1+ch.diem.first-1][y-1])^ch.alt;
                else work=(psa[x+ch.diem.first-1][y+ch.diem.second-1]-psa[x-1][y+ch.diem.second-1]-psa[x+ch.diem.first-1][y-1]+psa[x-1][y-1]<psa[x+ch.diem.first-1][y+ch.diem.second-1+1+ch.diem.second-1]-psa[x-1][y+ch.diem.second-1+1+ch.diem.second-1]-psa[x+ch.diem.first-1][y-1+1+ch.diem.second-1]+psa[x-1][y-1+1+ch.diem.second-1])^ch.alt;
                am[x-ch.loc.first+1][y-ch.loc.second+1]+=work;
            }
        }
    }
    int best=-1;
    pii ans={-1,-1};
    for(int i=1;i+l-1<=r;i++){
        for(int j=1;j+w-1<=c;j++){
            if(am[i][j]>best){
                best=am[i][j];
                ans={i,j};
            }
        }
    }
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}