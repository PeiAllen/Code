#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pll indation[MAXN];
ll cost[MAXN];
ll ans[MAXN];
vector<int> matrix[MAXN];
int n;
struct point{
    ll di[3];
    point(){
        di[0]=0,di[1]=0,di[2]=0;
    }
    point(ll X, ll Y, ll Z){
        di[0]=X,di[1]=Y,di[2]=Z;
    }
    ll dist(point a){
        return (a.di[0]-di[0])*(a.di[0]-di[0])+(a.di[1]-di[1])*(a.di[1]-di[1])+abs(a.di[2]-di[2]);
    }
};
struct kd{
    struct node{
        point data;
        pair<point,point> bound;
        int ch[2];
        node(){
            data=point(),ch[0]=-1,ch[1]=-1,bound={point(),point()};
        }
        node(point a){
            data=a,bound={a,a};
            ch[0]=-1,ch[1]=-1;
        }
    };
    vector<node> t;
    kd(){
        t={node()};
    }
    void pushup(int ind){
        t[ind].bound={t[ind].data,t[ind].data};
        for(int i=0;i<2;i++)for(int j=0;j<3;j++)if(t[ind].ch[i]!=-1){
            t[ind].bound.first.di[j]=min(t[ind].bound.first.di[j],t[t[ind].ch[i]].bound.first.di[j]);
            t[ind].bound.second.di[j]=max(t[ind].bound.second.di[j],t[t[ind].ch[i]].bound.second.di[j]);
        }
    }
    int insert(int ind, point val, int cd){
        if(ind==-1){
            t.push_back(node(val));
            return sz(t)-1;
        }
        int nx=val.di[cd]>t[ind].data.di[cd];
        int te=insert(t[ind].ch[nx],val,(cd+1)%3);
        t[ind].ch[nx]=te;
        pushup(ind);
        return ind;
    }
    ll query(int ind, point val, int cd, ll bestdist){
        if(ind==-1)return bestdist;
        if(val.dist(point(min(t[ind].bound.second.di[0],max(t[ind].bound.first.di[0],val.di[0])),min(t[ind].bound.second.di[1],max(t[ind].bound.first.di[1],val.di[1])),min(t[ind].bound.second.di[2],max(t[ind].bound.first.di[2],val.di[2]))))>=bestdist)return bestdist;
        bestdist=min(bestdist,val.dist(t[ind].data));
        int nx=val.di[cd]>t[ind].data.di[cd];
        bestdist=query(t[ind].ch[nx],val,(cd+1)%3,bestdist);
        bestdist=query(t[ind].ch[!nx],val,(cd+1)%3,bestdist);
        return bestdist;
    }
    int undo(int ind, point val, int cd){
        if(ind==sz(t)-1){
            t.pop_back();
            return -1;
        }
        int nx=val.di[cd]>t[ind].data.di[cd];
        int te=undo(t[ind].ch[nx],val,(cd+1)%3);
        t[ind].ch[nx]=te;
        pushup(ind);
        return ind;
    }
}tree;
void dfs(int ind){
    ans[ind]=tree.query(0,point(indation[ind].first,indation[ind].second,0),0,LLONG_MAX);
    tree.insert(0,point(indation[ind].first,indation[ind].second,ans[ind]+cost[ind]),0);
    for(auto x:matrix[ind])dfs(x);
    tree.undo(0,point(indation[ind].first,indation[ind].second,ans[ind]+cost[ind]),0);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        cin>>indation[i].first>>indation[i].second>>cost[i]>>a;
        if(i!=n)matrix[a].push_back(i);
    }
    ans[n]=0;
    tree.t[0].data=point(indation[n].first,indation[n].second,cost[n]);
    for(auto x:matrix[n])dfs(x);
    for(int i=1;i<=n;i++)printf("%lli\n",ans[i]);
    return 0;
}