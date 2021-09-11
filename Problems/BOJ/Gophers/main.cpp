#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
struct seg{
    struct node{
        ll lazy,mi,micnt;
        node(){
            lazy=0;
            mi=0;
            micnt=0;
        }
        void apply(ll v){
            mi+=v;
            lazy+=v;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy);
        t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void mt(int ind, int le, int ri){
        t[ind].micnt=(ri-le+1);
        if(le==ri)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].mi=min(t[left].mi,t[right].mi);
        t[ind].micnt=(t[left].mi==t[ind].mi)*t[left].micnt+(t[right].mi==t[ind].mi)*t[right].micnt;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,d,l,a,b;
    cin>>n>>m>>d>>l;
    vector<int> locs(n);
    for(int i=1;i<n;i++){
        cin>>locs[i];
    }
    tree.mt(0,0,n-1);
    auto range=[&](int v){
        int left=lower_bound(locs.begin(),locs.end(),v-l)-locs.begin();
        int right=upper_bound(locs.begin(),locs.end(),v+l)-locs.begin()-1;
        return pii{left,right};
    };
    for(int i=0;i<m;i++){
        cin>>a;
        pii r=range(a);
        tree.update(0,0,n-1,r.first,r.second,1);
    }
    if(tree.t[0].mi>0)printf("%d\n",n);
    else printf("%d\n",n-tree.t[0].micnt);
    while(d--){
        cin>>a;
        pii r=range(a);
        tree.update(0,0,n-1,r.first,r.second,-1);
        cin>>a;
        r=range(a);
        tree.update(0,0,n-1,r.first,r.second,1);
        if(tree.t[0].mi>0)printf("%d\n",n);
        else printf("%d\n",n-tree.t[0].micnt);
    }
    return 0;
}