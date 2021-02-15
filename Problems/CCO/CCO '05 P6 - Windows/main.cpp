#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e4+1;
struct seg{
    struct node{
        int data, ts, left, right, inner;
        node(){
            data=0,ts=0,left=-1,right=-1,inner=-1;
        }
        void apply(int val, int timestamp){
            data=val,ts=timestamp;
        }
    };
    vector<node> t;
    int timestamp;
    seg(){
        t={node()};
        timestamp=0;
    }
    void update(int ind, int le, int ri, int ile, int iri, int l, int r, int il, int ir, int val){
        timestamp++;
        updateout(ind,le,ri,ile,iri,l,r,il,ir,val);
    }
    int updatein(int ind, int le, int ri, int l, int r, int val){
        if(le>r||ri<l)return ind;
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        if(le>=l&&ri<=r){
            t[ind].apply(val,timestamp);
            return ind;
        }
        int mid=(le+ri)/2;
        {int te=updatein(t[ind].left,le,mid,l,r,val);t[ind].left=te;}
        {int te=updatein(t[ind].right,mid+1,ri,l,r,val);t[ind].right=te;}
        return ind;
    }
    int updateout(int ind, int le, int ri, int ile, int iri, int l, int r, int il, int ir, int val){
        if(le>r||ri<l)return ind;
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        if(le>=l&&ri<=r){
            {int te=updatein(t[ind].inner,ile,iri,il,ir,val);t[ind].inner=te;}
            return ind;
        }
        int mid=(le+ri)/2;
        {int te=updateout(t[ind].left,le,mid,ile,iri,l,r,il,ir,val);t[ind].left=te;}
        {int te=updateout(t[ind].right,mid+1,ri,ile,iri,l,r,il,ir,val);t[ind].right=te;}
        return ind;
    }
    pii queryin(int ind, int le, int ri, int loc){
        if(ind==-1||loc>ri||loc<le)return {0,0};
        if(le==ri)return {t[ind].ts,t[ind].data};
        int mid=(le+ri)/2;
        return max({{t[ind].ts,t[ind].data},queryin(t[ind].left,le,mid,loc),queryin(t[ind].right,mid+1,ri,loc)});
    }
    pii queryout(int ind, int le, int ri, int ile, int iri, int x, int y){
        if(ind==-1||x>ri||x<le)return {0,0};
        pii val=queryin(t[ind].inner,ile,iri,y);
        int mid=(le+ri)/2;
        return max({val,queryout(t[ind].left,le,mid,ile,iri,x,y),queryout(t[ind].right,mid+1,ri,ile,iri,x,y)});
    }
}tree;
pair<pii,pii> win[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c,n;
    cin>>r>>c>>n;
    int x,y,x2,y2;
    for(int i=1;i<=n;i++){
        cin>>x>>y2>>x2>>y;
        win[i]={{x,x2},{y,y2}};
        tree.update(0,1,r,1,c,x,x2,y,y2,i);
    }
    int m;
    cin>>m;
    while(m--){
        cin>>x>>y;
        int curwin=tree.queryout(0,1,r,1,c,x,y).second;
        printf("%d\n",curwin);
        tree.update(0,1,r,1,c,win[curwin].first.first,win[curwin].first.second,win[curwin].second.first,win[curwin].second.second,curwin);
    }
    return 0;
}