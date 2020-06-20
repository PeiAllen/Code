#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e4+1;
vector<pair<int,ll>> matrix[MAXN];
pair<int,ll> dist[2][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    ll c;
    for(int i=1;i<=n;i++)dist[0][i]={INT_MAX,0},dist[1][i]={INT_MAX,0};;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    for(int cs=0;cs<=1;cs++) {
        priority_queue<pair<pair<int, ll>, int>, vector<pair<pair<int, ll>, int>>, greater<>> q;
        dist[cs][1] = {0, 0};
        q.push({{0, 0}, 1});
        while (sz(q)) {
            auto cur = q.top();
            q.pop();
            if (dist[cs][cur.second] <= cur.first) {
                for (auto x:matrix[cur.second]) {
                    pair<int, ll> te = {cur.first.first + 1, cur.first.second +(cs==0?-x.second:x.second)};
                    if (te < dist[cs][x.first]) {
                        dist[cs][x.first] = te;
                        q.push({te, x.first});
                    }
                }
            }
        }
    }
    int q;
    cin>>q;
    string in;
    while(q--){
        cin>>a>>in;
        printf("%d %lli\n",dist[in=="Black"][a].first,abs(dist[in=="Black"][a].second));
    }
    return 0;
}