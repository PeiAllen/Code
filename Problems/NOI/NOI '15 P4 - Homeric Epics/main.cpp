#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first;
#define B second;
template<typename T> int SZ(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    ll a;
    cin>>n>>k;
    priority_queue<pll,vector<pll>,greater<>> q;
    for(int i=0;i<n;i++){
        cin>>a;
        q.push({a,0});
    }
    while(n%(k-1)!=1%(k-1))q.push({0,0}),n++;
    ll ans=0;
    while(SZ(q)>1){
        pll cur={0,0};
        for(int i=0;i<k&&SZ(q);i++){
            cur.first+=q.top().first,cur.second=max(cur.second,q.top().second+1);
            q.pop();
        }
        ans+=cur.first;
        q.push(cur);
    }
    printf("%lli\n%lli\n",ans,q.top().second);
    return 0;
}