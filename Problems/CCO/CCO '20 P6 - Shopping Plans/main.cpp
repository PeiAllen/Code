#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pair<vector<ll>,pii> costs[MAXN];
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
    for(int i=0;i<m;i++){
        cin>>costs[i].second.first>>costs[i].second.second;
        if(costs[i].second.second==0)costs[i].first.clear();
        costs[i].first.push_back(0);
        sort(costs[i].first.begin(),costs[i].first.end());
        if(sz(costs[i].first)-1<costs[i].second.first){
            while(k--){
                printf("-1\n");
            }
            return 0;
        }
        for(int j=1;j<=costs[i].second.first;j++)tot+=costs[i].first[j];
    }
    sort(costs,costs+m,[&](auto lhs, auto rhs){
        return (lhs.second.first+1<sz(lhs.first)?lhs.first[lhs.second.first+1]-lhs.first[lhs.second.first]:LLONG_MAX)<(rhs.second.first+1<sz(rhs.first)?rhs.first[rhs.second.first+1]-rhs.first[rhs.second.first]:LLONG_MAX);
    });
    priority_queue<pair<ll,pair<int,pair<int,pii>>>,vector<pair<ll,pair<int,pair<int,pii>>>>,greater<>> q;
    q.push({tot,{0,{costs[0].second.first,{costs[0].second.first,sz(costs[0].first)}}}});
    for(int i=1;i<=k;i++){
        if(!sz(q))printf("-1\n");
        else{
            auto cur=q.top();
            q.pop();
            printf("%lli\n",cur.first);
            if(cur.second.second.first+1<cur.second.second.second.second){
                q.push({cur.first+costs[cur.second.first].first[cur.second.second.first+1]-costs[cur.second.first].first[cur.second.second.first],{cur.second.first,{cur.second.second.first+1,cur.second.second.second}}});
            }
            if(cur.second.second.first>max(1,cur.second.second.second.first)&&cur.second.second.second.first-1>=costs[cur.second.first].second.first-costs[cur.second.first].second.second+1){
                q.push({cur.first+costs[cur.second.first].first[max(1,cur.second.second.second.first)]-costs[cur.second.first].first[max(0,cur.second.second.second.first-1)],{cur.second.first,{max(1,cur.second.second.second.first),{cur.second.second.second.first-1,cur.second.second.first}}}});
            }
            if(cur.second.first+1<m&&sz(costs[cur.second.first+1].first)>costs[cur.second.first+1].second.first+1){
                q.push({cur.first+costs[cur.second.first+1].first[costs[cur.second.first+1].second.first+1]-costs[cur.second.first+1].first[costs[cur.second.first+1].second.first],{cur.second.first+1,{costs[cur.second.first+1].second.first+1,{costs[cur.second.first+1].second.first,sz(costs[cur.second.first+1].first)}}}});
                if(cur.second.first&&cur.second.second==pair<int,pii>{costs[cur.second.first].second.first+1,{costs[cur.second.first].second.first,sz(costs[cur.second.first].first)}}){
                    q.push({cur.first+costs[cur.second.first+1].first[costs[cur.second.first+1].second.first+1]-costs[cur.second.first+1].first[costs[cur.second.first+1].second.first]-(costs[cur.second.first].first[costs[cur.second.first].second.first+1]-costs[cur.second.first].first[costs[cur.second.first].second.first]),{cur.second.first+1,{costs[cur.second.first+1].second.first+1,{costs[cur.second.first+1].second.first,sz(costs[cur.second.first+1].first)}}}});
                }
            }
        }
    }
    return 0;
}
// move pointer to the right
// switch to next pointer(if curloc !=start..)
/*
6 1 256
1 1
1 2
1 4
1 8
1 16
1 32
2 6
 */
