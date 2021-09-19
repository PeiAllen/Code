#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

vi adjList[100000];
int dp[100000],node[100000];
vpii cc[100000];
int doDFS(int u,int p) {
    int i;
    vpii c;
    cc[u].clear();
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u),c.pb(mp(dp[v],v));
    }
    if (c.empty()) dp[u] = 0,node[u] = u;
    else {
        dp[u] = 0;
        sort(c.begin(),c.end(),greater<pii>());
        node[u] = node[c[0].second];
        for (i = 0; i < c.size(); i++) dp[u] = max(dp[u],max(c[i].first,1)+i);
        cc[u] = c;
    }
    return 0;
}
int size[100000],parent[100000],f;
int doDFS2(int u,int p) {
    int i;
    parent[u] = p,size[u] = f ? 1:adjList[u].size();
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS2(v,u);
    }
    return size[u];
}
int doDFS3(int u,int p) {
    int i;
    parent[u] = p,size[u] = (adjList[u].size()==1);
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS2(v,u);
    }
    return size[u];
}
int main() {
    int i;
    int n,u,v;
    cin >> n;
    for (i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    if (n == 1) {
        int l;
        cout << 0 << endl;
        cin >> l;
        cout << "! " << 1 << " " << 1 << endl;
        return 0;
    }

    int j,m = 0;
    vi cand;
    doDFS3(0,-1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if ((v != parent[i]) && (size[v] > size[0]/2)) break;
            else if ((v == parent[i]) && (size[0]-size[i] > size[0]/2)) break;
        }
        if (j == adjList[i].size()){
            printf("%d %d\n",i,int(adjList[i].size()));
            cand.pb(i);
        }
    }
    int k;
    for (k = 0; k < cand.size(); k++) {
        i = cand[k];
        doDFS(i,-1);
        vi c;
        for (j = 0; j < cc[i].size(); j++) c.pb(cc[i][j].first);
        sort(c.begin(),c.end(),greater<int>());
        for (j = 0; j < c.size(); j++) {
            if (j == 0) m = max(m,max(c[j],1));
            else m = max(m,max(c[0],1)+max(c[j],1)+j-1);
        }
    }
    cout << m << endl;
    int f;
    cin >> f,f--;
    doDFS(f,-1);
    vpii c;
    for (i = 0; i < adjList[f].size(); i++) c.pb(mp(dp[adjList[f][i]],adjList[f][i]));
    sort(c.begin(),c.end(),greater<pii>());
    vpii qq;
    for (i = 0; i < c.size(); i++) {
        int l;
        cout << "? " << node[c[i].second]+1 << endl;
        cin >> l,l--;
        if (l != f) qq.pb(mp(node[c[i].second],l));
        if (qq.size() == 2) break;
    }
    vi ans;
    if (qq.size() == 0) ans.pb(f),ans.pb(f);
    else if (qq.size() == 1) ans.pb(f);
    for (i = 0; i < qq.size(); i++) {
        int u = qq[i].second;
        while (1) {
            int f = 0;
            for (j = 1; j < cc[u].size(); j++) {
                int l;
                cout << "? " << node[cc[u][j].second]+1 << endl;
                cin >> l,l--;
                if (l != u) {
                    u = l;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans.pb(u);
                break;
            }
        }
    }
    cout << "! " << ans[0]+1 << " " << ans[1]+1 << endl;

    return 0;
}