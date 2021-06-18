#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll k;
unordered_map<ll,ll> memo;
vector<ll> arr;
bool solve(ll a){
    if(memo.count(a))return memo[a]!=LLONG_MAX;
    memo[a]=LLONG_MAX;
    for(auto x:arr){
        if((a-x)%k==0){
            if(a-x==0||solve((a-x)/k)){
                memo[a]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q,d,m;
    cin>>k>>q>>d>>m;
    arr.resize(d);
    for(int i=0;i<d;i++)cin>>arr[i];
    ll a;
    while(q--){
        cin>>a;
        bool te=solve(a);
        if(!te)printf("IMPOSSIBLE\n");
        else{
            ll cur=a;
            vector<ll> fin;
            while(1){
                fin.push_back(memo[cur]);
                cur=(cur-memo[cur])/k;
                if(cur==0)break;
            }
            reverse(fin.begin(),fin.end());
            for(int i=0;i<sz(fin);i++)printf("%lli%c",fin[i]," \n"[i==sz(fin)-1]);
        }
    }
    return 0;
}