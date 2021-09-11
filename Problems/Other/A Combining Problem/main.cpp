#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int arr[MAXN];
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int val, int range){
            if(val==1)data=range;
            else if(val==2)data=0;
            if(val)lazy=val;
        }
    }t[2*MAXN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1),t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val,ri-le+1);
            return;
        }
        if(t[ind].lazy)prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=t[left].data+t[right].data;
    }
    int query(int ind, int le, int ri, int val){
        if(le==ri)return le+val-t[ind].data;
        if(t[ind].lazy)prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[left].data>=val)return query(left,le,mid,val);
        return query(right,mid+1,ri,val-t[left].data);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[i]+=arr[i-1];
    tree.update(0,1,n,1,n,1);
    int a,b,c;
    while(q--){
        cin>>a>>b;
        int am=tree.t[0].data;
        b%=am;
        if(b==0)b+=am;
        if(a==1){
            cin>>c;
            int l=tree.query(0,1,n,b);
            int rightof=am-b+1;
            c%=rightof;
            if(c==0)c+=rightof;
            int r=tree.query(0,1,n,b+c-1);
            tree.update(0,1,n,l+1,r,2);
        }
        else if(a==2){
            int l=tree.query(0,1,n,b),r=tree.query(0,1,n,b+1);
            tree.update(0,1,n,l+1,r-1,1);
        }
        else{
            cin>>c;
            int l=tree.query(0,1,n,b);
            int rightof=am-b+1;
            c%=rightof;
            if(c==0)c+=rightof;
            int r=tree.query(0,1,n,b+c);
            printf("%d\n",arr[r-1]-arr[l-1]);
        }
    }
    return 0;
}