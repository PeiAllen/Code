#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
ll psa[MAXN];
pii tim[MAXN];
vector<pii> peeps[MAXN];
ll ans[MAXN];
int n,m,d;
ll calc(int dp, int cur){
    if(dp==-1)return 0;
    return psa[m]-psa[dp]+(psa[dp]-psa[dp-1])*(dp-cur);
}
struct lichao{
    struct node{
        int data,left,right;
        node(){
            data=-1,left=-1,right=-1;
        }
    };
    vector<node> t;
    lichao(){
        t={node()};
    }
    int update(int ind, int le, int ri, int val){
        if(val==-1)return ind;
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        int mid=(le+ri)/2;
        bool lef=calc(val,le)>=calc(t[ind].data,le);
        bool mi=calc(val,mid)>=calc(t[ind].data,mid);
        if(mi)swap(val,t[ind].data);
        if(le==ri)return ind;
        if(lef!=mi){int newl=update(t[ind].left,le,mid,val);t[ind].left=newl;}
        else {int newr=update(t[ind].right,mid+1,ri,val);t[ind].right=newr;}
        return ind;
    }
    ll query(int ind, int le, int ri, int loc){
        if(ind==-1)return 0;
        if(loc<le||loc>ri)return 0;
        if(le==ri)return calc(t[ind].data,loc);
        int mid=(le+ri)/2;
        return max({calc(t[ind].data,loc),query(t[ind].left,le,mid,loc),query(t[ind].right,mid+1,ri,loc)});
    }
};
struct seg{
    lichao t[2*MAXN];
    void update(int ind, int le, int ri, int l, int r, int val){
        if(le>r||ri<l)return;
        if(le>=l&&ri<=r){
            t[ind].update(0,0,m,val);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
    }
    ll query(int ind, int le, int ri, int loc, int amsv){
        if(le>loc||ri<loc)return 0;
        if(le==ri)return t[ind].query(0,0,m,amsv);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max({t[ind].query(0,0,m,amsv),query(left,le,mid,loc,amsv),query(right,mid+1,ri,loc,amsv)});
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++){
        cin>>psa[i]>>tim[i].first>>tim[i].second;
        psa[i]+=psa[i-1];
    }
    int a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        peeps[a].push_back({b,i});
    }
    ll tot=0;
    for(int i=m;i>=1;i--){
        for(auto x:peeps[i]){
            ans[x.second]=tot-tree.query(0,1,d,x.first,i);
        }
        tot+=psa[m]-psa[i-1];
        tree.update(0,1,d,tim[i].first,tim[i].second,i);
    }
    for(auto x:peeps[0]){
        ans[x.second]=tot-tree.query(0,1,d,x.first,0);
    }
    for(int i=1;i<=n;i++){
        printf("%lli\n",ans[i]);
    }
    return 0;
}