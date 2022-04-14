#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const ll mod=1e9;
const int MN=5e5+1;
ll arr[MN];
struct seg{
    struct node{
        ll data,lazy;
        node(){
            data=0,lazy=-1;
        }
        void apply(ll v, ll range){
            if(v==-1)return;
            data=v*range%mod;
            lazy=v;
        }
    }t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1);
        t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=-1;
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v,ri-le+1);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=(t[left].data+t[right].data)%mod;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return (query(left,le,mid,l,r)+query(right,mid+1,ri,l,r))%mod;
    }
}miseg,maseg;
int n;
ll solve(bool type){
    miseg.update(0,1,n,1,n,0);
    maseg.update(0,1,n,1,n,0);
    ll sum=0,ans=0;
    vector<pii> mi,ma;
    mi.push_back({INT_MIN,0});
    ma.push_back({INT_MAX,0});
    for(int i=1;i<=n;i++){
        while(sz(mi)&&mi.back().first>=arr[i]){
            sum=(sum-mi.back().first*maseg.query(0,1,n,mi[sz(mi)-2].second+1,mi.back().second)%mod+mod)%mod;
            mi.pop_back();
        }
        sum=(sum+arr[i]*maseg.query(0,1,n,mi.back().second+1,i)%mod)%mod;
        miseg.update(0,1,n,mi.back().second+1,i,arr[i]);
        mi.push_back({arr[i],i});
        while(sz(ma)&&ma.back().first<=arr[i]){
            sum=(sum-ma.back().first*miseg.query(0,1,n,ma[sz(ma)-2].second+1,ma.back().second)%mod+mod)%mod;
            ma.pop_back();
        }
        sum=(sum+arr[i]*miseg.query(0,1,n,ma.back().second+1,i)%mod)%mod;
        maseg.update(0,1,n,ma.back().second+1,i,arr[i]);
        ma.push_back({arr[i],i});
        if(type==0)ans=(ans+sum*ll(i+1)%mod)%mod;
        else ans=(ans+sum*ll(n-i+1)%mod)%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    ans=(ans+solve(0))%mod;
    reverse(arr+1,arr+1+n);
    ans=(ans-solve(1)+mod)%mod;
    printf("%lli\n",ans);
    return 0;
}