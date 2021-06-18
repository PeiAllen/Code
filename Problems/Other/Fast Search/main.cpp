#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
struct seg{
    int t[2*MN];
    void update(int ind, int le, int ri, int loc, int val){
        if(loc<le||loc>ri)return;
        if(le==ri){
            t[ind]=val;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
        t[ind]=min(t[left],t[right]);
    }
    int query(int ind, int le, int ri, int l, int r, int k){
        if(r<le||l>ri)return INT_MAX;
        if(le>=l&&ri<=r){
            if(t[ind]<k){
                while(le!=ri){
                    int mid=(le+ri)/2;
                    int left=ind+1,right=ind+(mid-le+1)*2;
                    if(t[left]<k)ind=left,ri=mid;
                    else ind=right,le=mid+1;
                }
                return le;
            }
            return INT_MAX;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        int te=query(left,le,mid,l,r,k);
        if(te!=INT_MAX)return te;
        return query(right,mid+1,ri,l,r,k);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b,c,d;
    cin>>n>>q;
    int last=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        tree.update(0,1,n,i,a);
    }
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            b^=last,c^=last;
            tree.update(0,1,n,b,c);
        }
        else{
            cin>>d;
            b^=last,c^=last,d^=last;
            printf("%d\n",last=tree.query(0,1,n,b,c,d));
        }
    }
    return 0;
}