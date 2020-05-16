#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=300001;
struct slopefunc{
    lli m,b;
    priority_queue<lli> points;
    slopefunc(lli m1, lli b1, vector<lli> pts){
        m=m1,b=b1;
        for(lli x:pts)points.push(x);
    }
    void merge(slopefunc* a){
        m+=a->m,b+=a->b;
        if(sz(a->points)>sz(points))points.swap(a->points);
        while(sz(a->points)){
            points.push(a->points.top());
            a->points.pop();
        }
    }
    void pop(){
        b+=points.top();
        m-=1;
        points.pop();
    }
};
vector<int> matrix[MAXN];
lli parentedge[MAXN];
slopefunc* dfs(int loc){
    slopefunc* cur=new slopefunc(0,0,{});
    for(int x:matrix[loc])cur->merge(dfs(x));
    if(sz(matrix[loc])){
        while(cur->m>1)cur->pop();
        lli t1=cur->points.top();
        cur->points.pop();
        lli t0=cur->points.top();
        cur->points.pop();
        cur->points.push(t0+parentedge[loc]);
        cur->points.push(t1+parentedge[loc]);
        cur->b-=parentedge[loc];
    }
    else cur=new slopefunc(1,-parentedge[loc],{parentedge[loc],parentedge[loc]});
    return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int p;
    for(int i=2;i<=n+m;i++){
        cin>>p>>parentedge[i];
        matrix[p].push_back(i);
    }
    slopefunc* ans=dfs(1);
    while(ans->m>=1)ans->pop();
    printf("%lli\n",ans->b);
    return 0;
}