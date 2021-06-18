#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+10;
const int MB=1000;
int mi[MN],n;
vector<pii> dp[MN];
ll bit[MN+12];
void bupdate(int loc, ll val){
    loc++;
    for(;loc<=n+10;loc+=loc&-loc)bit[loc]+=val;
}
int bquery(int loc){
    loc++;
    ll am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit[loc];
    return int(am);
}
struct seg{
    struct node{
        int data,lazy,lazyset;
        node(){
            data=INT_MAX,lazy=INT_MAX,lazyset=-1;
        }
        void apply(int a, int b){
            if(b!=-1){
                data=b;
                lazy=INT_MAX;
            }
            data=min(data,a),lazy=min(lazy,a);
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,t[ind].lazyset);
        t[right].apply(t[ind].lazy,t[ind].lazyset);
        t[ind].lazy=INT_MAX;
    }
    void update(int ind, int le, int ri, int l, int r, int val, int set){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val,set);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val,set),update(right,mid+1,ri,l,r,val,set);
        t[ind].data=min(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return INT_MAX;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(int argc, char *argv[]) {// same as given an array of values, make it sorted, can change any element to any element smaller.
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)mi[i]=n+1;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mi[a]=min(mi[a],b);
        mi[b]=min(mi[b],a);
    }
    dp[0].push_back({0,0});
    for(int i=2;i<=n;i++){
        vector<pii> toupdate;
        if(mi[i]>i-1){
            int cnt=0;
            for(int k=max(i-2,0);k>=0;k--) {
                cnt++;
                int val=tree.query(0,0,n,k,k);
                while(sz(dp[k])&&dp[k].back().first>=val)dp[k].pop_back();
                toupdate.push_back({k,(sz(dp[k]))?dp[k].back().second+bquery(k) + 1:n+1});
                if(cnt>MB)break;
            }
        }
        else{
            int cnt=0;
            for(int k=min(mi[i]-1,max(i-2,0));k>=0;k--) {
                cnt++;
                int val=tree.query(0,0,n,k,k);
                while(sz(dp[k])&&dp[k].back().first>=val)dp[k].pop_back();
                toupdate.push_back({k,(sz(dp[k]))?dp[k].back().second+bquery(k):n+1});
                if(cnt>MB)break;
            }
        }
        if(i==2)dp[0]=vector<pii>(),bupdate(0,-bquery(0)),tree.update(0,0,n,0,0,INT_MAX,INT_MAX);
        dp[i-1]=vector<pii>(),bupdate(i-1,-bquery(i-1)),tree.update(0,0,n,i-1,i-1,INT_MAX,INT_MAX);
        reverse(toupdate.begin(),toupdate.end());
        for(auto x:toupdate){
            if(!sz(dp[i-1])||dp[i-1].back().second>x.second)dp[i-1].push_back(x);
        }
        bupdate(1,1),bupdate(min(mi[i],i-1),-1);
        tree.update(0,0,n,mi[i],i-2,mi[i],-1);
    }
    int best=n+1;
    for(int j=0;j<=n;j++){
        int val=tree.query(0,0,n,j,j);
        while(sz(dp[j])&&dp[j].back().first>=val)dp[j].pop_back();
        best=min(best,(sz(dp[j]))?dp[j].back().second+bquery(j):n+1);
    }
    assert(best!=n+1);
    printf("%d\n",best);
    return 0;
}