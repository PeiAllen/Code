#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pair<pii,ll> result[7][7];
int front[7][7];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    front[1][3]=5;
    front[1][4]=2;
    front[1][2]=3;
    front[1][5]=4;
    front[6][3]=2;
    front[6][4]=5;
    front[6][2]=4;
    front[6][5]=3;
    front[2][3]=1;
    front[2][4]=6;
    front[2][1]=4;
    front[2][6]=3;
    front[5][3]=6;
    front[5][4]=1;
    front[5][1]=3;
    front[5][6]=4;
    front[3][1]=2;
    front[3][6]=5;
    front[3][2]=6;
    front[3][5]=1;
    front[4][1]=5;
    front[4][6]=2;
    front[4][2]=1;
    front[4][5]=6;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(j!=i&&j+i!=7){
                int curt=i,curr=j;
                ll sum=0;
                for(int k=0;k<c;k++){
                    sum+=curt;
                    if(k!=c-1) {
                        swap(curt,curr);
                        curt = 7 - curt;
                    }
                }
                result[i][j]={{front[curt][curr],7-curr},sum};
            }
        }
    }
    int curt=1,curr=3;
    ll tot=0;
    for(int i=0;i<r;i++){
        auto te=result[curt][curr];
        tot+=te.second;
        curr=te.first.second;
        curt=(i%2==0?te.first.first:7-te.first.first);
    }
    printf("%lli\n",tot);
    return 0;
}