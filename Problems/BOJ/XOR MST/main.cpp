#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct trie{
    trie* to[2];
    trie(){
        to[0]=nullptr,to[1]=nullptr;
    }
    void add(ll val, ll bit){
        if(bit==0)return;
        int ch=!!(val&bit);
        if(to[ch]==nullptr)to[ch]=new trie();
        to[ch]->add(val,bit/2);
    }
    ll query(ll val, ll bit){
        if(bit==0)return 0;
        int ch=!!(val&bit);
        if(to[ch])return to[ch]->query(val,bit/2);
        return to[!ch]->query(val,bit/2)+bit;
    }
    void clear(){
        if(to[0])to[0]->clear();
        if(to[1])to[1]->clear();
        delete this;
    }
};
ll ans=0;
void solve(const vector<ll> &arr, ll bit){
    if(bit==0||sz(arr)==0)return;
    vector<ll> left,right;
    for(auto x:arr){
        if(x&bit)right.push_back(x);
        else left.push_back(x);
    }
    if(sz(left)&&sz(right)){
        trie* solver= new trie();
        for(auto x:left)solver->add(x,bit);
        ll cost=LLONG_MAX;
        for(auto x:right)cost=min(cost,solver->query(x,bit));
        ans+=cost;
        solver->clear();
    }
    solve(left,bit/2),solve(right,bit/2);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> vals(n);
    for(int i=0;i<n;i++)cin>>vals[i];
    solve(vals,(ll(1)<<29));
    printf("%lli\n",ans);
    return 0;
}