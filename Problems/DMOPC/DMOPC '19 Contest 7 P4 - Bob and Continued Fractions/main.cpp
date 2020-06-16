#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
ll arr[MAXN];
const ll mod=1e9+7;
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
struct node{
    ll a,b,c,d;
    node(){
        a=0,b=0,c=0,d=0;
    }
    node(ll a1, ll b1, ll c1, ll d1){
        a=a1,b=b1,c=c1,d=d1;
    }
};
node join(node a, node b){
    return node(fix((a.a*b.a%mod)+(a.b*b.c%mod)),fix((a.a*b.b%mod)+(a.b*b.d%mod)),fix((a.c*b.a%mod)+(a.d*b.c%mod)),fix((a.c*b.b%mod)+(a.d*b.d%mod)));
}
struct seg{
    vector<node> t;
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=node(arr[le],1,1,0);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=join(t[left],t[right]);
    }
    node query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return node(1,0,0,1);
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return join(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    tree.t.resize(2*n);
    for(int i=1;i<=n;i++)cin>>arr[i];
    tree.mt(0,1,n);
    int l,r;
    while(q--){
        cin>>l>>r;
        node te=tree.query(0,1,n,l,r);
        printf("%lli %lli\n",te.a,te.c);
    }
    return 0;
}