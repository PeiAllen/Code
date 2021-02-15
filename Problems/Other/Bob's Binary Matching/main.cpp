#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1,BS=3000;
ll fp(ll a, ll b, ll mod){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
struct trie{
    struct node{
        int nxt[2];
        ll mival;
        node(){
            nxt[0]=-1,nxt[1]=-1;
            mival=LLONG_MAX;
        }
    };
    vector<node> t;
    trie(){
        t={node()};
    }
    int insert(int ind, const string& a, int loc, ll v){
        if(ind==-1)ind=sz(t),t.push_back(node());
        t[ind].mival=min(t[ind].mival,v);
        if(loc!=sz(a)){int te=insert(t[ind].nxt[a[loc]-'0'],a,loc+1,v);t[ind].nxt[a[loc]-'0']=te;}
        return ind;
    }
}forw,back;
struct seg{
    struct node{
        ll data,lazy;
        node(){
            data=LLONG_MAX,lazy=LLONG_MAX;
        }
        void apply(ll a){
            data=min(data,a);
            lazy=min(lazy,a);
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=LLONG_MAX;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        if(ri<l||le>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=min(t[left].data,t[right].data);
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(ri<l||le>r)return LLONG_MAX;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}rupdate,rquery;
ll p[MN],ip[MN];
struct HSH{
     vector<ll> h;
     ll m;
     HSH(){
         h={};
     }
     HSH(const string& a, ll mut, ll mod){
        m=mod;
        h.resize(sz(a)+1);
        for(int i=1;i<=sz(a);i++)h[i]=(h[i-1]+(a[i-1]-'0'+1)*p[i-1])%m;
     }
     inline ll substr(int l, int r) const{
         return (h[r+1]-h[l]+m)*ip[l]%m;
     }
};
bool arr[MN];
HSH bhash;
vector<pair<HSH,ll>> pat;
ll dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,n,l;
    cin>>m>>n>>l;
    string s;
    cin>>s;
    p[0]=1;
    ll tem=1e9+7;
    for(int i=1;i<=max(m,l);i++)p[i]=p[i-1]*ll(31)%tem;
    ip[max(m,l)]=fp(p[max(m,l)],tem-2,tem);
    for(int i=max(m,l)-1;i>=0;i--)ip[i]=ip[i+1]*ll(31)%tem;
    bhash=HSH(s,31,1e9+7);
    for(int i=1;i<=m;i++)arr[i]=s[i-1]-'0',dp[i]=LLONG_MAX;
    ll val;
    string a;
    for(int i=0;i<n;i++){
        cin>>val>>a;
        if(sz(a)>=BS)pat.push_back({HSH(a,31,1e9+7),val});
        else forw.insert(0,a,0,val),reverse(a.begin(),a.end()),back.insert(0,a,0,val);
    }
    int ind=0;
    for(int i=1;i<=m;i++){
        ind=forw.t[ind].nxt[arr[i]];
        if(ind==-1)break;
        dp[i]=min(dp[i],forw.t[ind].mival);
    }
    for(const pair<HSH,ll> &x:pat){
        if(x.first.h[1]==bhash.h[1]) {
            int lo = 0, hi = min(sz(x.first.h) - 1, m);
            while (lo != hi) {
                int mid = (lo + hi + 1) / 2;
                if (x.first.substr(0, mid - 1) == bhash.substr(0, mid - 1))lo = mid;
                else hi = mid - 1;
            }
            rupdate.update(0, 0, m, 1, lo, x.second);
        }
    }
    rquery.update(0,0,m,0,0,0);
    for(int i=1;i<=m;i++) {
        dp[i]=min(dp[i],rupdate.query(0,0,m,i,i));
        ind = 0;
        for (int j = i; j >= 1; j--) {
            ind = back.t[ind].nxt[arr[j]];
            if (ind == -1)break;
            if(dp[j-1]!=LLONG_MAX)dp[i] = min(dp[i], dp[j-1] + back.t[ind].mival);
        }
        for (int j=0;j<sz(pat);j++) {
            if(pat[j].first.substr(sz(pat[j].first.h) - 2,sz(pat[j].first.h) - 2)==bhash.substr(i-1,i-1)) {
                int lo = 0, hi = min(sz(pat[j].first.h) - 1, i);
                while (lo != hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (pat[j].first.substr(sz(pat[j].first.h) - mid - 1, sz(pat[j].first.h) - 2) == bhash.substr(i - mid, i - 1))lo = mid;
                    else hi = mid - 1;
                }
                ll te = rquery.query(0, 0, m, i - lo, i - 1);
                if (te != LLONG_MAX)dp[i] = min(dp[i], pat[j].second + te);
            }
        }
        if (dp[i] != LLONG_MAX) {
            ind = 0;
            for (int j = i+1; j <= m; j++) {
                ind = forw.t[ind].nxt[arr[j]];
                if (ind == -1)break;
                dp[j] = min(dp[j], dp[i] + forw.t[ind].mival);
            }
            for (int j=0;j<sz(pat);j++) {
                if(pat[j].first.h[1]==bhash.substr(i,i)) {
                    int lo = 0, hi = min(sz(pat[j].first.h) - 1, m - i);
                    while (lo != hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (pat[j].first.substr(0, mid - 1) == bhash.substr(i, i + mid - 1))lo = mid;
                        else hi = mid - 1;
                    }
                    rupdate.update(0, 0, m, i + 1, i + lo, dp[i] + pat[j].second);
                }
            }
            rquery.update(0, 0, m, i,i, dp[i]);
        }
    }
    if(dp[m]==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",dp[m]);
    return 0;
}