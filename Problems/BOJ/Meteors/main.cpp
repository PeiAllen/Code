#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> points[MN];
__int128 needed[MN];
__int128 bit[MN];
int n,m,k;
void update(int loc, __int128 val){
    for(;loc<=m;loc+=loc&-loc)bit[loc]+=val;
}
__int128 query(int loc){
    __int128 sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int ans[MN];
void cdq(int l, int r, const vector<int>& states, const vector<pair<pii,pair<__int128,int>>>& showers){
    if(sz(states)==0)return;
    if(l==r){
        for(auto x:showers){
            if(x.first.first<=x.first.second)update(x.first.first,x.second.first),update(x.first.second+1,-x.second.first);
            else update(x.first.first,x.second.first),update(1,x.second.first),update(x.first.second+1,-x.second.first);
        }
        for(auto x:states){
            __int128 am=0;
            for(auto y:points[x])am+=query(y);
            if(am>=needed[x])ans[x]=l;
            else ans[x]=l+1;
        }
        for(auto x:showers){
            if(x.first.first<=x.first.second)update(x.first.first,-x.second.first),update(x.first.second+1,x.second.first);
            else update(x.first.first,-x.second.first),update(1,-x.second.first),update(x.first.second+1,x.second.first);
        }
        return;
    }
    int mid=(l+r)/2;
    vector<int> lstates,rstates;
    vector<pair<pii,pair<__int128,int>>> lshowers,rshowers;
    for(auto x:showers){
        if(x.second.second<=mid){
            if(x.first.first<=x.first.second)update(x.first.first,x.second.first),update(x.first.second+1,-x.second.first);
            else update(x.first.first,x.second.first),update(1,x.second.first),update(x.first.second+1,-x.second.first);
            lshowers.push_back(x);
        }
        else rshowers.push_back(x);
    }
    for(auto x:states){
        __int128 am=0;
        for(auto y:points[x])am+=query(y);
        if(am>=needed[x])lstates.push_back(x);
        else rstates.push_back(x),needed[x]-=am;
    }
    for(auto x:showers)if(x.second.second<=mid){
        if(x.first.first<=x.first.second)update(x.first.first,-x.second.first),update(x.first.second+1,x.second.first);
        else update(x.first.first,-x.second.first),update(1,-x.second.first),update(x.first.second+1,x.second.first);
    }
    cdq(l,mid,lstates,lshowers),cdq(mid+1,r,rstates,rshowers);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>n>>m;
    ll c;
    for(int i=1;i<=m;i++){
        cin>>a;
        points[a].push_back(i);
    }
    vector<int> states;
    for(int i=1;i<=n;i++){
        cin>>c;
        needed[i]=c,states.push_back(i);
    }
    cin>>k;
    vector<pair<pii,pair<__int128,int>>> showers;
    for(int i=1;i<=k;i++){
        cin>>a>>b>>c;
        showers.push_back({{a,b},{c,i}});
    }
    cdq(1,k,states,showers);
    for(int i=1;i<=n;i++){
        if(ans[i]==k+1)printf("NIE\n");
        else printf("%d\n",ans[i]);
    }
    return 0;
}