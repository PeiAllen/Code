#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
 template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
priority_queue<pair<int,short>> row[MN],col[MN];
int val[MN][MN];
ll ans=0;
set<short> toupdate;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>val[i][j];
            row[i].push({val[i][j],j}),col[j].push({val[i][j],i});
        }
    }
    for(int i=0;i<n;i++)if(row[i].top().first!=col[i].top().first)toupdate.insert(i);
    while(sz(toupdate)){
        int cur=*toupdate.begin();
        toupdate.erase(toupdate.begin());
        while(row[cur].top().first!=val[cur][row[cur].top().second])row[cur].pop();
        while(col[cur].top().first!=val[col[cur].top().second][cur])col[cur].pop();
        if(row[cur].top().first<col[cur].top().first){
            ll v=row[cur].top().first;
            while(col[cur].top().first>v){
                pair<ll,int> te=col[cur].top();
                col[cur].pop();
                if(te.first==val[te.second][cur]) {
                    col[cur].push({v, te.second});
                    row[te.second].push({v, cur});
                    val[te.second][cur]=v;
                    ans += te.first - v;
                    toupdate.insert(te.second);
                }
            }
        }
        else if(row[cur].top().first>col[cur].top().first){
            ll v=col[cur].top().first;
            while(row[cur].top().first>v){
                pair<ll,int> te=row[cur].top();
                row[cur].pop();
                if(te.first==val[cur][te.second]) {
                    row[cur].push({v, te.second});
                    col[te.second].push({v, cur});
                    val[cur][te.second]=v;
                    ans += te.first - v;
                    toupdate.insert(te.second);
                }
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}