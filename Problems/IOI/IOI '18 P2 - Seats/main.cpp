#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
vector<vector<int>> arr;
pii loc[MAXN];
int xc[4]={1,-1,0,0},yc[4]={0,0,1,-1};
int h,w,maxv;
struct seg{
    struct node{
        pii data;
        int lazy;
        node(){
            data={0,0},lazy=0;
        }
    }t[2*MAXN];
    pii pu(pii a, pii b){
        if(a.first<b.first)return a;
        if(b.first<a.first)return b;
        return {a.first,a.second+b.second};
    }
    void mt(int ind, int le, int ri){
        t[ind].data.second=ri-le+1;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(le!=ri)mt(left,le,mid),mt(right,mid+1,ri);
    }
    void rl(int ind, int le, int ri){
        t[ind].data.first+=t[ind].lazy;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        rl(ind,le,ri);
        if(le>r||ri<l)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=pu(t[left].data,t[right].data);
    }
}tree;
bool inbounds(pii a){
    return (a.first>=0&&a.second>=0&&a.first<h&&a.second<w);
}
void update(pii a, int val){
    pii rn={arr[a.first][a.second],maxv};
    if(inbounds({a.first-1,a.second}))rn.second=min(rn.second,arr[a.first-1][a.second]-1);
    if(inbounds({a.first,a.second-1}))rn.second=min(rn.second,arr[a.first][a.second-1]-1);
    if(rn.first<=rn.second)tree.update(0,0,maxv,rn.first,rn.second,val);
    rn={0,arr[a.first][a.second]-1};
    vector<int> te;
    for(int i=0;i<4;i++){
        pii ne={a.first+xc[i],a.second+yc[i]};
        if(inbounds(ne))te.push_back(arr[ne.first][ne.second]);
    }
    sort(te.begin(),te.end());
    if(sz(te)>=2){
        rn.first=te[1];
        if(rn.first<=rn.second)tree.update(0,0,maxv,rn.first,rn.second,val);
    }
}
void give_initial_chart(int H, int W, vector<int> R, vector<int> C){
    h=H,w=W;
    maxv=h*w-1;
    arr.resize(h);
    tree.mt(0,0,maxv);
    for(int i=0;i<h;i++)arr[i].resize(w);
    for(int i=0;i<h*w;i++){
        loc[i]={R[i],C[i]};
        arr[R[i]][C[i]]=i;
    }
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)update({i,j},1);
}
int swap_seats(int a, int b){
    set<pii> toupdate;
    toupdate.insert(loc[a]),toupdate.insert(loc[b]);
    for(int i=0;i<4;i++){
        pii ne={loc[a].first+xc[i],loc[a].second+yc[i]};
        if(inbounds(ne))toupdate.insert(ne);
        ne={loc[b].first+xc[i],loc[b].second+yc[i]};
        if(inbounds(ne))toupdate.insert(ne);
    }
    for(auto x:toupdate)update(x,-1);
    swap(arr[loc[a].first][loc[a].second],arr[loc[b].first][loc[b].second]);
    swap(loc[a],loc[b]);
    for(auto x:toupdate)update(x,1);
    assert(tree.t[0].data.first==1);
    return tree.t[0].data.second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int baf[6]={0, 1, 1, 0, 0, 1};
    int baf2[6]={0, 0, 1,
                 1, 2, 2};
    give_initial_chart(2, 3, baf,baf2);
    printf("%d\n",swap_seats(0,5));
    printf("%d\n",swap_seats(0,5));
    return 0;
}