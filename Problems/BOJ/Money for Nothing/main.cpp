#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
pll deq[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,n;
    cin>>m>>n;
    vector<pll> sellers(m),buyers(n);
    for(int i=0;i<m;i++)cin>>sellers[i].second>>sellers[i].first;
    for(int i=0;i<n;i++)cin>>buyers[i].second>>buyers[i].first;
    sort(sellers.begin(),sellers.end()),sort(buyers.begin(),buyers.end());
    vector<pll> goodsellers,goodbuyers;
    for(auto x:sellers){
        if(!sz(goodsellers)||x.second<goodsellers.back().second)goodsellers.push_back(x);
    }
    for(auto x:buyers){
        while(sz(goodbuyers)&&x.second>=goodbuyers.back().second)goodbuyers.pop_back();
        goodbuyers.push_back(x);
    }
    sellers=goodsellers,buyers=goodbuyers;
    int ptr=0;
    ll best=0;
    int r=-1,l=0;
    auto calc=[&](pll a, pll b){
        return (a.first-b.first)*(a.second-b.second);
    };
    auto overcome=[&](pll a, pll b, int lo){
        int hi=sz(buyers);
        while(lo!=hi){
            int mid=(lo+hi)/2;
            if(mid==sz(buyers)||calc(buyers[mid],a)>=calc(buyers[mid],b))hi=mid;
            else lo=mid+1;
        }
        return lo;
    };
    int ind=0;
    for(auto x:buyers){
        while(ptr!=sz(sellers)&&sellers[ptr].first<x.first){
            while(r>l&&overcome(deq[r],deq[r-1],ind)>=overcome(sellers[ptr],deq[r],ind))r--;
            deq[++r]=sellers[ptr];
            ptr++;
        }
        while(r>l&&calc(x,deq[l+1])>=calc(x,deq[l]))l++;
        if(r>=l)best=max(best,(x.first-deq[l].first)*(x.second-deq[l].second));
        ind++;
    }
    printf("%lli\n",best);
    return 0;
}