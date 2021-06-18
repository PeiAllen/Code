#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll d;
int n,m;
struct seg{
    struct node{
        __int128 totake,impossible,wimpossible,wsuffix;
        node(__int128 a=0, __int128 b=0,__int128 c=0, __int128 d=0){
            totake=a,impossible=b,wimpossible=c,wsuffix=d;
        }
    }t[2*MN];
    node merge(const node &a, const node &b){
        return node(a.totake+b.totake,min(a.impossible,a.totake+b.impossible),min({a.wimpossible,b.wimpossible,a.wsuffix+b.impossible}),min(a.wsuffix+b.totake,b.wsuffix));
    }
    void mt(int ind, int le, int ri, __int128 am){
        if(le==ri){
            t[ind]=node(am,am*min(__int128(n-ri+1),__int128(d+1))+1,am*min(__int128(n-ri+1),__int128(d+1))+1,0);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid,am),mt(right,mid+1,ri,am);
        t[ind]=merge(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int loc, __int128 am){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind].totake-=am,t[ind].impossible-=am,t[ind].wimpossible-=am,t[ind].wsuffix=min(__int128(0),t[ind].totake);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,am),update(right,mid+1,ri,loc,am);
        t[ind]=merge(t[left],t[right]);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll b;
    int a;
    cin>>n>>m>>b>>d;
    tree.mt(0,1,n,b);
    while(m--){
        cin>>a>>b;
        tree.update(0,1,n,a,b);
        if(tree.t[0].wimpossible>0)printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}