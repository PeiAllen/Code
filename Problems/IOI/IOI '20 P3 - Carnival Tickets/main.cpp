#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<int> used[1501][2];
int amlower[1501];
ll find_maximum(int k, vector<vector<int>> x){
    int n=sz(x),m=sz(x[0]);
    ll ans=0;
    priority_queue<pair<ll,int>> q;
    vector<int> order;
    for(int i=0;i<n;i++){
        order.push_back(i);
        for(int j=1;j<=k;j++){
            ans+=x[i][m-j];
            q.push({-x[i][j-1]-x[i][m-k+j-1],i});
        }
    }
    for(int i=0;i<n*k/2;i++){
        auto cur=q.top();
        q.pop();
        ans+=cur.first;
        amlower[cur.second]++;
    }
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=m-k+amlower[i];j--)used[i][0].push_back(j);
        for(int j=0;j<amlower[i];j++)used[i][1].push_back(j);
    }
    vector<vector<int>> ret(n,vector<int>(m,-1));
    for(int i=0;i<k;i++){
        sort(order.begin(),order.end(),[&](auto &lhs, auto &rhs){
            return sz(used[rhs][0])<sz(used[lhs][0]);
        });
        for(int j=0;j<n;j++){
            int loc=(j>=n/2);
            ret[order[j]][used[order[j]][loc].back()]=i;
            used[order[j]][loc].pop_back();
        }
    }
    allocate_tickets(ret);
    return ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    printf("%lli\n",find_maximum(2, {{0, 2, 5},{1, 1, 3}}));
    printf("%lli\n",find_maximum(1, {{5, 9}, {1, 4}, {3, 6}, {2, 7}}));
    return 0;
}