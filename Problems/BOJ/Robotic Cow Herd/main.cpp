#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<ll> inc[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,a;
    cin>>n>>k;
    ll cost=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        vector<ll> te;
        te.resize(a);
        for(int j=0;j<a;j++)cin>>te[j];
        sort(te.begin(),te.end());
        cost+=te.front();
        for(int j=1;j<a;j++){
            inc[i].push_back(te[j]-te[j-1]);
        }
    }
    sort(inc,inc+n,[&](const auto& lhs, const auto& rhs){
        if(!sz(lhs))return false;
        if(!sz(rhs))return true;
        return lhs[0]<rhs[0];
    });
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<>> q;
    q.push({cost,{0,0}});
    for(int i=0;i<k;i++){
        auto cur=q.top();
        q.pop();
        ans+=cur.first;
        if(cur.second.second<sz(inc[cur.second.first]))q.push({cur.first+inc[cur.second.first][cur.second.second],{cur.second.first,cur.second.second+1}});
        if(cur.second.first+1<n&&sz(inc[cur.second.first+1])) {
            q.push({cur.first + inc[cur.second.first + 1][0], {cur.second.first + 1, 1}});
            if (cur.second.first != 0 && cur.second.second == 1)q.push({cur.first - inc[cur.second.first][0] + inc[cur.second.first + 1][0], {cur.second.first + 1, 1}});
        }
    }
    printf("%lli\n",ans);
    return 0;
}