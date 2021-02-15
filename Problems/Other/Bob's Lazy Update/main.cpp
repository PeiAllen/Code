#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll mod=1e9+7;
const int MN=1e5+1;
struct seg{
    struct node{
        ll data,lm,la;
        node(){
            data=0,lm=1,la=0;
        }
        void apply(ll m,ll a, ll range){
            data=(data*m%mod+a*range%mod)%mod;
            la=(la*m%mod+a)%mod;
            lm=lm*m%mod;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lm,t[ind].la,mid-le+1),t[right].apply(t[ind].lm,t[ind].la,ri-mid);
        t[ind].lm=1,t[ind].la=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll m, ll a){
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(m,a,ri-le+1);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,m,a),update(right,mid+1,ri,l,r,m,a);
        t[ind].data=(t[left].data+t[right].data)%mod;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return (query(left,le,mid,l,r)+query(right,mid+1,ri,l,r))%mod;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>mod;
    int a;
    for(int i=1;i<=n;i++)cin>>a,tree.update(0,1,n,i,i,1,a%mod);
    int m;
    cin>>m;
    int b,c,d;
    while(m--){
        cin>>a>>b>>c;
        if(a==1){
            cin>>d;
            tree.update(0,1,n,b,c,d%mod,0);
        }
        else if(a==2){
            cin>>d;
            tree.update(0,1,n,b,c,1,d%mod);
        }
        else{
            printf("%lli\n",tree.query(0,1,n,b,c));
        }
    }
    return 0;
}