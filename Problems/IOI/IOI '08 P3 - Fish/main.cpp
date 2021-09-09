#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
ll mod;
int am[MN],totam[MN];
vector<ll> vals[MN];
int ord[MN],last[MN],mexp[MN];
bool done[MN],active[MN];
struct seg{
    ll t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=1%mod;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=t[left]*t[right]%mod;
    }
    void update(int ind, int le, int ri, int loc, ll v){
        if(loc<le||loc>ri)return;
        if(le==ri){
            t[ind]=v%mod;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,v),update(right,mid+1,ri,loc,v);
        t[ind]=t[left]*t[right]%mod;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>r||l>ri||r<le)return 1%mod;
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)*query(right,mid+1,ri,l,r)%mod;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int f,k;
    cin>>f>>k>>mod;
    vector<pii> fishes(f);
    for(int i=0;i<f;i++){
        cin>>fishes[i].first>>fishes[i].second;
    }
    sort(fishes.begin(),fishes.end());
    ll ans=0;
    vector<int> types;
    for(int i=1;i<=k;i++)ord[i]=-1,types.push_back(i);
    for(int i=0;i<f;i++){
        ord[fishes[i].second]=i;
        vals[fishes[i].second].push_back(fishes[i].first);
        mexp[fishes[i].second]=fishes[i].first;
    }
    vector<pii> inord;
    for(int i=1;i<=k;i++){
        if(mexp[i]){
            inord.push_back({mexp[i],i});
        }
    }
    sort(inord.begin(),inord.end());
    sort(types.begin(),types.end(),[&](const auto &lhs, const auto &rhs){
        return ord[lhs]<ord[rhs];
    });
    for(int i=0;i<k;i++){
        ord[types[i]]=i;
    }
    while(sz(fishes)){
        for(int i=1;i<=k;i++)am[i]=0,totam[i]=0,active[i]=!done[i];
        tree.mt(0,0,k-1);
        int ptr=-1;
        while(ptr+1<sz(fishes)&&fishes[ptr+1].first*2<=fishes.back().first)ptr++;
        for(int i=0;i<=ptr;i++)totam[fishes[i].second]++;
        for(int i=ptr+1;i<sz(fishes);i++)last[fishes[i].second]=i;
        int othptr=-1;
        int finptr=-1;
        for(int i=ptr+1;i<sz(fishes);i++){
            while(othptr+1<=ptr&&fishes[othptr+1].first*2<=fishes[i].first){
                othptr++;
                am[fishes[othptr].second]++;
                if(active[fishes[othptr].second])tree.update(0,0,k-1,ord[fishes[othptr].second],am[fishes[othptr].second]+1);
            }
            while(finptr+1<sz(inord)&&inord[finptr+1].first<fishes[i].first*2){
                finptr++;
                active[inord[finptr].second]=true;
                tree.update(0,0,k-1,ord[inord[finptr].second],am[inord[finptr].second]+1);
            }
            if(i==last[fishes[i].second]&&!done[fishes[i].second]) {
                for(int j=0;j<=am[fishes[i].second];j++){
                    ll need=vals[fishes[i].second][j];
                    int loc=lower_bound(types.begin(),types.end(),need*2,[&](const int &it, const int &val){
                       return mexp[it]<val;
                    })-types.begin();//cant use anything >=loc
                    loc=max(loc,ord[fishes[i].second]+1);
                    ans=(ans+tree.query(0,0,k-1,0,ord[fishes[i].second]-1)*tree.query(0,0,k-1,ord[fishes[i].second]+1,loc-1)%mod)%mod;
                }
                done[fishes[i].second]=true;
            }
        }
        vector<pii> te;
        for(int i=0;i<=ptr;i++){
            te.push_back(fishes[i]);
        }
        fishes=te;
    }
    printf("%lli\n",ans);
    return 0;
}