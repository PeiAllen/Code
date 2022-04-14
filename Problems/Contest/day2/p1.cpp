#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2501;
struct sam{
    struct node{
        int link,len,endpos;
        int to[26];
        node(int l, int p){
            for(int i=0;i<26;i++)to[i]=-1;
            link=-1;
            len=l,endpos=p;
        }
    };
    vector<node> t;
    int last;
    sam(){
        t={node(0,-1)};
        last=0;
    }
    void addchar(int c, int end){
        int cur=sz(t);
        int p=last;
        t.push_back(node(t[p].len+1,end));
        while(p!=-1&&t[p].to[c]==-1)t[p].to[c]=cur,p=t[p].link;
        if(p==-1){
            t[cur].link=0;
        }
        else{
            int oth=t[p].to[c];
            if(t[oth].len==t[p].len+1){
                t[cur].link=oth;
            }
            else{
                int clone=sz(t);
                t.push_back(node(t[p].len+1,-1));
                for(int i=0;i<26;i++)t[clone].to[i]=t[oth].to[i];
                t[clone].link=t[oth].link;
                t[oth].link=t[cur].link=clone;
                while(p!=-1&&t[p].to[c]==oth)t[p].to[c]=clone,p=t[p].link;
            }
        }
        last=cur;
    }
}solver;
vector<int> endpos[2*MN];
int jump[__lg(MN)+1][MN+1];
vector<int> adj[2*MN];
ll matrix[2*MN][2*MN];
ll dist[2*MN];
void dfs(int loc){
    if(solver.t[loc].endpos!=-1)endpos[loc].push_back(solver.t[loc].endpos);
    for(auto x:adj[loc]) {
        dfs(x);
        vector<int> nexendpos(sz(endpos[loc]) + sz(endpos[x]));
        merge(endpos[loc].begin(), endpos[loc].end(), endpos[x].begin(), endpos[x].end(), nexendpos.begin());
        endpos[loc] = nexendpos;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a,b,c;
    string s;
    cin>>s;
    cin>>a>>b>>c;
    for(int i=0;i<n;i++){
        solver.addchar(s[i]-'a',i);
    }
    for(int i=1;i<sz(solver.t);i++){
        dist[i]=LLONG_MAX;
        adj[solver.t[i].link].push_back(i);
    }
    dfs(0);
    for(int i=0;i<sz(solver.t);i++){
        int pclg=__lg(sz(endpos[i]));
        if(i>0) {
            int ptr = 0;
            for (int j = 0; j < sz(endpos[i]); j++) {
                while (ptr < sz(endpos[i]) && endpos[i][ptr] - solver.t[i].len + 1 <= endpos[i][j])ptr++;
                jump[0][j] = ptr;
            }
            jump[0][sz(endpos[i])] = sz(endpos[i]);
            endpos[i].push_back(2 * n);
            for (int j = 1; j <= pclg; j++) {
                for (int k = 0; k < sz(endpos[i]); k++) {
                    jump[j][k] = jump[j - 1][jump[j - 1][k]];
                }
            }
        }
        for(int j=0;j<sz(solver.t);j++){
            if(i==j)matrix[i][j]=0;
            else{
                int stpos=endpos[j][0]-solver.t[j].len+1;
                int enpos=endpos[j][0];
                int fi=lower_bound(endpos[i].begin(),endpos[i].end(),stpos+solver.t[i].len-1)-endpos[i].begin();
                ll ampaste=0;
                if(i>0&&endpos[i][fi]<=enpos){
                    ampaste=1;
                    for(int k=pclg;k>=0;k--){
                        if(endpos[i][jump[k][fi]]<=enpos){
                            ampaste+=(1<<k);
                            fi=jump[k][fi];
                        }
                    }
                }
                matrix[i][j]=min(solver.t[j].len*a,(solver.t[j].len-ampaste*solver.t[i].len)*a+ampaste*c)+b;
            }
        }
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    q.push({0,0});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first>dist[cur.second])continue;
        if(cur.second==solver.last){
            printf("%lli\n",cur.first-b);
            return 0;
        }
        for(int i=0;i<sz(solver.t);i++){
            if(dist[i]>cur.first+matrix[cur.second][i]){
                dist[i]=cur.first+matrix[cur.second][i];
                q.push({dist[i],i});
            }
        }
    }
    return 0;
}