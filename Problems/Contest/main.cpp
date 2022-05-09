#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
int appear[MN];
int lr[MN],rr[MN];
pii st[MN];
vector<pair<pii,int>> updates[MN+2];
vector<pair<pii,pii>> queries[MN+2];
ll ans[MN];
struct seg{
    struct node{
        ll mi,ammi,am,historicam,lazysum,mostneglazy,ammostneg,lazycall;
        node(){
            mi=0,ammi=0,am=0;
            historicam=0;
            lazysum=0;
            mostneglazy=0;
            ammostneg=0;
            lazycall=0;
        }
        void apply(ll plazysum,ll pmostneglazy,ll pammostneg,ll plazycall){
            if(am==0)return;
            historicam+=am*plazycall;
            if(pmostneglazy+mi==0){
                historicam-=pammostneg*ammi;
            }
            ll nmostneglazy=min(mostneglazy,lazysum+pmostneglazy);
            ammostneg=(nmostneglazy==mostneglazy?ammostneg:0)+(nmostneglazy==pmostneglazy+lazysum?pammostneg:0);
            mostneglazy=nmostneglazy;
            mi+=plazysum;
            lazysum+=plazysum;
            lazycall+=plazycall;
        }
    }t[2*MN];
    node merge(const node &a, const node &b){
        node ret=node();
        ret.mi=min(a.mi,b.mi);
        ret.ammi=(a.mi==ret.mi?a.ammi:0)+(b.mi==ret.mi?b.ammi:0);
        ret.am=a.am+b.am;
        ret.historicam=a.historicam+b.historicam;
        return ret;
    }
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].ammi=t[ind].am=1;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=merge(t[left],t[right]);
    }
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazysum,t[ind].mostneglazy,t[ind].ammostneg,t[ind].lazycall);
        t[right].apply(t[ind].lazysum,t[ind].mostneglazy,t[ind].ammostneg,t[ind].lazycall);
        t[ind].lazysum=0,t[ind].mostneglazy=0,t[ind].ammostneg=0,t[ind].lazycall=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>ri||r<le||l>r||t[ind].am==0)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v,v,0,0);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind]=merge(t[left],t[right]);
    }
    void call(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r||t[ind].am==0)return;
        if(le>=l&&ri<=r){
            t[ind].apply(0,0,1,1);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        call(left,le,mid,l,r),call(right,mid+1,ri,l,r);
        t[ind]=merge(t[left],t[right]);
    }
    void disable(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r||t[ind].am==0)return;
        if(le>=l&&ri<=r){
            t[ind].am=0;
            t[ind].ammi=0;
            t[ind].mi=INT_MAX;
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        disable(left,le,mid,l,r),disable(right,mid+1,ri,l,r);
        t[ind]=merge(t[left],t[right]);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r){
            return t[ind].historicam;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i],appear[arr[i]]=i;
    }
    int l=0,r=-1;
    st[++r]={INT_MAX,0};
    for(int i=1;i<=n;i++){
        while(st[r].first<arr[i])r--;
        lr[arr[i]]=st[r].second+1;
        st[++r]={arr[i],i};
    }
    l=0,r=-1;
    st[++r]={INT_MAX,n+1};
    for(int i=n;i>=1;i--){
        while(st[r].first<arr[i])r--;
        rr[arr[i]]=st[r].second-1;
        st[++r]={arr[i],i};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<=n;j++){
            if(i!=j){
                pii lrange={1,min(appear[i],appear[j])};
                pii rrange={max(appear[i],appear[j]),n};
                lrange.first=max(lrange.first,lr[i*j]);
                lrange.second=min(lrange.second,appear[i*j]);
                rrange.first=max(rrange.first,appear[i*j]);
                rrange.second=min(rrange.second,rr[i*j]);
                if(lrange.first<=lrange.second&&rrange.first<=rrange.second){
                    updates[lrange.first].push_back({rrange,1});
                    updates[lrange.second+1].push_back({rrange,-1});
                }
            }
        }
    }
    int a,b;
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        queries[a-1].push_back({{a,b},{-1,i}});
        queries[b].push_back({{a,b},{1,i}});
    }
    tree.mt(0,1,n);
    for(int i=1;i<=n;i++){
        for(auto x:updates[i]){
            tree.update(0,1,n,x.first.first,x.first.second,x.second);
        }
        tree.call(0,1,n,1,n);
        tree.disable(0,1,n,i,i);
        for(auto x:queries[i]){
            ans[x.second.second]+=tree.query(0,1,n,x.first.first,x.first.second)*x.second.first;
        }
    }
    for(int i=1;i<=q;i++)printf("%lli\n",ans[i]);
    return 0;
}