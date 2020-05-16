#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pair<int,lli>> matrix[MAXN];
pair<pll,lli> dist[MAXN];
lli height[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    lli st;
    cin>>n>>m>>st;
    int a,b;
    lli t;
    for(int i=1;i<=n;i++){
        cin>>height[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>t;
        matrix[a].push_back({b,t});
        matrix[b].push_back({a,t});
    }
    lli ans=LLONG_MAX;
    for(lli pen=1;pen<=1;pen++) {
        for (int i = 1; i <= n; i++) {
            dist[i] = {{-1, LLONG_MAX},LLONG_MAX};
        }
        dist[n] = {{height[n], 0},0};
        priority_queue<pair<pll, pair<int, lli>>, vector<pair<pll, pair<int, lli>>>, greater<>> q;
        q.push({{0,0}, {n, height[n]}});
        while (sz(q)) {
            auto cur = q.top();
            q.pop();
            if (dist[cur.second.first] == pair<pll,lli>{pll{cur.second.second, cur.first.first},cur.first.second}) {
                for (auto x:matrix[cur.second.first]) {
                    lli spot = min(height[x.first], cur.second.second + x.second);
                    if (x.second <= height[x.first]) {
                        if (dist[x.first].first.first == -1 ||
                            x.second + cur.first.first + pen*(cur.second.second - (spot - x.second)) + abs(spot-st) <
                            abs(dist[x.first].first.first-st) + dist[x.first].first.second) {
                            dist[x.first] = {{spot, x.second + cur.first.first + pen*(cur.second.second - (spot - x.second))},x.second + cur.first.second + cur.second.second - (spot - x.second)};
                            q.push({{dist[x.first].first.second,dist[x.first].second} ,{x.first, spot}});
                        }
                    }
                }
            }
        }
        if (dist[1].first.first == -1){
            printf("-1\n");
            return 0;
        }
        ans=min(ans,dist[1].second+abs(st-dist[1].first.first));
    }
    printf("%lli\n",ans);
    return 0;
}