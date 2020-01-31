#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
const int MAXN=100001;
const int MAXRND=4;
mt19937 rd(time(NULL));
template <typename T>
int sz(T &a){return (int)a.size();}
pll fix(pll a){
    lli te=__gcd(abs(a.first),abs(a.second));
    return {a.first/te,a.second/te};
}
pair<pll,pll> loc[MAXN];
map<pll,int> at;
set<int> gone;
int n;
lli ma=1e6;
int st(int i, int j){
    pll te = {loc[j].first.first-loc[i].first.first,loc[j].first.second-loc[i].first.second};
    te={loc[j].second.first*te.first+loc[j].second.second*te.second,loc[j].second.second*te.first-loc[j].second.first*te.second};
    te = fix(te);
    pll cur=loc[j].first;
    cur.first+=te.first;
    cur.second+=te.second;
    while(cur.first<=ma&&cur.first>=1&&cur.second<=ma&&cur.second>=1){
        if(at.count(cur))return at[cur];
        cur.first+=te.first;
        cur.second+=te.second;
    }
    return 0;
}
vector<int> ans;
vector<int> path;
int go(int a, int b){
    if(gone.count(a))return 0;
    path.push_back(a);
    gone.insert(a);
    if(b==0)return 1;
    return go(b,st(a,b))+1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>loc[i].first.first>>loc[i].first.second>>loc[i].second.first>>loc[i].second.second;
        at[loc[i].first]=i;
    }
    uniform_int_distribution<int> dis(1,n);
    for(int i=1;i<=MAXRND;i++) {
        int cur=dis(rd);
        for (int j = 1; j <= n; j++) {
            if (j != cur) {
                gone.clear();
                path.clear();
                int te=go(cur,j);
                gone.erase(cur);
                gone.erase(j);
                go(j,cur);
                if(sz(path)-2>=(3*n+3)/4){
                    reverse(path.begin()+te+2,path.end());
                    ans.insert(ans.begin(),path.begin()+te+2,path.end());
                    ans.insert(ans.end(),path.begin(),path.begin()+te);
                    for(int l=0;l<(3*n+3)/4;l++)printf("%d ",ans[l]);
                    return 0;
                }
                gone.clear();
                path.clear();
                te=go(j,cur);
                gone.erase(cur);
                gone.erase(j);
                go(cur,j);
                if(sz(path)-2>=(3*n+3)/4){
                    reverse(path.begin()+te+2,path.end());
                    ans.insert(ans.begin(),path.begin()+te+2,path.end());
                    ans.insert(ans.end(),path.begin(),path.begin()+te);
                    for(int l=0;l<(3*n+3)/4;l++)printf("%d ",ans[l]);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}