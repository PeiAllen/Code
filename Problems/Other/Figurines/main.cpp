#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
pii arr[MN];
struct seg{
    struct node{
        int amax,bmax,summax,alazy,blazy;
        node(){
            amax=0,bmax=0,summax=0,alazy=INT_MAX,blazy=INT_MIN;
        }
        void apply(int a, int b){
            if(a!=INT_MAX){
                alazy=a;
                amax=a;
                summax=bmax+amax;
            }
            if(b!=INT_MIN) {
                blazy = max(blazy, b);
                bmax = max(bmax, b);
                summax = max(summax, b + amax);
            }
        }
    }t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].amax=arr[le].first,t[ind].bmax=arr[le].second;
            t[ind].summax=arr[le].first+arr[le].second;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].summax=max(t[left].summax,t[right].summax);
        t[ind].amax=max(t[left].amax,t[right].amax);
        t[ind].bmax=max(t[left].bmax,t[right].bmax);
    }
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].alazy,t[ind].blazy);
        t[right].apply(t[ind].alazy,t[ind].blazy);
        t[ind].alazy=INT_MAX,t[ind].blazy=INT_MIN;
    }
    void update(int ind, int le, int ri, int l, int r, int alazy, int blazy){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(alazy,blazy);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,alazy,blazy),update(right,mid+1,ri,l,r,alazy,blazy);
        t[ind].summax=max(t[left].summax,t[right].summax);
        t[ind].amax=max(t[left].amax,t[right].amax);
        t[ind].bmax=max(t[left].bmax,t[right].bmax);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return INT_MIN;
        if(le>=l&&ri<=r)return t[ind].summax;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,l,r;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i].first;
    for(int i=1;i<=n;i++)cin>>arr[i].second;
    tree.mt(0,1,n);
    while(q--){
        cin>>a>>l>>r;
        if(a==1){
            cin>>a;
            tree.update(0,1,n,l,r,a,INT_MIN);
        }
        else if(a==2){
            cin>>a;
            tree.update(0,1,n,l,r,INT_MAX,a);
        }
        else printf("%d\n",tree.query(0,1,n,l,r));
    }
    return 0;
}