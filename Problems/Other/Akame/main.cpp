#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt"
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
int ans[MAXN];
pair<int,double> point[MAXN];
int n,m;
struct line{
    double a,b,c;
    line(){
        a=0,b=0,c=0;
    }
    double at(double x){
        x-=1e9;
        return (-a*x+c)/b;
    }
};
line lines[MAXN];
struct lichao{
    struct node{
        line data;
        int left,right;
        node(){
            data=line();
            left=-1,right=-1;
        }
    };
    node t[MAXN+10];
    int curind;
    bool type;
    lichao(){
        curind=1;
        type=false;
    }
    void reset(){
        t[0]=node();
        curind=1;
    }
    int update(int ind, ll le, ll ri, line val){
        if(val.a==0&&val.b==0&&val.c==0)return ind;
        if(ind==-1){
            ind=curind++;
            t[ind]=node();
            t[ind].data=val;
            return ind;
        }
        ll mid=(le+ri)/2;
        bool lef,mi;
        if(val.a==0&&val.b==0&&val.c==0)lef=false,mi=false;
        else if(t[ind].data.a==0&&t[ind].data.b==0&&t[ind].data.c==0)lef=true,mi=true;
        else {
            double x=val.at(le),y=t[ind].data.at(le);
            if (!type && x<=y)lef=true;
            else if (type && x>=y)lef=true;
            else lef=false;
            x=val.at(mid),y=t[ind].data.at(mid);
            if (!type && x<=y)mi=true;
            else if (type && x>=y)mi=true;
            else mi=false;
        }
        if(mi)swap(val,t[ind].data);
        if(le==ri)return ind;
        if(lef!=mi){int te=update(t[ind].left,le,mid,val);t[ind].left=te;}
        else {int te=update(t[ind].right,mid+1,ri,val);t[ind].right=te;}
        return ind;
    }
    double query(int ind, ll le, ll ri, ll loc){
       // assert(dep<=1000);
        if(ind==-1)return (type?INT_MIN:INT_MAX);
        if(le>loc||ri<loc)return (type?INT_MIN:INT_MAX);
        if(le==ri)return t[ind].data.at(loc);
        ll mid=(le+ri)/2;
        return (type?max({t[ind].data.at(loc),query(t[ind].left,le,mid,loc),query(t[ind].right,mid+1,ri,loc)}):min({t[ind].data.at(loc),query(t[ind].left,le,mid,loc),query(t[ind].right,mid+1,ri,loc)}));
    }
}treemin,treemax;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    treemax.type=1;
    for(int i=1;i<=n;i++){
        cin>>lines[i].a>>lines[i].b>>lines[i].c;
        treemin.update(0, 0,2e9, lines[i]);
        treemax.update(0, 0,2e9, lines[i]);
    }
    vector<pair<int,pair<double,double>>> q;
    for(int i=1;i<=m;i++){
        cin>>point[i].first>>point[i].second;
        double mi = treemin.query(0, 0, 2e9, point[i].first+1e9), ma = treemax.query(0, 0,2e9, point[i].first+1e9);
        if(point[i].second>=mi&&point[i].second<=ma)q.push_back({i,{INT_MAX,INT_MIN}});
        else ans[i]=-1;
    }
    treemin.reset();
    treemax.reset();
    queue<pair<pii,vector<pair<int,pair<double,double>>>>> que;
    if(sz(q))que.push({{1,n},q});
    while(sz(que)){
        auto cur=que.front();
        que.pop();
        if(cur.first.first==cur.first.second){
            treemin.update(0,0,2e9,lines[cur.first.first]);
            treemax.update(0,0,2e9,lines[cur.first.first]);
            for(auto x:cur.second){
                double mi=treemin.query(0,0,2e9,point[x.first].first+1e9),ma=treemax.query(0,0,2e9,point[x.first].first+1e9);
                if(point[x.first].second>=min(x.second.first,mi)&&point[x.first].second<=max(x.second.second,ma))ans[x.first]=cur.first.first;
                else ans[x.first]=-1;
            }
            treemin.reset(),treemax.reset();
        }
        else if(sz(cur.second)==1){
            bool done=false;
            for (int i = cur.first.first; i <= cur.first.second; i++) {
                treemin.update(0, 0,2e9, lines[i]);
                treemax.update(0, 0,2e9, lines[i]);
                double mi = treemin.query(0, 0,2e9, point[cur.second.front().first].first+1e9), ma = treemax.query(0, 0,2e9, point[cur.second.front().first].first+1e9);
                if (point[cur.second.front().first].second >= min(cur.second.front().second.first, mi) &&
                    point[cur.second.front().first].second <= max(cur.second.front().second.second, ma)){
                    ans[cur.second.front().first]=i;
                    done=true;
                    break;
                }
            }
            treemin.reset();
            treemax.reset();
            if(!done){
                ans[cur.second.front().first]=-1;
            }
        }
        else {
            int mid = (cur.first.first + cur.first.second) / 2;
            for (int i = cur.first.first; i <= mid; i++) {
                treemin.update(0, 0,2e9, lines[i]);
                treemax.update(0, 0,2e9, lines[i]);
            }
            vector<pair<int, pair<double, double>>> lq, rq;
            for (auto x:cur.second) {
                double mi = treemin.query(0, 0,2e9, point[x.first].first+1e9), ma = treemax.query(0, 0,2e9,
                                                                                                  point[x.first].first+1e9);
                if (point[x.first].second >= min(x.second.first, mi) &&
                    point[x.first].second <= max(x.second.second, ma))
                    lq.push_back(x);
                else rq.push_back({x.first, {min(x.second.first, mi), max(x.second.second, ma)}});
            }
            treemin.reset(), treemax.reset();
            if (sz(lq))que.push({{cur.first.first, mid}, lq});
            if (sz(rq))que.push({{mid + 1, cur.first.second}, rq});
        }
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}