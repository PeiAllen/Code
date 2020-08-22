#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
ll dp[MAXN];
int parent[MAXN];
pll loc[MAXN];
ll cost[MAXN];
const ll NEG_INF=LLONG_MIN/2;
struct Line {
    ll b, loc;
    Line(ll m = 0, ll b = 1) : loc(m), b(b) {}
    ll eval(ll x) const { return b == 1 ? NEG_INF : b-(loc-x)*(loc-x); }
    bool majorize(const Line &line, ll l, ll r) const { return eval(l) >= line.eval(l) && eval(r) >= line.eval(r); }
};

// Supports adding lines in the form f(x) = mx + b and finding the maximum value of f(x) at any value of x
// along with line segments where l <= x <= r, in any order
// Time Complexity:
//   addLine: O(log (MX - MN))
//   addLineSegment: O((log (MX - MN))^2)
//   getMax: O(log (MX - MN))
// Memory Complexity: O(N log (MX - MN)) where N is the number of lines added
template <const bool maxHull> struct DynamicLiChaoTree {
    struct Node {
        Line line; ll l, r;
        Node(const Line &line = Line()) : line(line), l(-1), r(-1) {}
    };
    int root = -1; vector<Node> TR; ll MN, MX;
    DynamicLiChaoTree(ll MN, ll MX) : MN(MN), MX(MX) {}
    int addLine(int cur, ll tl, ll tr, Line line) {
        if (cur == -1) { cur = int(TR.size()); TR.emplace_back(); }
        if (line.majorize(TR[cur].line, tl, tr)) swap(line, TR[cur].line);
        if (TR[cur].line.majorize(line, tl, tr)) return cur;
        if (TR[cur].line.eval(tl) < line.eval(tl)) swap(line, TR[cur].line);
        ll m = tl + (tr - tl) / 2;
        if (line.eval(m) >= TR[cur].line.eval(m)) { swap(line, TR[cur].line); int cl = addLine(TR[cur].l, tl, m, line); TR[cur].l = cl; }
        else { int cr = addLine(TR[cur].r, m + 1, tr, line); TR[cur].r = cr; }
        return cur;
    }
    int addLineSegment(int cur, ll tl, ll tr, ll l, ll r, Line line) {
        if (r < tl || tr < l) return cur;
        if (l <= tl && tr <= r) return addLine(cur, tl, tr, line);
        if (cur == -1) { cur = int(TR.size()); TR.emplace_back(); }
        ll m = tl + (tr - tl) / 2;
        int cl = addLineSegment(TR[cur].l, tl, m, l, r, line), cr = addLineSegment(TR[cur].r, m + 1, tr, l, r, line);
        TR[cur].l = cl; TR[cur].r = cr; return cur;
    }
    ll getMax(int cur, ll tl, ll tr, ll x) {
        if (cur == -1) return NEG_INF;
        ll ret = TR[cur].line.eval(x); ll m = tl + (tr - tl) / 2;
        if (x <= m) return max(ret, getMax(TR[cur].l, tl, m, x));
        else return max(ret, getMax(TR[cur].r, m + 1, tr, x));
    }
    void addLine(Line line) { root = addLine(root, MN, MX, maxHull ? line : Line(line.loc, -line.b)); }
    void addLineSegment(Line line, ll l, ll r) { root = addLineSegment(root, MN, MX, l, r, maxHull ? line : Line(line.loc, -line.b)); }
    ll getMax(ll x) { ll ret = getMax(root, MN, MX, x); return maxHull ? ret : -ret; }
};
DynamicLiChaoTree<false> tree(0,1e6);
int main(){//should wa
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>loc[i].first>>loc[i].second>>cost[i]>>parent[i];
    }
    if(n<=5001) {
        dp[n] = 0;
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = LLONG_MAX;
            for (int j = parent[i]; j != 0; j = parent[j]) {
                dp[i] = min(dp[i], dp[j] + cost[j] + (loc[i].first - loc[j].first) * (loc[i].first - loc[j].first) +
                                   (loc[i].second - loc[j].second) * (loc[i].second - loc[j].second));
            }
        }
        for (int i = 1; i <= n; i++)printf("%lli\n", dp[i]);
    }
    else{
        dp[n]=0;
        tree.addLine(Line(loc[n].second,cost[n]));
        for(int i=n-1;i>=1;i--){
            dp[i]=tree.getMax(loc[i].second);
            tree.addLine(Line(loc[i].second,dp[i]+cost[i]));
        }
        for (int i = 1; i <= n; i++)printf("%lli\n", dp[i]);
    }
    return 0;
}