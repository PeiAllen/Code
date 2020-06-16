#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
int arr[MAXN];
ll precalc[MAXN];
int p[MAXN];
ll ans[MAXN];
ll bit[MAXN];
int n;
void update(int loc, int am){
    for(;loc<=n&&loc>0;loc+=loc&-loc)bit[loc]+=am;
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
ll tot=0;
void cdq(int l, int r){
    if(l==r){
        tot+=precalc[l];
        ans[l]=tot;
        return;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    vector<pii> te;
    for(int i=l;i<=r;i++)te.push_back({p[i],i});
    sort(te.begin(),te.end());
    for(auto x:te){
        if(x.second<=mid)update(arr[x.first],1);
        else precalc[x.second]+=query(n)-query(arr[x.first]);
    }
    for(auto x:te)if(x.second<=mid)update(arr[x.first],-1);
    reverse(te.begin(),te.end());
    for(auto x:te){
        if(x.second<=mid)update(arr[x.first],1);
        else precalc[x.second]+=query(arr[x.first]-1);
    }
    for(auto x:te)if(x.second<=mid)update(arr[x.first],-1);
    cdq(mid+1,r);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cdq(1,n);
    for(int i=1;i<=n;i++)printf("%lli\n",ans[i]);
    return 0;
}