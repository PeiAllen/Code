#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
mt19937_64 gen;
uniform_int_distribution<ll> rnd(LLONG_MIN,LLONG_MAX);
const int MN=3e5+1;
ll dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    auto seed=time(NULL);
    gen.seed(seed);
    int n;
    cin>>n;
    vector<pll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),[&](const auto &lhs, const auto &rhs){
       return lhs.first+lhs.second<rhs.first+rhs.second;
    });
    priority_queue<ll> q;
    ll sum=0;
    for(auto x:arr){
        if(x.first>=sum){
            sum+=x.second;
            q.push(x.second);
        }
        else{
            if(sum-q.top()<=x.first&&q.top()>x.second){
                sum-=q.top();
                q.pop();
                sum+=x.second;
                q.push(x.second);
            }
        }
    }
    printf("%d\n",sz(q));
    return 0;
}