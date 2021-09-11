#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll bit[MN];
void update(int loc, ll val){
    for(;loc<MN;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
struct seg{
    struct node{
        ll data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(ll v){
            data+=v;
            lazy+=v;
        }
    }t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return LLONG_MIN;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
pll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    char a;
    ll b,c;
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        if(a=='+'){
            cin>>c;
            arr[i]={b,c};
            update(b,c);
            tree.update(0,1,1e6,b+1,1e6,-c);
            tree.update(0,1,1e6,b,b,b);
        }
        else if(a=='-'){
            c=arr[b].second;
            b=arr[b].first;
            update(b,-c);
            tree.update(0,1,1e6,b+1,1e6,c);
            tree.update(0,1,1e6,b,b,-b);
        }
        else{
            ll endtime=tree.query(0,1,1e6,1,b)+query(b);
            printf("%lli\n",max(ll(0),endtime-b));
        }
    }
    return 0;
}