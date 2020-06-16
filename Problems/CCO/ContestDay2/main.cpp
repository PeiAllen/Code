#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pair<vector<ll>,int> costs[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int a;
    ll c;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        costs[a-1].first.push_back(c);
    }
    ll tot=0;
    bool baf=false;
    for(int i=0;i<m;i++){
        cin>>a>>costs[i].second;
        if(costs[i].second==0)costs[i].first.clear();
        if(a==0)costs[i].first.push_back(0),baf=true;
        sort(costs[i].first.begin(),costs[i].first.end());
        if(sz(costs[i].first)==0){
            while(k--){
                printf("-1\n");
            }
            return 0;
        }
        tot+=costs[i].first[0];
    }
    sort(costs,costs+m,[&](auto lhs, auto rhs){
        for(int i=1;i<min(2,min(sz(lhs.first),sz(rhs.first)));i++){
            if(lhs.first[i]-lhs.first[i-1]!=rhs.first[i]-rhs.first[i-1])return lhs.first[i]-lhs.first[i-1]<rhs.first[i]-rhs.first[i-1];
        }
        return sz(lhs.first)>sz(rhs.first);
    });
    if(baf){
        priority_queue<pair<ll, pair<int,pii>>, vector<pair<ll, pair<int,pii>>>, greater<pair<ll, pair<int,pii>>>> q;
        q.push({0, {0, {0,0}}});
        for (int i = 1; i <= k; i++) {
            if (sz(q) == 0)printf("-1\n");
            else {
                auto cur = q.top();
                q.pop();
                printf("%lli\n", cur.first);
                if (cur.second.second.first + 1 < sz(costs[cur.second.first].first)) {
                    if(cur.second.second.second+1<=costs[cur.second.first].second) {
                        q.push({cur.first + costs[cur.second.first].first[cur.second.second.first + 1],
                                {cur.second.first, {cur.second.second.first + 1, cur.second.second.second + 1}}});
                    }
                    if(cur.second.second.first) {
                        q.push({cur.first + costs[cur.second.first].first[cur.second.second.first + 1] -
                                costs[cur.second.first].first[cur.second.second.first],
                                {cur.second.first, {cur.second.second.first + 1, cur.second.second.second}}});
                    }
                }
                if (cur.second.first + 1 < m&&sz(costs[cur.second.first + 1].first) > 1) {
                    q.push({cur.first + costs[cur.second.first + 1].first[1] - costs[cur.second.first + 1].first[0],
                            {cur.second.first + 1, {1,1}}});
                    if (cur.second.second == pii{1,1} && cur.second.first) {
                        q.push({cur.first + costs[cur.second.first + 1].first[1] - costs[cur.second.first + 1].first[0] -
                                (costs[cur.second.first].first[1] - costs[cur.second.first].first[0]), {cur.second.first + 1, {1,1}}});
                    }
                }
            }
        }
    }
    else {
        priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> q;
        q.push({tot, {0, 0}});
        for (int i = 1; i <= k; i++) {
            if (sz(q) == 0)printf("-1\n");
            else {
                auto cur = q.top();
                q.pop();
                printf("%lli\n", cur.first);
                if (cur.second.second + 1 < sz(costs[cur.second.first].first)) {
                    q.push({cur.first + costs[cur.second.first].first[cur.second.second + 1] -
                            costs[cur.second.first].first[cur.second.second], {cur.second.first, cur.second.second + 1}});
                }
                if (cur.second.first + 1 < m && sz(costs[cur.second.first + 1].first) > 1) {
                    q.push({cur.first + costs[cur.second.first + 1].first[1] - costs[cur.second.first + 1].first[0],
                            {cur.second.first + 1, 1}});
                    if (cur.second.second == 1 && cur.second.first) {
                        q.push({cur.first + costs[cur.second.first + 1].first[1] - costs[cur.second.first + 1].first[0] -
                                (costs[cur.second.first].first[1] - costs[cur.second.first].first[0]), {cur.second.first + 1, 1}});
                    }
                }
            }
        }
    }
    return 0;
}