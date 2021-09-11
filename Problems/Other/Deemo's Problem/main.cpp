#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1,HSHS=4;
ll mod[HSHS]={2000003261,3000002297,1000000919,900001117};
ll mut[HSHS]={1001107,2001847,3001811,4001407};
struct HASHER{
    ll hsh[HSHS];
    HASHER(ll a=0){
        for(int i=0;i<HSHS;i++)hsh[i]=a;
    }
    void operator+=(const HASHER &rhs) {
        for(int i=0;i<HSHS;i++)hsh[i]=(hsh[i]+rhs.hsh[i])%mod[i];
    }
    void operator-=(const HASHER &rhs) {
        for(int i=0;i<HSHS;i++)hsh[i]=(hsh[i]-rhs.hsh[i]+mod[i])%mod[i];
    }
    HASHER next(){
        HASHER ret;
        for(int i=0;i<HSHS;i++)ret.hsh[i]=(hsh[i]*mut[i])%mod[i];
        return ret;
    }
    bool operator==(const HASHER &rhs) const {
        for(int i=0;i<HSHS;i++)if(hsh[i]!=rhs.hsh[i])return false;
        return true;
    }
    bool operator<(const HASHER &rhs)  const {
        for(int i=0;i<HSHS-1;i++)if(hsh[i]!=rhs.hsh[i])return hsh[i]<rhs.hsh[i];
        return hsh[HSHS-1]<rhs.hsh[HSHS-1];
    }
};
map<HASHER,ll> am;
HASHER pre[MAXN];
ll cnt[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    pre[1]=HASHER(1);
    HASHER totsum(1),cur(0);
    multiset<ll> occ={0};
    for(int i=2;i<=m;i++){
        pre[i]=pre[i-1].next(),totsum+=pre[i],occ.insert(0);
    }
    am[cur]++;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        ll last=*occ.begin();
        cur+=pre[a];
        occ.erase(occ.find(cnt[a]));
        cnt[a]++;
        occ.insert(cnt[a]);
        if(*occ.begin()!=last)cur-=totsum;
        ans+=am[cur];
        am[cur]++;
    }
    printf("%lli\n",ans);
    return 0;
}