#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int MV;
vector<ll> vals;
struct seg{
    struct node{
        int cnt;
        ll sum;
        node(){
            sum=0,cnt=0;
        }
    }t[2*MN];
    void update(int ind, int le, int ri, int loc, int am){
        if(le==ri){
            t[ind].sum+=am*vals[le];
            t[ind].cnt+=am;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(loc<=mid)update(left,le,mid,loc,am);
        else update(right,mid+1,ri,loc,am);
        t[ind].sum=t[left].sum+t[right].sum;
        t[ind].cnt=t[left].cnt+t[right].cnt;
    }
    ll query(int ind, int le, int ri, int am){
        if(am==0)return 0;
        if(le==ri)return ll(min(t[ind].cnt,am))*vals[le];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[right].cnt>=am)return query(right,mid+1,ri,am);
        return query(left,le,mid,am-t[right].cnt)+t[right].sum;
    }
}tree;
int days,startday;
int arr[MN];
ll ans=0;
void cdq(int ql, int qr, int al, int ar){//q is to the left, a is to the right
    if(ql==qr){
        if(ql<startday)tree.update(0,0,MV,arr[ql],1);
        for(int i=al;i<=ar;i++){
            tree.update(0,0,MV,arr[i],1);
            ans=max(ans,tree.query(0,0,MV,max(0,days-2*(i-startday)-2*(startday-ql)+max(i-startday,startday-ql))));
        }
        if(ql<startday)tree.update(0,0,MV,arr[ql],-1);
        for(int i=ar;i>=al;i--)tree.update(0,0,MV,arr[i],-1);
        return;
    }
    if(al==ar){
        tree.update(0,0,MV,arr[al],1);
        for(int i=qr;i>=ql;i--){
            if(i<startday)tree.update(0,0,MV,arr[i],1);
            ans=max(ans,tree.query(0,0,MV,max(0,days-2*(al-startday)-2*(startday-i)+max(al-startday,startday-i))));
        }
        for(int i=ql;i<=qr;i++)if(i<startday)tree.update(0,0,MV,arr[i],-1);
        tree.update(0,0,MV,arr[al],-1);
        return;
    }
    int mid=(ql+qr)/2;
    int best=-1;
    ll bestans=-1;
    for(int i=min(qr,startday-1);i>=mid;i--)tree.update(0,0,MV,arr[i],1);
    for(int i=al;i<=ar;i++){
        tree.update(0,0,MV,arr[i],1);
        ll te=tree.query(0,0,MV,max(0,days-2*(i-startday)-2*(startday-mid)+max(startday-mid,i-startday)));
        if(te>bestans)bestans=te,best=i;
    }
    for(int i=mid;i<=min(qr,startday-1);i++)tree.update(0,0,MV,arr[i],-1);
    for(int i=ar;i>=best;i--)tree.update(0,0,MV,arr[i],-1);
    cdq(mid+1,qr,best,ar);
    for(int i=min(qr,startday-1);i>=mid+1;i--)tree.update(0,0,MV,arr[i],1);
    for(int i=best-1;i>=al;i--)tree.update(0,0,MV,arr[i],-1);
    cdq(ql,mid,al,best);
    for(int i=mid+1;i<=min(qr,startday-1);i++)tree.update(0,0,MV,arr[i],-1);
}
ll findMaxAttraction(int n, int start, int d, vector<int> attraction){
    days=d,startday=start,ans=0;
    for(int i=0;i<n;i++)vals.push_back(attraction[i]);
    sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
    MV=sz(vals)-1;
    for(int i=0;i<n;i++)arr[i]=lower_bound(vals.begin(),vals.end(),attraction[i])-vals.begin();
    cdq(0,startday,startday,n-1);
    return ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,s,d;
    cin>>n>>s>>d;
    vector<int> arri(n);
    for(int i=0;i<n;i++)cin>>arri[i];
    printf("%lli\n",findMaxAttraction(n,s,d,arri));
    return 0;
}