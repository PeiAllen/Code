#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int n;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int a){
            data+=a;
            lazy+=a;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=min(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return n+1;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int mostright[MN],mostleft[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)mostleft[i]=n+1;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        mostleft[a]=min(mostleft[a],b);
        mostleft[b]=min(mostleft[b],a);
        mostright[a]=max(mostright[a],b);
        mostright[b]=max(mostright[b],a);
    }
    int ptr=0;
    for(int i=2;i<=n;i++){
        while(ptr+1<i&&mostright[ptr+1]<=i)ptr++;
        tree.update(0,1,n,1,min(i-1,mostleft[i]-1),1);
        int te=tree.query(0,1,n,1,ptr);
        tree.update(0,1,n,i,i,te);
    }
    printf("%d\n",tree.query(0,1,n,n,n));
    return 0;
}