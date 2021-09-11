#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
const ll mod=998244353;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
const int proot = 3;
const int root_pw = 23;
const int root = fp(proot,(mod-1)/(1<<root_pw));
ll val[MN];
vector<ll> arr;
vector<int> offset;
int curoffset[MN];
bool used[MN];
int n,q,totrot;
ll invsz;
ll precalc[1048577];
int half=0;
int flip[524289];
void dft(vector<ll>& a, bool inv){
    int lg=log2(sz(a));
    for(int i=1;i<sz(a);i++)if(flip[i]>i)swap(a[i],a[flip[i]]);
    int cnt=(inv?half:0);
    for(int lay=1;lay<=lg;lay++){
        int t=(1<<lay);
        for(int i=0;i<sz(a);i+=t){
            int prev=cnt;
            for(int j=0;j<t/2;j++){
                ll u=a[i+j], v=precalc[cnt++]*a[i+j+t/2]%mod;
                a[i+j]=(u+v>=mod?u+v-mod:u+v),a[i+j+t/2]=(u-v<0?u-v+mod:u-v);
            }
            if(i+t<sz(a))cnt=prev;
        }
    }
    if(inv)for(int i=0;i<sz(a);i++)a[i]=(a[i]*invsz)%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    if(n%2==1){
        for(int i=0;i<=q;i++)printf("0\n");
        return 0;
    }
    int nn=1;
    while(nn<n+n)nn<<=1;
    invsz=fp(nn,mod-2);
    int ind=0;
    for(int i=0;i<2;i++){
        ll rt=(i?fp(root,mod-2):root);
        for(int j=1;j<20;j++){
            ll mut=fp(rt,(1<<(root_pw-j)));
            ll cur=1;
            for(int k=0;k<(1<<(j-1));k++){
                precalc[ind++]=cur;
                cur=(cur*mut)%mod;
            }
        }
        if(!i)half=ind;
    }
    int k=0,tei=log2(nn);
    for(int j=0;j<(1<<tei);j++){
        flip[j]=k;
        int b=(1<<(tei-1));
        for(;k&b;b>>=1)k^=b;
        k^=b;
    }
    ll ans=0;
    int len=((n+2)/4)*2-1,bs=7000,a,b,c;
    for(int i=0;i<n;i++)cin>>val[i];
    offset.resize(n),offset[0]=(n/2)-(n-1)/2/2,arr.resize(n);
    for(int i=0;i<len;i++)arr[0]=(arr[0]+val[i])%mod,ans=arr[0];
    for(int i=1;i<n;i++)arr[i]=(arr[i-1]+val[(i+len-1)%n]-val[i-1]+mod)%mod,offset[i]=(offset[i-1]+1)%n,ans=(ans+arr[i])%mod;
    vector<ll> darr(arr.begin(),arr.end());
    darr.resize(nn);
    dft(darr,0);
    vector<ll> pc(nn);
    vector<int> updated;
    int totoffset=0;
    printf("%lli\n",ans);
    auto reset=[&](){
        for(int j=0;j<n;j++){
            offset[j]=(offset[j]+curoffset[j]+totoffset);
            if(offset[j]>=n)offset[j]-=n;
            if(offset[j]>=n)offset[j]-=n;
        }
        for(int j=0;j<nn;j++)pc[j]=0;
        for(int j=0;j<n;j++)pc[(offset[j]==0?0:n-offset[j])]++,curoffset[j]=0;
        dft(pc,0);
        for(int j=0;j<sz(pc);j++)pc[j]=(pc[j]*darr[j])%mod;
        dft(pc,1);
        updated=vector<int>();
        totoffset=0;
    };
    reset();
    for(int i=0;i<q;i++){
        if(i%bs==0)reset();
        cin>>a>>b;
        if(a==1){
            totrot=(totrot+b>=n?totrot+b-n:totrot+b),totoffset=(totoffset+b>=n?totoffset+b-n:totoffset+b);
            ans=(pc[totoffset]+(totoffset==n-1?ll(0):pc[totoffset+n]));
            for(auto x:updated)if(!used[x]){
                    used[x]=true;
                    ans=(ans-arr[(offset[x]+totoffset>=n?offset[x]+totoffset-n:offset[x]+totoffset)]+arr[(curoffset[x]+offset[x]+totoffset)%n]+mod);
                }
            ans%=mod;
            for(auto x:updated)used[x]=false;
        }
        else{
            cin>>c,b=(b-totrot+n)%n;
            updated.push_back(b);
            ans=(ans-arr[(curoffset[b]+offset[b]+totoffset)%n]+mod)%mod;
            curoffset[b]=(curoffset[b]-c+n)%n;
            ans=(ans+arr[(curoffset[b]+offset[b]+totoffset)%n])%mod;
        }
        printf("%lli\n",ans);
    }
    return 0;
}