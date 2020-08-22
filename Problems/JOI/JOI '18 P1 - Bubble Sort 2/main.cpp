#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
set<int> inds[MAXN];
struct seg{
    struct node{
        int data,lazy;
    }t[2*MAXN];
    void rl(int ind, int le, int ri){
        t[ind].data+=t[ind].lazy;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void range(int ind, int le, int ri, int l, int r, int val){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        range(left,le,mid,l,r,val),range(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    void update(int ind, int le, int ri, int loc, int val){
        rl(ind,le,ri);
        if(loc>ri||loc<le)return;
        if(le==ri){
            if(sz(inds[loc]))t[ind].data-=*inds[loc].rbegin();
            if(inds[loc].count(val))inds[loc].erase(val);
            else inds[loc].insert(val);
            if(sz(inds[loc]))t[ind].data+=*inds[loc].rbegin();
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
}tree;
vector<int> countScans(vector<int> A, vector<int> X, vector<int> V){
    vector<int> vals;
    for(int x:A)vals.push_back(x);
    for(int x:V)vals.push_back(x);
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    int maxv=sz(vals)-1;
    for(int i=1;i<=sz(A);i++){
        int val=lower_bound(vals.begin(),vals.end(),A[i-1])-vals.begin();
        tree.update(0,0,maxv,val,i);
        tree.range(0,0,maxv,val,maxv,-1);
    }
    vector<int> ans;
    for(int i=0;i<sz(X);i++){
        int val=lower_bound(vals.begin(),vals.end(),V[i])-vals.begin(),oval=lower_bound(vals.begin(),vals.end(),A[X[i]])-vals.begin();
        tree.update(0,0,maxv,oval,X[i]+1);
        tree.range(0,0,maxv,oval,maxv,1);
        tree.update(0,0,maxv,val,X[i]+1);
        tree.range(0,0,maxv,val,maxv,-1);
        ans.push_back(tree.t[0].data);
        A[X[i]]=V[i];
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> arr,gind,gval;
    int n,m;
    cin>>n>>m;
    arr.resize(n),gind.resize(m),gval.resize(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++)cin>>gind[i]>>gval[i];
    vector<int> te=countScans(arr,gind,gval);
    for(auto x:te)printf("%d\n",x);
    return 0;
}