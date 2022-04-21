#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt"
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;

inline int readint() {
//    int c, o = 0;
//    int neg=1;
//    while ((c = getchar()) < '0'){
//        if(c=='-')neg*=-1;
//    }
//    do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
//    return o*neg;
int c;
cin>>c;
return c;
}
const int MN=1e5+1;
const ll MV=-2e9;
ll arr[MN];
struct node{
    ll sum,masum,presum,sufsum;
    int maval,mival,secondmi,micnt,lazy;
    node(){
        sum=MV,masum=0,presum=0,sufsum=0,maval=MV,mival=MV,lazy=MV,secondmi=INT_MAX,micnt=1;
    }
    void apply(int v, ll range){
        if(v<=mival)return;
        if(mival==maval||maval<=v){
            sum = v * range;
            masum = max(ll(0), sum);
            presum = max(ll(0), sum);
            sufsum = max(ll(0), sum);
            maval = v, mival = v;
            lazy = v;
            secondmi=INT_MAX;
            micnt=range;
        }
        else if(maval<=0&&v<=0){
            sum += ll(v - mival) * micnt;
            masum = 0;
            presum = 0;
            sufsum = 0;
            maval = max(maval, v), mival=v;
            lazy = v;
        }
        else{
            sum += ll(v - mival) * micnt;
            masum = sum;
            presum = sum;
            sufsum = sum;
            maval = max(maval, v), mival=v;
            lazy = v;
        }
    }
};
inline node merge(const node& a, const node& b){
    node te=node();
    te.sum=a.sum+b.sum;
    te.presum=max(a.presum,a.sum+b.presum);
    te.sufsum=max(b.sufsum,a.sufsum+b.sum);
    te.mival = min(a.mival, b.mival);
    te.maval = max(a.maval, b.maval);
    te.masum = max({a.masum, b.masum, a.sufsum + b.presum});
    te.micnt = (a.mival == te.mival ? a.micnt : 0) + (b.mival == te.mival ? b.micnt : 0);
    te.secondmi = min({(a.mival == te.mival ? INT_MAX : a.mival), (a.secondmi == te.mival ? INT_MAX : a.secondmi), (b.mival == te.mival ? INT_MAX : b.mival), (b.secondmi == te.mival ? INT_MAX : b.secondmi)});
    return te;
}
inline node merge2(const node& a, const node& b){
    node te=node();
    te.sum=a.sum+b.sum;
    te.presum=max(a.presum,a.sum+b.presum);
    te.sufsum=max(b.sufsum,a.sufsum+b.sum);
    te.masum = max({a.masum, b.masum, a.sufsum + b.presum});
    return te;
}
struct seg{
    node t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy,mid-le+1);
        t[right].apply(t[ind].lazy,ri-mid);
        t[ind].lazy=MV;
    }
    void build(int ind, int le, int ri){
        if(le==ri){
            t[ind].apply(arr[le],1);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        build(left,le,mid),build(right,mid+1,ri);
        t[ind]=merge(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||t[ind].mival>=v)return;
        if(le>=l&&ri<=r&&v<t[ind].secondmi&&(t[ind].mival==t[ind].maval||v>=0||t[ind].maval<=0||t[ind].maval<=v||(t[ind].sufsum==t[ind].sum&&t[ind].presum==t[ind].sum))){
            if((le>=l&&ri<=r&&v<t[ind].secondmi&&(t[ind].mival==t[ind].maval||v>=0||t[ind].maval<=0||t[ind].maval<=v||(t[ind].sufsum==t[ind].sum&&t[ind].presum==t[ind].sum)))&&!(le>=l&&ri<=r&&v<t[ind].secondmi&&(t[ind].mival==t[ind].maval||v>=0||t[ind].maval<=0||t[ind].maval<=v))){
                printf("%d %d %d %d %d %d\n",ind,le,ri,l,r,v);
            }
            t[ind].apply(v,ri-le+1);
            return;
        }
        if(t[ind].lazy!=MV)rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind]=merge(t[left],t[right]);
    }
    node query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return node();
        if(le>=l&&ri<=r)return t[ind];
        if(t[ind].lazy!=MV)rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return merge2(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,t,a,b,c;
    n=readint();
    q=readint();
    for(int i=1;i<=n;i++)arr[i]=readint();
    tree.build(0,1,n);
    while(q--){
        t=readint();
        a=readint();
        b=readint();
        if(t==0){
            c=readint();
            tree.update(0,1,n,a,b,c);
        }
        else printf("%lli\n",tree.query(0,1,n,a,b).masum);
    }
    return 0;
}