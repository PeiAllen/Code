#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll MV=1e16;
vector<ll> poses;
ll pos[MN];
int dir[MN];
ll cost[MN];
struct seg{
    struct node{
        ll data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(ll a){
            data+=a;
            lazy+=a;
        }
    }t[4*MN];
    void mt(int ind, int le, int ri, int type){
        if(le==ri){
            if(type==0)t[ind].data=-poses[le];
            else if(type==1)t[ind].data=poses[le];
            else t[ind].data=MV;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid,type),mt(right,mid+1,ri,type);
        t[ind].data=min(t[left].data,t[right].data);
    }
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll v){
        if(l>r||l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
    void update(int ind, int le, int ri, int loc, pair<ll,bool> v){
        if(loc>ri||loc<le)return;
        if(le==ri){
            if(!v.second)t[ind].data=min(t[ind].data,v.first);
            else t[ind].data=v.first;
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,v),update(right,mid+1,ri,loc,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>r||l>ri||r<le)return MV;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree[2];//left or right
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    char a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        if(pos[i]>1)poses.push_back(pos[i]-1);
        if(pos[i]<m)poses.push_back(pos[i]+1);
    }
    for(int i=1;i<=n;i++)cin>>a,dir[i]=(a=='R');
    for(int i=0;i<=n;i++)cin>>cost[i];
    sort(poses.begin(),poses.end()),poses.erase(unique(poses.begin(),poses.end()),poses.end());
    tree[0].mt(0,0,sz(poses)-1,0);
    tree[1].mt(0,0,sz(poses)-1,1);
    pos[0]=0;
    dir[0]=0;
    auto getrange=[&](ll l, ll r){
        return pii{lower_bound(poses.begin(),poses.end(),l)-poses.begin(),upper_bound(poses.begin(),poses.end(),r)-poses.begin()-1};
    };
    for(int i=1;i<=n;i++){
        vector<pair<pii,ll>> toupdate;
        auto solve=[&](ll loc, int laser){
            pii range=getrange(1,min(loc,pos[i-1]-1));
            ll bestleftle=tree[0].query(0,0,sz(poses)-1,range.first,range.second)+loc;
            range=getrange(max(ll(1),pos[i-1]+1),loc);
            ll bestleftri=tree[0].query(0,0,sz(poses)-1,range.first,range.second)+loc;
            range=getrange(loc,min(ll(m),pos[i-1]-1));
            ll bestrightle=tree[1].query(0,0,sz(poses)-1,range.first,range.second)-loc;
            range=getrange(max(loc,pos[i-1]+1),m);
            ll bestrightri=tree[1].query(0,0,sz(poses)-1,range.first,range.second)-loc;
            ll best=min(min(bestleftle,bestrightle)+((!dir[i-1])^laser?cost[i-1]:0),min(bestleftri,bestrightri)+(dir[i-1]^laser?cost[i-1]:0));
            toupdate.push_back({{0,lower_bound(poses.begin(),poses.end(),loc)-poses.begin()},best-loc});
            toupdate.push_back({{1,lower_bound(poses.begin(),poses.end(),loc)-poses.begin()},best+loc});
        };
        if(pos[i]>1)solve(pos[i]-1,!dir[i]);
        if(pos[i]<m)solve(pos[i]+1,dir[i]);
        vector<ll> locs={pos[i-1],pos[i]};
        sort(locs.begin(),locs.end()),locs.erase(unique(locs.begin(),locs.end()),locs.end());
        locs.push_back(m+1);
        vector<int> val(sz(locs));
        int te=lower_bound(locs.begin(),locs.end(),pos[i-1])-locs.begin();
        if(dir[i-1])for(te++;te<sz(locs);te++)val[te]^=1;
        else for(int j=0;j<=te;j++)val[j]^=1;
        te=lower_bound(locs.begin(),locs.end(),pos[i])-locs.begin();
        if(dir[i])for(te++;te<sz(locs);te++)val[te]^=1;
        else for(int j=0;j<=te;j++)val[j]^=1;
        int prev=0;
        for(int j=0;j<sz(locs);j++){
            if(val[j]) {
                pii range=getrange(prev+1,locs[j]-1);
                for (int k = 0; k < 2; k++) {
                    tree[k].update(0, 0, sz(poses) - 1, range.first, range.second,cost[i-1]);
                }
            }
            prev=locs[j];
        }
        int ind=lower_bound(poses.begin(),poses.end(),pos[i])-poses.begin();
        if(ind!=sz(poses)&&poses[ind]==pos[i]){
            for(int j=0;j<2;j++)tree[j].update(0,0,sz(poses)-1,ind,{MV,1});
        }
        for(auto x:toupdate){
            tree[x.first.first].update(0,0,sz(poses)-1,x.first.second,{x.second,0});
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<sz(poses);i++){
        ans=min(ans,tree[0].query(0,0,sz(poses)-1,i,i)+poses[i]+n+1);
    }
    printf("%lli\n",ans);
    return 0;
}