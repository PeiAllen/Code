#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+3;
pair<pll,pll> devices[MAXN];
vector<lli> points;
const lli MAXV=1e15;
struct seg{
    lli t[2*MAXN];
    void mt(int n){
        for(int i=0;i<2*n;i++)t[i]=MAXV;
    }
    void update(int ind, int le, int ri, int loc, lli val){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind]=min(val,t[ind]);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
        t[ind]=min(t[left],t[right]);
    }
    lli query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return MAXV;
        if(l<=le&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}treel,treer;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    lli n;
    cin>>m>>n;
    points.push_back(1);
    points.push_back(n);
    for(int i=0;i<m;i++){
        cin>>devices[i].first.first>>devices[i].first.second>>devices[i].second.first>>devices[i].second.second;
        points.push_back(devices[i].second.first);
    }
    sort(points.begin(),points.end());
    points.erase(unique(points.begin(),points.end()),points.end());
    treel.mt(sz(points));
    treel.update(0,0,sz(points)-1,0,0);
    treer.mt(sz(points));
    treer.update(0,0,sz(points)-1,sz(points)-1,0);
    lli ans=MAXV;
    for(int i=0;i<m;i++){
        int l=lower_bound(points.begin(),points.end(),devices[i].first.first)-points.begin();
        int r=(upper_bound(points.begin(),points.end(),devices[i].first.second)-points.begin())-1;
        int mid=lower_bound(points.begin(),points.end(),devices[i].second.first)-points.begin();
        ans=min(ans,devices[i].second.second+treel.query(0,0,sz(points)-1,l,r)+treer.query(0,0,sz(points)-1,l,r));
        treel.update(0,0,sz(points)-1,mid,devices[i].second.second+treel.query(0,0,sz(points)-1,l,r));
        treer.update(0,0,sz(points)-1,mid,devices[i].second.second+treer.query(0,0,sz(points)-1,l,r));
    }
    if(ans==MAXV)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}