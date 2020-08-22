#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int n,m;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
    }t[2*MAXN];
    void rl(int ind, int le, int ri){
        t[ind].data=max(t[ind].data,t[ind].lazy);
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy=max(t[left].lazy,t[ind].lazy);
            t[right].lazy=max(t[right].lazy,t[ind].lazy);
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
vector<int> tow[2][2];
vector<int> hp[MAXN];
set<int> isend[MAXN];
set<int> isbegin[MAXN];
vector<pair<int,ll>> matrix[6*MAXN];
ll dist[6*MAXN];
map<int,pii> last;
int nodes=0;
int st,en;
void addedge(int a, int b, ll c){
    matrix[a].push_back({b,c});
    matrix[b].push_back({a,c});
}
ll min_distance(vector<int> x, vector<int> h, vector<int> l, vector<int> r, vector<int> y, int s, int g){
    n=sz(x),m=sz(l);
    vector<pair<int,pii>> bridges;
    if(s>g)swap(s,g);
    for(int po=0;po<2;po++) {
        tow[po][0].push_back((po?g:s));
        for (int i = (po?g:s) - 1; i >= 0; i--)if (h[i] > h[tow[po][0].back()])tow[po][0].push_back(i);
        tow[po][1].push_back((po?g:s));
        for (int i = (po?g:s) + 1; i < n; i++)if (h[i] > h[tow[po][1].back()])tow[po][1].push_back(i);
    }
    for(int i=0;i<m;i++){
        set<int> points;
        points.insert(l[i]),points.insert(r[i]);
        for(int po=0;po<2;po++) {
            if (l[i] <= (po?g:s) && r[i] >= (po?g:s)) {
                for(int j=0;j<2;j++)points.insert(*lower_bound(tow[po][j].begin(), tow[po][j].end(), y[i], [&](auto it, int val) {
                    return h[it] < val;
                }));
            }
        }
        for(auto it=points.begin();it!=prev(points.end(),1);it++){
            bridges.push_back({y[i],{*it,*next(it,1)}});
        }
    }
    sort(bridges.begin(),bridges.end());
    hp[s].push_back(0),hp[g].push_back(0);
    for(auto i:bridges){
        hp[i.second.first].push_back(i.first);
        isbegin[i.second.first].insert(i.first);
        hp[i.second.second].push_back(i.first);
        isend[i.second.second].insert(i.first);
        hp[i.second.first].push_back(tree.query(0,0,n-1,i.second.first,i.second.first));
        hp[i.second.second].push_back(tree.query(0,0,n-1,i.second.second,i.second.second));
        tree.update(0,0,n-1,i.second.first,i.second.second,i.first);
    }
    for(int i=0;i<n;i++){
        sort(hp[i].begin(),hp[i].end());
        hp[i].erase(unique(hp[i].begin(),hp[i].end()),hp[i].end());
        if(i==s)st=nodes;
        if(i==g)en=nodes;
        for(int j=0;j<sz(hp[i]);j++){
            if(last.count(hp[i][j])&&last[hp[i][j]].first!=-1)addedge(last[hp[i][j]].first,nodes,x[i]-last[hp[i][j]].second);
            if(j)addedge(nodes,nodes-1,hp[i][j]-hp[i][j-1]);
            if(hp[i][j]&&(!isend[i].count(hp[i][j])||isbegin[i].count(hp[i][j])))last[hp[i][j]]={nodes,x[i]};
            else last[hp[i][j]]={-1,-1};
            nodes++;
            assert(nodes<=4*(3*m)+2);
        }
    }
    for(int i=0;i<nodes;i++)dist[i]=LLONG_MAX;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    dist[st]=0;
    q.push({0,st});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            if(cur.second==en)return cur.first;
            for(auto ne:matrix[cur.second]){
                if(ne.second+cur.first<dist[ne.first]){
                    dist[ne.first]=ne.second+cur.first;
                    q.push({dist[ne.first],ne.first});
                }
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    printf("%lli\n",min_distance({0, 3, 5, 7, 10, 12, 14},
//                                 {8, 7, 9, 7, 6, 6, 9},
//                                 {0, 0, 0, 2, 2, 3, 4},
//                                 {1, 2, 6, 3, 6, 4, 6},
//                                 {1, 6, 8, 1, 7, 2, 5},
//    1, 5));
//    printf("%lli\n",min_distance({0, 4, 5, 6, 9},
//    {6, 6, 6, 6, 6},
//        {3, 1, 0},
//            {4, 3, 2},
//                {1, 3, 6},
//    0, 4));
    int n,m;
    cin>>n>>m;
    vector<int> loc(n),height(n),lefttower(m),righttower(m),height2(m);
    int s,g;
    for(int i=0;i<n;i++){
        cin>>loc[i]>>height[i];
    }
    for(int i=0;i<m;i++){
        cin>>lefttower[i]>>righttower[i]>>height2[i];
    }
    cin>>s>>g;
    printf("%lli\n",min_distance(loc,height,lefttower,righttower,height2,s,g));
    return 0;
}