#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
const int MAXN=2001;
const int MAXRND=20;
mt19937 rd(time(NULL));
template <typename T>
int sz(T &a){return (int)a.size();}
pll fix(pll a){
    lli te=__gcd(abs(a.first),abs(a.second));
    return {a.first/te,a.second/te};
}
map<pll,int> to[MAXN];
int st[MAXN][MAXN];
int best[MAXN][MAXN];
pair<pll,pll> loc[MAXN];
set<int> gone;
int cnt=0;
int n;
lli mandist(int a, int b){
    return abs(loc[a].first.first-loc[b].first.first)+abs(loc[a].first.second-loc[b].first.second);
}
vector<int> path;
int go(int a, int b){
    if(gone.count(a))return 0;
    path.push_back(a);
    if(b==0)return 1;
    gone.insert(a);
    return go(b,st[a][b])+1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>loc[i].first.first>>loc[i].first.second>>loc[i].second.first>>loc[i].second.second;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            best[i][j]=-1;
            if(j!=i){
                pll te={loc[j].first.first-loc[i].first.first,loc[j].first.second-loc[i].first.second};
                te=fix(te);
                if(to[i].count(te)){
                    if(mandist(i,to[i][te])>mandist(i,j)){
                        to[i][te]=j;
                    }
                }
                else to[i][te]=j;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            if(j!=i) {
                pll te = {loc[j].first.first-loc[i].first.first,loc[j].first.second-loc[i].first.second};
                te={loc[j].second.first*te.first+loc[j].second.second*te.second,loc[j].second.second*te.first-loc[j].second.first*te.second};
                te = fix(te);
                if(to[j].count(te)){
                    st[i][j]=to[j][te];
                }
            }
        }
    }
    uniform_int_distribution<int> dis(1,n);
    for(int i=1;i<=MAXRND;i++) {
        int cur=dis(rd);
        for (int j = 1; j <= n; j++) {
            if (j != cur) {
                gone.clear();
                path.clear();
                int te=go(i,j);
                go(j,i);
                if(sz(path)-2>=(3*n+3)/4){
                    reverse(path.begin()+te+2,path.end());
                    path.insert(path.begin(),path.begin()+te+2,path.end());
                    for(int l=0;l<(3*n+3)/4;l++)printf("%d ",path[l]);
                    return 0;
                }
                gone.clear();
                path.clear();
                te=go(j,i);
                go(i,j);
                if(sz(path)-2>=(3*n+3)/4){
                    reverse(path.begin()+te+2,path.end());
                    path.insert(path.begin(),path.begin()+te+2,path.end());
                    for(int l=0;l<(3*n+3)/4;l++)printf("%d ",path[l]);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}