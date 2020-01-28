#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
const int MAXN=2001;
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
lli mandist(int a, int b){
    return abs(loc[a].first.first-loc[b].first.first)+abs(loc[a].first.second-loc[b].first.second);
}
int go(int a, int b){
    if(gone.count(a))return 0;
    if(b==0)return 1;
    //if(best[a][b]!=-1)return best[a][b]; fails on loops
    gone.insert(a);
    return best[a][b]=go(b,st[a][b])+1;
}
void prun(int a, int b){
    if(gone.count(a))return;
    printf("%d ",a);
    cnt++;
    if(b==0)return;
    gone.insert(a);
    prun(b,st[a][b]);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
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
    int best=0;
    int a=-1,b=-1;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                gone.clear();
                int te=go(i,j);
                if(te>best){
                    best=te;
                    a=i,b=j;
                }
            }
        }
    }
    if(best>=(3*n+3)/4){
        printf("%d\n",best);
        gone.clear();
        prun(a,b);
        assert(cnt==best);
    }
    else printf("-1\n");
    return 0;
}