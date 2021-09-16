#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int N = 3002, MM = N*N;

int n, m, a[N], id[N][N], t, top[N];
string s[N];
int blue[MM];
vector<int> adj1[MM], adj2[MM];
bool ins[MM];
int path[MM], ptr, tt, dfn[MM], low[MM], sid[MM];

bool bad[MM];

bool vis[MM];
int dpl[MM], dpr[MM];

int rs[MM];
int dfscnt=0;
void dfs0(int cur){

        dfscnt++;
        assert(dfscnt<=t);
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++tt;

    for(int u: adj1[cur]){
        if(!dfn[u]){
            dfs0(u);
            low[cur] = min(low[cur], low[u]);
        }
        else if(ins[u])
            low[cur] = min(low[cur], dfn[u]);
    }

    if(dfn[cur] == low[cur]){
        int u = -1;
        while(u != cur){
            u = path[ptr--];
            ins[u] = 0;
            sid[u] = cur;
            blue[cur] |= blue[u];
        }
    }
}

void dfs1(int cur){
    if(bad[cur])
        return;
    for(int u: adj2[cur]){
        dfs1(u);
        bad[u] = 1;
    }
}

void dfs2(int cur){
    if(vis[cur])
        return;
    vis[cur] = 1;

    for(int u: adj2[cur]){
        dfs2(u);
        dpl[cur] = min(dpl[cur], dpl[u]);
        dpr[cur] = max(dpr[cur], dpr[u]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("C:\\Users\\allen\\Documents\\Github\\Code\\Problems\\CFRound\\E. Falling Sand\\breakeric","r",stdin);
    cin>>n>>m;
    for(int i = n; i; i--)
        cin>>s[i];
    for(int i = 1; i <= m; i++)
        cin>>a[i];

    //so that lower # nodes are on left
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(s[i][j-1] == '#')
                id[i][j] = ++t;
        }
    }
    auto addedge = [](int a, int b){
        if(a == b) return;
        adj1[a].emplace_back(b);
    };

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(id[i][j]){
                int cur = id[i][j];
                if(!--a[j])
                    blue[cur] = 1;



                if(top[j-1]) addedge(cur, top[j-1]);
                if(top[j]) addedge(cur, top[j]);
                if(top[j+1]) addedge(cur, top[j+1]);

                //directly connected
                if(id[i-1][j])
                    addedge(id[i-1][j], cur);
                if(id[i][j-1])
                    addedge(id[i][j-1], cur);

                top[j] = id[i][j];
            }
        }
    }

    for(int j = 1; j <= m; j++){
        if(a[j] > 0){
            cout<<"-1\n";
            return 0;
        }
    }

    for(int i = 1; i <= t; i++){
        if(!dfn[i]){
            dfs0(i);
        }
    }

    for(int cur = 1; cur <= t; cur++){
        for(int u: adj1[cur]){
            if(sid[cur] != sid[u])
                adj2[sid[cur]].emplace_back(sid[u]);
        }
    }

    for(int i = 1; i <= t; i++){
        if(sid[i] != i) continue;
        if(blue[i]){
            dfs1(i);
        }
    }
    //good ones are blue and dp1[cur] = 0


    for(int i = 1; i <= t; i++){
        if(sid[i] != i) continue;
        if(blue[i] and !bad[i])
            dpl[i] = dpr[i] = i;
        else
            dpl[i] = INT_MAX/3, dpr[i] = -1;
        sort(all(adj2[i]));
    }

    for(int i = 1; i <= t; i++){
        if(sid[i] != i) continue;
        dfs2(i);
        if(dpr[i] != -1){
            rs[dpl[i]] = max(rs[dpl[i]], dpr[i]);
        }
    }

    for(int i = 1; i <= t; i++)
        rs[i] = max(rs[i], rs[i-1]);

    int ans = 0, i = 0;
    while(i <= t){
        if(sid[i] == i and blue[i] and !bad[i]){
            ans++;
            i = rs[i];
        }
        i++;
    }

    cout<<ans<<'\n';
}